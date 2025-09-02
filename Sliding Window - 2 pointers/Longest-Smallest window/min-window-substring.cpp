// Minimum Window Substring
// Given two strings s and t. Find the smallest window substring of s that includes all characters in t (including duplicates) , in the window. Return the empty string "" if no such substring exists.

// Examples:
// Input : s = "ADOBECODEBANC" , t = "ABC"

// Output : "BANC"

// Explanation : The minimum window substring of string s that contains the string t is "BANC".

// Input : s = "a" , t = "a"

// Output : "a"

// Explanation : The complete string is the minimum window

#include <bits/stdc++.h>
using namespace std;

// Brute

class Solution
{
public:
    string minWindow(string s, string t)
    {
        // your code goes here
        int minlen = INT_MAX;
        int startIndex = -1;

        for (int i = 0; i < s.size(); i++)
        {
            int hash[256] = {0};
            for (char c : t)
                hash[c]++;
            int cnt = 0;
            for (int j = i; j < s.size(); j++)
            {
                if (hash[s[j]] > 0)
                    cnt++;
                hash[s[j]]--;

                if (cnt == t.size())
                {
                    if (j - i + 1 < minlen)
                    {
                        minlen = j - i + 1;
                        startIndex = i;
                    }
                    break;
                }
            }
        }
        return (startIndex == -1) ? "" : s.substr(startIndex, minlen);
    }
};

// Optimal

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int l = 0, r = 0;
        int n = s.size();
        int minlen = INT_MAX;
        int startIndex = -1;
        int hash[256] = {0};
        for (char c : t)
            hash[c]++;

        int cnt = 0;

        while (r < n)
        {
            if (hash[s[r]] > 0) // If this character is still needed, increase count of matched chars
                cnt++;
            hash[s[r]]--;

            while (cnt == t.size())
            {
                if ((r - l + 1) < minlen)
                {
                    minlen = r - l + 1;
                    startIndex = l;
                }
                //shrink
                hash[s[l]]++; //restore frequency
                if (hash[s[l]] > 0) //if still needed, reduce match cnt
                    cnt--;
                l++;
            }
            r++;
        }
        return (startIndex == -1) ? "" : s.substr(startIndex, minlen);
    }
};