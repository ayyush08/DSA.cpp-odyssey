// Q4. Good Subsequence Queries
// You are given an integer array nums of length n and an integer p.

// A non-empty subsequence of nums is called good if:

// Its length is strictly less than n.
// The greatest common divisor (GCD) of its elements is exactly p.
// You are also given a 2D integer array queries of length q, where each queries[i] = [indi, vali] indicates that you should update nums[indi] to vali.

// After each query, determine whether there exists any good subsequence in the current array.

// Return the number of queries for which a good subsequence exists.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

// The term gcd(a, b) denotes the greatest common divisor of a and b.
//  

// Example 1:

// Input: nums = [4,8,12,16], p = 2, queries = [[0,3],[2,6]]

// Output: 1

// Explanation:

// i	[indi, vali]	Operation	Updated nums	Any good Subsequence
// 0	[0, 3]	Update nums[0] to 3	[3, 8, 12, 16]	No, as no subsequence has GCD exactly p = 2
// 1	[2, 6]	Update nums[2] to 6	[3, 8, 6, 16]	Yes, subsequence [8, 6] has GCD exactly p = 2
// Thus, the answer is 1.

// Example 2:

// Input: nums = [4,5,7,8], p = 3, queries = [[0,6],[1,9],[2,3]]

// Output: 2

// Explanation:

// i	[indi, vali]	Operation	Updated nums	Any good Subsequence
// 0	[0, 6]	Update nums[0] to 6	[6, 5, 7, 8]	No, as no subsequence has GCD exactly p = 3
// 1	[1, 9]	Update nums[1] to 9	[6, 9, 7, 8]	Yes, subsequence [6, 9] has GCD exactly p = 3
// 2	[2, 3]	Update nums[2] to 3	[6, 9, 3, 8]	Yes, subsequence [6, 9, 3] has GCD exactly p = 3
// Thus, the answer is 2.

// Example 3:

// Input: nums = [5,7,9], p = 2, queries = [[1,4],[2,8]]

// Output: 0

// Explanation:

// i	[indi, vali]	Operation	Updated nums	Any good Subsequence
// 0	[1, 4]	Update nums[1] to 4	[5, 4, 9]	No, as no subsequence has GCD exactly p = 2
// 1	[2, 8]	Update nums[2] to 8	[5, 4, 8]	No, as no subsequence has GCD exactly p = 2
// Thus, the answer is 0.

//  

// Constraints:

// 2 <= n == nums.length <= 5 * 10^4
// 1 <= nums[i] <= 5 * 10^4
// 1 <= queries.length <= 5 * 10^4
// queries[i] = [indi, vali]
// 1 <= vali, p <= 5 * 10^4
// 0 <= indi <= n - 1

#include <bits/stdc++.h>
using namespace std;

// Intuition: Store Gcds in segment tree, take count of elements divisible by p then use it and segment tree to check if we can get a subsequence with gcd p

// Time Complexity: O(q*n log n) where q is the number of queries and n is the size of the input array. This is because for each query, we may need to check all elements in the worst case to find a good subsequence, and each check involves a range query on the segment tree which takes O(log n) time.

// Space Complexity: O(n) for the segment tree .

struct SegmentTree
{
    vector<int> tree;
    int gcdToCheck;

    void init(int n, int p)
    {
        tree.assign(4 * n, 0);
        gcdToCheck = p;
    }
    void build(vector<int> &arr, int left, int right, int idx)
    {
        if (left == right)
        {
            if (left < arr.size())
            {
                tree[idx] = (arr[left] % gcdToCheck == 0) ? arr[left] : 0;
            }
            return;
        }
        int mid = (left + right) >> 1;
        build(arr, left, mid, 2 * idx + 1);
        build(arr, mid + 1, right, 2 * idx + 2);
        tree[idx] = gcd(tree[2 * idx + 1], tree[2 * idx + 2]);
    }
    void update(int left, int right, int idx, int pos, int val)
    {
        if (left == right)
        {
            tree[idx] = val % gcdToCheck == 0 ? val : 0;
            return;
        }
        int mid = (left + right) >> 1;
        if (pos <= mid)
        {
            update(left, mid, 2 * idx + 1, pos, val);
        }
        else
        {
            update(mid + 1, right, 2 * idx + 2, pos, val);
        }
        tree[idx] = gcd(tree[2 * idx + 1], tree[2 * idx + 2]);
    }
    int range_query(int left, int right, int idx, int l, int r)
    {
        if (right < l || left > r)
            return 0;
        if (left >= l && right <= r)
            return tree[idx];
        int mid = (left + right) >> 1;
        int left_sum = range_query(left, mid, 2 * idx + 1, l, r);
        int right_sum = range_query(mid + 1, right, 2 * idx + 2, l, r);
        return gcd(left_sum, right_sum);
    }
};
class Solution
{
public:
    int countGoodSubseq(vector<int> &nums, int p, vector<vector<int>> &queries)
    {
        int n = nums.size();
        SegmentTree segTree;
        segTree.init(n, p);
        segTree.build(nums, 0, n - 1, 0);

        int divisibles = 0;
        for (int num : nums)
        {
            if (num % p == 0)
                divisibles++;
        }

        int ans = 0;

        for (auto q : queries)
        {
            int idx = q[0];
            int val = q[1];
            if (nums[idx] % p == 0)
                divisibles--;
            if (val % p == 0)
                divisibles++;
            nums[idx] = val;
            segTree.update(0, n - 1, 0, idx, val);

            int totalGcd = segTree.tree[0];

            if (totalGcd == p)
            {
                if (divisibles < n)
                    ans++;
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        int left = segTree.range_query(0, n - 1, 0, 0, i - 1);
                        int right = segTree.range_query(0, n - 1, 0, i + 1, n - 1);
                        if (gcd(left, right) == p)
                        {
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
