// You are given a string s consisting of uppercase English letters.

// You are allowed to insert at most one uppercase English letter at any position (including the beginning or end) of the string.

// Return the maximum number of "LCT" subsequences that can be formed in the resulting string after at most one insertion.

// Example 1:

// Input: s = "LMCT"

// Output: 2

// Explanation:

// We can insert a "L" at the beginning of the string s to make "LLMCT", which has 2 subsequences, at indices [0, 3, 4] and [1, 3, 4].

// Example 2:

// Input: s = "LCCT"

// Output: 4

// Explanation:

// We can insert a "L" at the beginning of the string s to make "LLCCT", which has 4 subsequences, at indices [0, 2, 4], [0, 3, 4], [1, 2, 4] and [1, 3, 4].

// Example 3:

// Input: s = "L"

// Output: 0

// Explanation:

// Since it is not possible to obtain the subsequence "LCT" by inserting a single letter, the result is 0.

// Idea:Precompute the number of subsequences "LCT"  already present in the string, and then calculate the prefix and suffix counts of "LC" and "CT" respectively. Then, iterate through the string to find the maximum number of subsequences that can be formed by inserting a letter at each position. Final ans is the sum of the original count and the maximum increment found.
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long numOfSubsequences(string s)
    {
        int n = s.size();
        long long lCount = 0, cCount = 0, tCount = 0;
        long long original_ans = 0, ans = 0;
        long long tillC = 0;
        for (char c : s)
        {
            if (c == 'L')
                lCount++;
            else if (c == 'C')
            {
                cCount++;
                tillC += lCount; // tillC is the count of "LC" subsequences till this point
            }
            else if (c == 'T')
            {
                tCount++;
                original_ans += tillC; // original_ans is the count of "LCT" subsequences in the original string
            }
        }

        vector<long long> lcPrefix(n, 0), ctSuffix(n, 0);
        // lc prefix
        long long lCount2 = 0, lcCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
                lCount2++;
            else if (s[i] == 'C')
            {
                lcCount += lCount2;
            }
            lcPrefix[i] = lcCount;
        }

        // ct suffix
        long long tCount2 = 0, ctCount = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'T')
                tCount2++;
            else if (s[i] == 'C')
            {
                ctCount += tCount2;
            }
            ctSuffix[i] = ctCount;
        }

        long long inc = 0; 
        // for L & T
        lCount = 0, cCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
                lCount++;
            else if (s[i] == 'C')
                cCount++;
            else if (s[i] == 'T')
                tCount--;
            // placing C here
            inc = max(inc, lCount * tCount); //Why muliply? Because for each 'L' before this 'C', it can form a new "LCT" with each 'T' after this 'C'. which means we can form lCount * tCount new "LCT" subsequences by placing 'C' here.
            // placing L here (before)
            inc = max(inc, ctSuffix[i]);
            // placing T here (after)
            inc = max(inc, lcPrefix[i]);
        }

        return original_ans + inc;
    }
};