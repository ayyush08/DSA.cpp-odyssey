// Frog Jump

// A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step.

// To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. The frog can jump from any step either one or two steps, provided it exists. Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.

// Examples:
// Input: heights = [2, 1, 3, 5, 4]

// Output: 2

// Explanation: One possible route can be,

// 0th step -> 2nd Step = abs(2 - 3) = 1

// 2nd step -> 4th step = abs(3 - 4) = 1

// Total = 1 + 1 = 2.

// Input: heights = [7, 5, 1, 2, 6]

// Output: 9

// Explanation: One possible route can be,

// 0th step -> 1st Step = abs(7 - 5) = 2

// 1st step -> 3rd step = abs(5 - 2) = 3

// 3rd step -> 4th step = abs(2 - 6) = 4

// Total = 2 + 3 + 4 = 9.

#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution
{
public:
    int func(vector<int> &heights, int i, vector<int> &dp)
    {
        if (i <= 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        //take 1 step
        int oneStep = func(heights, i - 1, dp) + abs(heights[i] - heights[i - 1]);
        //take 2 step
        int twoStep = INT_MAX;
        if (i > 1) // to avoid negative indexing
        {
            twoStep = func(heights, i - 2, dp) + abs(heights[i] - heights[i - 2]);
        }
        return dp[i] = min(oneStep, twoStep);
    }
    int frogJump(vector<int> &heights)
    {
        int n = heights.size();
        //size n because we have to reach the (n-1)th step
        vector<int> dp(n, -1);
        return func(heights, n - 1, dp);
    }
};

// Tabulation

class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int>dp(n,-1);
        dp[0]=0;
        for(int i=1;i<n;i++){
            int oneStep = dp[i-1]+abs(heights[i]-heights[i-1]);
            int twoStep=INT_MAX;
            if(i>1) twoStep = dp[i-2]+abs(heights[i]-heights[i-2]);
            dp[i] = min(oneStep,twoStep);
        }
        return dp[n-1];
    }
};

// Space Optimization

class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        int prev=0;
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int oneStep = prev+abs(heights[i]-heights[i-1]);
            int twoStep=INT_MAX;
            if(i>1) twoStep = prev2+abs(heights[i]-heights[i-2]);
            int curri = min(oneStep,twoStep);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};