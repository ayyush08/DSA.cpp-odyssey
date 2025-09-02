// Longest Repeating Character Replacement
// Given an integer k and a string s, any character in the string can be selected and changed to any other uppercase English character. This operation can be performed up to k times. After completing these steps, return the length of the longest substring that contains the same letter.

// Examples:
// Input : s = "BAABAABBBAAA" , k = 2

// Output : 6

// Explanation : we can change the B present at index 0 , 3 (0 base indexing) to A.

// The new string is "AAAAAABBBAAA".

// The substring "AAAAAA" is the longest substring having same letter with length 6.

// Input : s = "AABABBA" , k = 1

// Output : 4

// Explanation : The underlined characters are changed in the new string obtained.

// The new string is "AABBBBA". The substring "BBBB" is the answer.

// There are other ways to achieve this answer.

#include <bits/stdc++.h>
using namespace std;

// Brute - O(n^2)
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int maxfreq = 0, ans = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int hash[26] = {0};
            for (int j = i; j < s.size(); j++)
            {
                hash[s[j] - 'A']++;

                maxfreq = max(maxfreq, hash[s[j] - 'A']);

                int flips = (j - i + 1) - maxfreq;

                if (flips > k)
                    break;

                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

// Optimal
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int l = 0, r = 0;
        int n = s.size();

        int ans = 0, maxFreq = 0;

        int hash[26] = {0};

        while (r < n)
        {
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);
            if ((r - l + 1) - maxFreq > k)
            {
                hash[s[l] - 'A']--;
                for (int i = 0; i < 26; i++)
                    maxFreq = max(maxFreq, hash[i]);
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};

// Time Complexity:O((N+N) * 26), where N is the size of the array.4