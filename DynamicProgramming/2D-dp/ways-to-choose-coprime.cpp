// 3725. Count Ways to Choose Coprime Integers from Rows
// You are given a m x n matrix mat of positive integers.

// Return an integer denoting the number of ways to choose exactly one integer from each row of mat such that the greatest common divisor of all chosen integers is 1.

// Since the answer may be very large, return it modulo 109 + 7.

// Example 1:

// Input: mat = [[1,2],[3,4]]

// Output: 3

// Explanation:

// Chosen integer in the first row	Chosen integer in the second row	Greatest common divisor of chosen integers
// 1	3	1
// 1	4	1
// 2	3	1
// 2	4	2
// 3 of these combinations have a greatest common divisor of 1. Therefore, the answer is 3.

// Example 2:

// Input: mat = [[2,2],[2,2]]

// Output: 0

// Explanation:

// Every combination has a greatest common divisor of 2. Therefore, the answer is 0.

// Constraints:

// 1 <= m == mat.length <= 150
// 1 <= n == mat[i].length <= 150
// 1 <= mat[i][j] <= 150

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    int func(int i, int g, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        int m = mat.size();
        int n = mat[0].size();
        if (i == m)
        {
            return g == 1;
        }
        if (dp[i][g] != -1)
            return dp[i][g];

        long long ans = 0;

        for (int j = 0; j < mat[i].size(); j++)
        {
            int val = mat[i][j];
            if (g)
                val = gcd(val, g);
            ans = (ans + func(i + 1, val, mat, dp)) % mod;
        }
        return dp[i][g] = (int)ans;
    }
    int countCoprime(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        //dp[i][g] = number of ways to choose from row i to m-1 such that gcd of chosen numbers till now is g
        vector<vector<int>> dp(m, vector<int>(150 + 1, -1));
        return func(0, 0, mat, dp);
    }
};

//Time Complexity: O(m * n * log(max(mat[i][j])))
//Space Complexity: O(m * 150) + O(m) for recursion stack