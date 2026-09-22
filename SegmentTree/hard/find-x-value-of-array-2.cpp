// 3525. Find X Value of Array II

// You are given an array of positive integers nums and a positive integer k. You are also given a 2D array queries, where queries[i] = [indexi, valuei, starti, xi].

// You are allowed to perform an operation once on nums, where you can remove any suffix from nums such that nums remains non-empty.

// The x-value of nums for a given x is defined as the number of ways to perform this operation so that the product of the remaining elements leaves a remainder of x modulo k.

// For each query in queries you need to determine the x-value of nums for xi after performing the following actions:

// Update nums[indexi] to valuei. Only this step persists for the rest of the queries.
// Remove the prefix nums[0..(starti - 1)] (where nums[0..(-1)] will be used to represent the empty prefix).
// Return an array result of size queries.length where result[i] is the answer for the ith query.

// A prefix of an array is a subarray that starts from the beginning of the array and extends to any point within it.

// A suffix of an array is a subarray that starts at any point within the array and extends to the end of the array.

// Note that the prefix and suffix to be chosen for the operation can be empty.

// Note that x-value has a different definition in this version.

// Example 1:

// Input: nums = [1,2,3,4,5], k = 3, queries = [[2,2,0,2],[3,3,3,0],[0,1,0,1]]

// Output: [2,2,2]

// Explanation:

// For query 0, nums becomes [1, 2, 2, 4, 5], and the empty prefix must be removed. The possible operations are:
// Remove the suffix [2, 4, 5]. nums becomes [1, 2].
// Remove the empty suffix. nums becomes [1, 2, 2, 4, 5] with a product 80, which gives remainder 2 when divided by 3.
// For query 1, nums becomes [1, 2, 2, 3, 5], and the prefix [1, 2, 2] must be removed. The possible operations are:
// Remove the empty suffix. nums becomes [3, 5].
// Remove the suffix [5]. nums becomes [3].
// For query 2, nums becomes [1, 2, 2, 3, 5], and the empty prefix must be removed. The possible operations are:
// Remove the suffix [2, 2, 3, 5]. nums becomes [1].
// Remove the suffix [3, 5]. nums becomes [1, 2, 2].
// Example 2:

// Input: nums = [1,2,4,8,16,32], k = 4, queries = [[0,2,0,2],[0,2,0,1]]

// Output: [1,0]

// Explanation:

// For query 0, nums becomes [2, 2, 4, 8, 16, 32]. The only possible operation is:
// Remove the suffix [2, 4, 8, 16, 32].
// For query 1, nums becomes [2, 2, 4, 8, 16, 32]. There is no possible way to perform the operation.
// Example 3:

// Input: nums = [1,1,2,1,1], k = 2, queries = [[2,1,0,1]]

// Output: [5]

// Constraints:

// 1 <= nums[i] <= 109
// 1 <= nums.length <= 105
// 1 <= k <= 5
// 1 <= queries.length <= 2 * 104
// queries[i] == [indexi, valuei, starti, xi]
// 0 <= indexi <= nums.length - 1
// 1 <= valuei <= 109
// 0 <= starti <= nums.length - 1
// 0 <= xi <= k - 1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int cnt[5] = {0};
    int prod = 0;
};
struct SegmentTree
{
    vector<Node> tree;
    int k;
    int n;
    void init(int n, int k)
    {
        tree.assign(4 * n, Node());
        this->n = n;
        this->k = k;
    }
    void build(vector<int> &nums, int i, int l, int r)
    {
        if (l == r)
        {
            handleLeaf(i, nums[l]);
            return;
        }

        int mid = l + (r - l) / 2;
        build(nums, 2 * i + 1, l, mid);
        build(nums, 2 * i + 2, mid + 1, r);

        tree[i] = merge(tree[2 * i + 1], tree[2 * i + 2]);
    }

    Node query(int start, int end, int node, int l, int r)
    {

        if (l >= start && r <= end)
            return tree[node];

        int mid = l + (r - l) / 2;

        if (mid >= end)
            return query(start, end, 2 * node + 1, l, mid);
        if (mid < start)
            return query(start, end, 2 * node + 2, mid + 1, r);

        Node queryLeft = query(start, end, 2 * node + 1, l, mid);
        Node queryRight = query(start, end, 2 * node + 2, mid + 1, r);

        return merge(queryLeft, queryRight);
    }
    void update(int start, int end, int idx, int val, int node)
    {
        if (start == end)
        {
            handleLeaf(node, val);
            return;
        }
        int mid = (start + end) >> 1;
        if (idx <= mid)
        {
            update(start, mid, idx, val, 2 * node + 1);
        }
        else
        {
            update(mid + 1, end, idx, val, 2 * node + 2);
        }
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
    void handleLeaf(int node, int val)
    {
        for (int x = 0; x < k; x++)
            tree[node].cnt[x] = 0;

        int rem = val % k;
        tree[node].cnt[rem] = 1;
        tree[node].prod = rem;
    }
    Node merge(Node &left, Node &right)
    {
        Node merged;
        merged.prod = (left.prod * right.prod) % k;

        for (int x = 0; x < k; x++)
            merged.cnt[x] = left.cnt[x];

        for (int x = 0; x < k; x++)
        {
            int newRem = (left.prod * x) % k;
            merged.cnt[newRem] += right.cnt[x];
        }

        return merged;
    }
};
class Solution
{
public:
    vector<int> resultArray(vector<int> &nums, int k, vector<vector<int>> &queries)
    {
        int n = nums.size();
        SegmentTree segTree;
        segTree.init(n, k);
        //O(n*k)
        segTree.build(nums, 0, 0, n - 1);
        vector<int> result;
        //O(q*k*log(n))
        for (auto &q : queries)
        {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];
            segTree.update(0, n - 1, idx, val, 0);

            Node res = segTree.query(start, n - 1, 0, 0, n - 1);
            result.push_back(res.cnt[x]);
        }

        return result;
    }
};

//Overall time complexity: O((n + q) * k * log(n)), where n is the size of nums, q is the number of queries, and k is the given integer.
//Overall space complexity: O(n * k), where n is the size of nums and k is the given integer.