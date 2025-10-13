// Trapping Rainwater

// Given an array of non-negative integers, height representing the elevation of ground. Calculate the amount of water that can be trapped after rain.

// Examples:
// Input: height= [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]

// Output: 6

// Explanation: As seen from the diagram 1+1+2+1+1=6 unit of water can be trapped

// Input: height= [4, 2, 0, 3, 2, 5]

// Output: 9

// Expalanation: 2+4+1+2=9 unit of water can be trapped

// Brute Force Approach: O(3n) Time and O(2n) Space

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void prefix(vector<int> &prefixMax, vector<int> &height) // O(n)
    {
        int n = height.size();
        prefixMax[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }
    }
    void suffix(vector<int> &suffixMax, vector<int> &height) // O(n)
    {
        int n = height.size();
        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i > 0; i--)
        {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }
    }
    int trap(vector<int> &height)
    {
        int ans = 0;
        int n = height.size();
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        prefix(prefixMax, height);
        suffix(suffixMax, height);
        for (int i = 0; i < n; i++) // O(n)
        {
            int leftMax = prefixMax[i];
            int rightMax = suffixMax[i];
            if (height[i] < leftMax && height[i] < rightMax)
            {
                ans += (min(leftMax, rightMax) - height[i]);
            }
        }
        return ans;
    }
};

// Optimal - O(n) Time and O(1) Space

class Solution2
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int l = 0, r = n - 1;
        int lmax = 0;
        int rmax = 0;
        int ans = 0;
        while (l < r)
        {
            if (height[l] <= height[r])
            {
                if (lmax > height[l]) // someone on left
                {
                    ans += (lmax - height[l]);
                }
                else
                    lmax = height[l];
                l++;
            }
            else
            {
                if (rmax > height[r])
                {
                    ans += (rmax - height[r]);
                }
                else
                    rmax = height[r];
                r--;
            }
        }
        return ans;
    }
};

// Another Approach - Using Stack - O(n) Time and O(n) Space
class Solution3
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        stack<int> st; // stores indices
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            // while current height is greater than height of top of stack
            while (!st.empty() && height[i] > height[st.top()])
            {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break; // no left boundary

                int distance = i - st.top() - 1; // width between left & right walls
                int bounded_height = min(height[i], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(i);
        }
        return ans;
    }
};
