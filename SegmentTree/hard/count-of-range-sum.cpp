// 327. Count of Range Sum
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.

// Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.

// Example 1:

// Input: nums = [-2,5,-1], lower = -2, upper = 2
// Output: 3
// Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.
// Example 2:

// Input: nums = [0], lower = 0, upper = 0
// Output: 1

// Constraints:

// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// -105 <= lower <= upper <= 105
// The answer is guaranteed to fit in a 32-bit integer.

#include <bits/stdc++.h>
using namespace std;

struct SegmentTree
{
    vector<int> tree;

    void init(int n) { tree.assign(4 * n, 0); }
    void update(int start, int end, int idx, int val, int node)
    {
        if (start == end)
        {
            tree[node] += val;
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
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    int query(int left, int right, int ql, int qr, int node)
    {
        if (left > qr || right < ql)
            return 0;

        if (left >= ql && right <= qr)
            return tree[node];

        int mid = (left + right) >> 1;

        return query(left, mid, ql, qr, 2 * node + 1) +
               query(mid + 1, right, ql, qr, 2 * node + 2);
    }
};
class Solution
{
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        SegmentTree segTree;
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        vector<long long> ranks = prefix;
        sort(ranks.begin(), ranks.end());
        ranks.erase(unique(ranks.begin(), ranks.end()), ranks.end());

        segTree.init(ranks.size());
        int ans = 0;

        for (auto sum : prefix)
        {
            auto left = sum - upper;
            auto right = sum - lower;

            int leftRank =
                lower_bound(ranks.begin(), ranks.end(), left) - ranks.begin();
            int rightRank = upper_bound(ranks.begin(), ranks.end(), right) -
                            ranks.begin() - 1;

            ans += segTree.query(0, ranks.size() - 1, leftRank, rightRank, 0);

            int currRank =
                lower_bound(ranks.begin(), ranks.end(), sum) - ranks.begin();
            segTree.update(0, ranks.size() - 1, currRank, 1, 0);
        }
        return ans;
    }
};