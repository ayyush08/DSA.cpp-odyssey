// Palindrome partitioning II

// Given a string s, partition s such that every substring of the partition is a palindrome.Return the minimum cuts needed for a palindrome partitioning of s.

// Examples:
// Input : s = "aab"

// Output : 1

// Explanation : The palindrome partitioning ["aa", "b"] could be produced using 1 cut.

// Input : s = "abaaba"

// Output : 0

// Explanation : The complete string can be considered as a partition as the string itself is palindrome.

// There are other ways to partition the string but it requires more number of cuts.

#include <bits/stdc++.h>
using namespace std;

// Memoization - O(n^2) time and O(n) for dp array +O(n) for auxiliary stack space

class Solution
{
public:
    bool isPalindrome(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int func(int i, int j, vector<int> &dp, string &s)
    {
        if (i == j)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int minPart = INT_MAX;
        for (int partition = i; partition <= j; partition++)
        {
            if (isPalindrome(i, partition, s))
            {
                int cost = 1 + func(partition + 1, j, dp, s);
                minPart = min(minPart, cost);
            }
        }
        return dp[i] = minPart;
    }
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n, -1);
        return func(0, n, dp, s) - 1;
    }
};

// Tabulation - O(n^2) time and O(n) space for dp array

class Solution
{
public:
    bool isPalindrome(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int minPart = INT_MAX;
            for (int partition = i; partition <= n; partition++)
            {
                if (isPalindrome(i, partition, s))
                {
                    int cost = 1 + dp[partition + 1];
                    minPart = min(minPart, cost);
                }
                dp[i] = minPart;
            }
        }
        return dp[0] - 1;
    }
};