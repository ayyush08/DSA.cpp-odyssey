// https://www.interviewbit.com/problems/word-break/

#include <bits/stdc++.h>
using namespace std;

int fun(int i, vector<int> &dp, string &A, vector<string> &B, unordered_set<string> &dict)
{
    if (dp[i] != -1)
        return dp[i];
    for (int j = i; j < A.size(); j++)
    {
        // if(B.cound(s[i...j] && fun(j+1))) then return true;
        // b.substr(i,j-i+1)
        string s = A.substr(i, j - i + 1);
        if (dict.count(s) && fun(j + 1, dp, A, B, dict))
            return dp[i] = 1;
    }
    return dp[i] = 0;
}

int wordBreak(string A, vector<string> &B)
{
    int n = A.size();
    unordered_set<string> dict(B.begin(), B.end());
    vector<int> dp(n + 1, -1);
    dp[n] = 1;
    return fun(0, dp, A, B, dict);
    // dp[i] = if its possible to make A[i...n-1] using word from B;
}
