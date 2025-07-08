// You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

// "1" -> 'A'

// "2" -> 'B'

// ...

// "25" -> 'Y'

// "26" -> 'Z'

// However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").

// For example, "11106" can be decoded into:

// "AAJF" with the grouping (1, 1, 10, 6)
// "KJF" with the grouping (11, 10, 6)
// The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
// Note: there may be strings that are impossible to decode.

// Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.

// The test cases are generated so that the answer fits in a 32-bit integer.

// Example 1:

// Input: s = "12"

// Output: 2

// Explanation:

// "12" could be decoded as "AB" (1 2) or "L" (12).

// Example 2:

// Input: s = "226"

// Output: 3

// Explanation:

// "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

// Example 3:

// Input: s = "06"

// Output: 0

// Explanation:

// "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06"). In this case, the string is not a valid encoding, so return 0.

// Constraints:

// 1 <= s.length <= 100
// s contains only digits and may contain leading zero(s)

#include <bits/stdc++.h>
using namespace std;

// Memoization approach

class Solution
{
public:
    int numbers(string s, vector<int> &dp, int n)
    {
        if (n == s.length())
            return 1;
        if (s[n] == '0')
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int count = 0;
        count = numbers(s, dp, n + 1);
        if (n < s.length() - 1)
        {
            if (s.substr(n, 2) >= "10" && s.substr(n, 2) <= "26")
                count = count + numbers(s, dp, n + 2);
        }
        return dp[n] = count;
    }

    int numDecodings(string s)
    {
        int n = 0;
        vector<int> dp(s.length() + 1, -1);
        return numbers(s, dp, n);
    }
};

// Tabulation approach

class Solution2
{
public:
    int numDecodings(string s)
    {
        int ans = 0;
        vector<int> dp(s.length() + 1, 0);
        dp[s.length()] = 1;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '0')
                continue;
            dp[i] = dp[i + 1];
            if (i + 1 < s.length())
            {
                if (s.substr(i, 2) >= "10" && s.substr(i, 2) <= "26")
                    dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }
};
