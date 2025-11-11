// 474. Ones and Zeroes
// You are given an array of binary strings strs and two integers m and n.
// Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
// A set x is a subset of a set y if all elements of x are also elements of y.

// Example 1:

// Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
// Output: 4
// Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
// Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
// {"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
// Example 2:

// Input: strs = ["10","0","1"], m = 1, n = 1
// Output: 2
// Explanation: The largest subset is {"0", "1"}, so the answer is 2.

// Constraints:

// 1 <= strs.length <= 600
// 1 <= strs[i].length <= 100
// strs[i] consists only of digits '0' and '1'.
// 1 <= m, n <= 100

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[601][101][101];
    int func(vector<pair<int, int>> &count, int m, int n, int i)
    {
        if (i < 0 || (m == 0 && n == 0))
            return 0;
        if (dp[i][m][n] != -1)
            return dp[i][m][n];

        int take = 0;
        if (count[i].first <= m && count[i].second <= n)
        {
            take = 1 + func(count, m - count[i].first, n - count[i].second, i - 1);
        }
        int notTake = func(count, m, n, i - 1);

        return dp[i][m][n] = max(take, notTake);
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int len = strs.size();
        vector<pair<int, int>> count(len);
        int i = 0;
        for (string str : strs)
        {
            int countOnes = 0;
            int countZeros = 0;

            for (char ch : str)
            {
                if (ch == '1')
                    countOnes++;
                else
                    countZeros++;
            }
            count[i++] = {countZeros, countOnes};
        }
        memset(dp, -1, sizeof(dp));
        return func(count, m, n, len - 1);
    }
};