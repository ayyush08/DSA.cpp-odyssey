// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

// Example 1:

// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
// Example 2:

// Input: heights = [2,4]
// Output: 4

// Constraints:

// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104

// APPROACH: Using Stack
//  get all previous and next smaller elements for each element in the array
//  then calculate the area for each element using the formula: area = height * (next smaller - previous smaller - 1)
//  return the maximum area found

#include <bits/stdc++.h>
using namespace std;
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

    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> ps(n), ns(n);
        nextSmallerElements(heights, ns);
        prevSmallerElements(heights, ps);
        int mxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int area = (ns[i] - ps[i] - 1) * heights[i];
            mxArea = max(area, mxArea);
        }
        return mxArea;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n) for storing next and previous smaller elements