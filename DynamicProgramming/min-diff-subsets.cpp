// Minimum Difference Subsets!
// Given an integer array A containing N integers.
// You need to divide the array A into two subsets S1 and S2 such that the absolute difference between their sums is minimum.

// Find and return this minimum possible absolute difference.

// NOTE:

// Subsets can contain elements from A in any order (not necessary to be contiguous).
// Each element of A should belong to any one subset S1 or S2, not both.
// It may be possible that one subset remains empty.

// Problem Constraints
// 1 <= N <= 100

// 1 <= A[i] <= 100

// Input Format
// First and only argument is an integer array A.

// Output Format
// Return an integer denoting the minimum possible difference among the sums of two subsets.

// Example Input
// Input 1:

//  A = [1, 6, 11, 5]

// Example Output
// Output 1:

//  1

// Example Explanation
// Explanation 1:

//  Subset1 = {1, 5, 6}, sum of Subset1 = 12
//  Subset2 = {11}, sum of Subset2 = 11

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A)
{
    int n = A.size();
    int sum = 0;
    for (int s : A)
        sum += s;
    int x = (sum / 2);
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    dp[0][0] = 1;
    // dp[i][j] -> is it possible to make a subest from first i elements such that its sum exactly j;
    for (int i = 1; i <= x; i++)
        dp[0][x] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= A[i - 1])
            {
                dp[i][j] |= dp[i - 1][j - A[i - 1]];
            }
        }
    }

    int s2 = 0;
    for (int i = x; i >= 0; i--)
    {
        if (dp[n][i])
        {
            s2 = i;
            break;
        }
    }

    return (sum - 2 * s2);
}


//Approach: To minimize the absolute difference between two subsets, we can find the maximum sum of one subset that is less than or equal to half of the total sum. The minimum difference will then be the total sum minus twice this maximum subset sum. Here we use dynamic programming to find the maximum subset sum.