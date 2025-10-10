// 85. Maximal Rectangle
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// Example 1:

// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = [["0"]]
// Output: 0
// Example 3:

// Input: matrix = [["1"]]
// Output: 1

// Similar to Largest Rectangle in Histogram

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
            int temp = nums[i];
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
            int temp = nums[i];
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
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m, 0);
        int maxArea = INT_MIN;
        //Build histogram heights for each consecutive rows and find max area in that histogram
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0; //Falldown to 0 if '0' is encountered otherwise heights[j] will keep increasing and will not give correct area
            }
            maxArea = max(maxArea, largestRectangleArea(heights)); 
        }
        return maxArea;
    }
};