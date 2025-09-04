// Number of Substrings Containing All Three Characters

// Given a string s , consisting only of characters 'a' , 'b' , 'c'.Find the number of substrings that contain at least one occurrence of all these characters 'a' , 'b' , 'c'.

// Examples:
// Input : s = "abcba"

// Output : 5

// Explanation : The substrings containing at least one occurrence of the characters 'a' , 'b' , 'c' are "abc" , "abcb" , "abcba" , "bcba" , "cba".

// Input : s = "ccabcc"

// Output : 8

// Explanation : The substrings containing at least one occurrence of the characters 'a' , 'b' , 'c' are "ccab" , "ccabc" , "ccabcc" , "cab" , "cabc" , "cabcc" , "abc" , "abcc".

#include <bits/stdc++.h>
using namespace std;

// Brute : O(n^2) - check each substring

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            int hash[3] = {0};
            for (int j = i; j < n; j++)
            {
                hash[s[j] - 'a'] = 1;
                if (hash[0] + hash[1] + hash[2] == 3)
                    ans++;
            }
        }
        return ans;
    }
};

// Optimal - O(N)
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int ans = 0;
        int n = s.size();
        int lastSeen[3] = {-1, -1, -1};
        for (int i = 0; i < n; i++)
        {
            lastSeen[s[i] - 'a'] = i;
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
            {
                ans += (1 + min({lastSeen[0], lastSeen[1], lastSeen[2]}));
            }
        }
        return ans;
    }
};