// 3691. Maximum Total Subarray Value II
// You are given an integer array nums of length n and an integer k.
// You must select exactly k distinct subarrays nums[l..r] of nums. Subarrays may overlap, but the exact same subarray (same l and r) cannot be chosen more than once.
// The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]).
// The total value is the sum of the values of all chosen subarrays.
// Return the maximum possible total value you can achieve.

// Example 1:
// Input: nums = [1,3,2], k = 2
// Output: 4
// Explanation:
// One optimal approach is:
// Choose nums[0..1] = [1, 3]. The maximum is 3 and the minimum is 1, giving a value of 3 - 1 = 2.
// Choose nums[0..2] = [1, 3, 2]. The maximum is still 3 and the minimum is still 1, so the value is also 3 - 1 = 2.
// Adding these gives 2 + 2 = 4.

// Example 2:
// Input: nums = [4,2,5,1], k = 3
// Output: 12
// Explanation:
// One optimal approach is:
// Choose nums[0..3] = [4, 2, 5, 1]. The maximum is 5 and the minimum is 1, giving a value of 5 - 1 = 4.
// Choose nums[1..3] = [2, 5, 1]. The maximum is 5 and the minimum is 1, so the value is also 4.
// Choose nums[2..3] = [5, 1]. The maximum is 5 and the minimum is 1, so the value is again 4.
// Adding these gives 4 + 4 + 4 = 12.

// Constraints:
// 1 <= n == nums.length <= 5 * 10​​​​​​​4
// 0 <= nums[i] <= 109
// 1 <= k <= min(105, n * (n + 1) / 2)

#include <bits/stdc++.h>
using namespace std;

// Approach: Use Top-K elements pattern (use only the top K possible answers with a heap and then push only the next possible answers from those K answers and so on) alongside Segment Tree to get the max and min of a subarray in O(logn) time.


//Time Complexity: O((n+k)log(n))
//Space Complexity: O(n)
 
typedef long long ll;
struct SegmentTree
{
    vector<ll> minTree;
    vector<ll> maxTree;
    void init(int n)
    {
        minTree.assign(4 * n, 0);
        maxTree.assign(4 * n, 0);
    }
    void build(vector<int> &arr, int i, int l, int r)
    {
        if (l == r)
        {
            minTree[i] = arr[l];
            maxTree[i] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(arr, 2 * i + 1, l, mid);
        build(arr, 2 * i + 2, mid + 1, r);

        minTree[i] = min(minTree[2 * i + 1], minTree[2 * i + 2]);
        maxTree[i] = max(maxTree[2 * i + 1], maxTree[2 * i + 2]);
    }
    pair<ll, ll> queryMaxMin(int start, int end, int i, int l, int r, vector<int> &arr)
    {
        if (l > end || r < start)
            return {LLONG_MIN, LLONG_MAX};
        if (l >= start && r <= end)
            return {maxTree[i], minTree[i]};

        int mid = l + (r - l) / 2;
        auto left = queryMaxMin(start, end, 2 * i + 1, l, mid, arr);
        auto right = queryMaxMin(start, end, 2 * i + 2, mid + 1, r, arr);
        ll maxi = max(left.first, right.first);
        ll mini = min(left.second, right.second);

        return {maxi, mini};
    }
};
class Solution
{
public:
    long long maxTotalValue(vector<int> &nums, int k)
    {
        int n = nums.size();
        SegmentTree segTree;
        segTree.init(n);
        segTree.build(nums, 0, 0, n - 1);

        priority_queue<tuple<ll, int, int>> pq;
        for (int l = 0; l < n; l++)
        {
            auto maxmin = segTree.queryMaxMin(l, n - 1, 0, 0, n - 1, nums);
            ll value = maxmin.first - maxmin.second;
            pq.push({value, l, n - 1});
        }

        long long ans = 0;

        while (k--)
        {
            auto [value, l, r] = pq.top();
            pq.pop();
            ans += value;
            if (l > r - 1)
                continue;
            auto maxmin = segTree.queryMaxMin(l, r - 1, 0, 0, n - 1, nums);
            ll nextBest = maxmin.first - maxmin.second;

            pq.push({nextBest, l, r - 1});
        }
        return ans;
    }
};