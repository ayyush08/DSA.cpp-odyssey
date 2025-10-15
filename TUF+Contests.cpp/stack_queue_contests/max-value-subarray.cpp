// Maximum Value Of A Subarray
// You are given an array of integers nums and an integer k. The value of a subarray is defined as the minimum value within the subarray multiplied by its length. You need to choose a subarray where the index k is included, i.e., there exists a subarray (nums[i], nums[i+1], ..., nums[j]) such that i≤k≤j.

// Return the maximum possible value of any such subarray.

// Examples:
// Input: nums = [1, 3, 5, 2, 8], k = 2

// Output: 8

// Explanation:

// The optimal subarray is from index 1 to index 4(inclusive), where the minimum value is 2.

// The value is calculated as min(3,5,2,8)×4=2×4=8.

// Input: nums = [4, 6, 3, 5, 7, 8], k = 4

// Output: 18

// Explanation:

// The optimal subarray is from index 0 to index 5 (inclusive), where the minimum value is 3. The value is calculated as =3×6=18.

// Constraints:
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104
// 0 <= k < nums.length

#include <bits/stdc++.h>
using namespace std;

// Similar to largest rectangle in histogram just that we need to include k in our subarray

class Solution
{
public:
    void nextSmallerElements(vector<int> &nums, vector<int> &ns)
    {
        int n = nums.size();
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            int temp = nums[i % n];
            while (!st.empty() && nums[st.top()] >= temp)
            {
                st.pop();
            }

            if (st.empty())
                ns[i] = n;
            else
                ns[i] = st.top();
            st.push(i);
        }
    }
    void prevSmallerElements(vector<int> &nums, vector<int> &ps)
    {
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            int temp = nums[i % n];
            while (!st.empty() && nums[st.top()] >= temp)
            {
                st.pop();
            }
            if (st.empty())
                ps[i] = -1;
            else
                ps[i] = st.top();

            st.push(i);
        }
    }

    int maximumValue(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ps(n), ns(n);
        nextSmallerElements(nums, ns);
        prevSmallerElements(nums, ps);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (ps[i] < k && ns[i] > k)
            {
                int area = (ns[i] - ps[i] - 1) * nums[i];
                ans = max(ans, area);
            }
        }
        return ans;
    }
};