// 3721. Longest Balanced Subarray II
// You are given an integer array nums.

// A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.

// Return the length of the longest balanced subarray.

// Example 1:

// Input: nums = [2,5,4,3]

// Output: 4

// Explanation:

// The longest balanced subarray is [2, 5, 4, 3].
// It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [5, 3]. Thus, the answer is 4.
// Example 2:

// Input: nums = [3,2,2,5,4]

// Output: 5

// Explanation:

// The longest balanced subarray is [3, 2, 2, 5, 4].
// It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [3, 5]. Thus, the answer is 5.
// Example 3:

// Input: nums = [1,2,3,2]

// Output: 3

// Explanation:

// The longest balanced subarray is [2, 3, 2].
// It has 1 distinct even number [2] and 1 distinct odd number [3]. Thus, the answer is 3.

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105

#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force) - TLE
// T.C : O(n^2)
// S.C : O(n)
class Solution
{
public:
    int longestBalanced(vector<int> &nums)
    {
        int n = nums.size();

        // treating even = +1 and odd = -1
        vector<int> cumSum(n, 0);

        int maxL = 0;

        unordered_map<int, int> mp;

        for (int r = 0; r < n; r++)
        {
            int val = (nums[r] % 2 == 0) ? 1 : -1;

            int prev = -1;
            if (mp.count(nums[r]))
            {
                prev = mp[nums[r]];
            }

            if (prev != -1)
            { // we have seen this element in past
                for (int l = 0; l <= prev; l++)
                {
                    cumSum[l] -= val;
                }
            }

            for (int l = 0; l <= r; l++)
            {
                cumSum[l] += val;
            }

            for (int l = 0; l <= r; l++)
            {
                if (cumSum[l] == 0)
                {
                    maxL = max(maxL, r - l + 1);
                    break;
                }
            }

            mp[nums[r]] = r;
        }

        return maxL;
    }
};

// Approach - 2 (Using Segment Tree RMin Max Query
// T.C : O(nlogn)
// S.C : O(n)

struct SegmentTree
{
    vector<int> segMin;
    vector<int> segMax;
    vector<int> lazy;
    void init(int n)
    {
        segMin.assign(4 * n, 0);
        segMax.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }
    void lazyPropogate(int i, int l, int r)
    {
        if (lazy[i] != 0)
        {
            segMin[i] += lazy[i];
            segMax[i] += lazy[i];
            if (l != r)
            {
                lazy[2 * i + 1] += lazy[i];
                lazy[2 * i + 2] += lazy[i];
            }
            lazy[i] = 0;
        }
    }
    void rangeUpdate(int start, int end, int l, int r, int i, int val)
    {
        lazyPropogate(i, l, r);
        if (l > end || r < start)
            return;
        if (l >= start && r <= end)
        {
            lazy[i] += val;
            lazyPropogate(i, l, r);
            return;
        }
        int mid = l + (r - l) / 2;

        rangeUpdate(start, end, l, mid, 2 * i + 1, val);
        rangeUpdate(start, end, mid + 1, r, 2 * i + 2, val);
        segMin[i] = min(segMin[2 * i + 1], segMin[2 * i + 2]);
        segMax[i] = max(segMax[2 * i + 1], segMax[2 * i + 2]);
    }
    int queryLeftMostZero(int i, int l, int r)
    {
        lazyPropogate(i, l, r);
        if (segMin[i] > 0 || segMax[i] < 0)
            return -1;
        if (l == r)
        {
            return l;
        }
        int mid = l + (r - l) / 2;

        int leftTree = queryLeftMostZero(2 * i + 1, l, mid);
        if (leftTree != -1)
            return leftTree;
        return queryLeftMostZero(2 * i + 2, mid + 1, r);
    }
};
class Solution
{
public:
    int longestBalanced(vector<int> &nums)
    {
        int n = nums.size();
        SegmentTree segTree;
        segTree.init(n);

        unordered_map<int, int> seen;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int val = (nums[i] & 1) ? -1 : 1;
            int prev = -1;
            if (seen.count(nums[i]))
                prev = seen[nums[i]];

            if (prev != -1)
                segTree.rangeUpdate(0, prev, 0, n - 1, 0, -val);
            segTree.rangeUpdate(0, i, 0, n - 1, 0, val);

            int j = segTree.queryLeftMostZero(0, 0, n - 1);
            if (j != -1)
                ans = max(ans, i - j + 1);

            seen[nums[i]] = i;
        }
        return ans;
    }
};