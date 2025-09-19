

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> longestIncreasingSubsequence(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> parent(n);

        int last = 0;
        int lis = 0;
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[prev] < arr[i] && dp[i] < dp[prev] + 1)
                {
                    dp[i] = 1 + dp[prev];
                    parent[i] = prev; //reconstruction
                }
            }
            if (dp[i] > lis)
            {
                last = i;
                lis = dp[i];
            }
        }
        vector<int> ans;
        int i = last;
        while (parent[i] != i)
        {
            ans.push_back(arr[i]);
            i = parent[i];
        }
        ans.push_back(arr[i]);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};