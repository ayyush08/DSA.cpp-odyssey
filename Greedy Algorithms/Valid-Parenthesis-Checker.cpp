// Valid Paranthesis Checker
// Hard

// Find the validity of an input string s that only contains the letters '(', ')' and '*'.

// A string entered is legitimate if

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

// Examples:
// Input : s = (*))

// Output : true

// Explanation : The * can be replaced by an opening '(' bracket. The string after replacing the * mark is "(())" and is a valid string.

// Input : s = *(()

// Output : false

// Explanation : The * replaced with any bracket does not form a valid string.

#include <bits/stdc++.h>
using namespace std;

// Brute force: Use recursion to try all possibilities

class Solution
{
public:
    bool checkParenthesis(int i, string s, int cnt)
    {
        if (cnt < 0)
            return false;
        if (i == s.size())
            return cnt == 0;
        if (s[i] == '(')
            return checkParenthesis(i + 1, s, cnt + 1);
        else if (s[i] == ')')
            return checkParenthesis(i + 1, s, cnt - 1);
        return (checkParenthesis(i + 1, s, cnt) ||
                checkParenthesis(i + 1, s, cnt + 1) ||
                checkParenthesis(i + 1, s, cnt - 1));
    }
    bool isValid(string s)
    {
        return checkParenthesis(0, s, 0);
    }
};

// Time Complexity: O(3^n) where n is the length of the string
// Space Complexity: O(n) for the recursion stack

// Better: Since recursion can give TLE we can memoize the solution with DP

// We have 2 states
// index - current index in the string
// count - current balance of parentheses

class Solution2
{
public:
    bool checkParenthesis(int i, string &s, int cnt, vector<vector<int>> &dp)
    {
        if (cnt < 0)
            return false;
        if (i == s.size())
            return cnt == 0;
        if (dp[i][cnt] != -1)
            return dp[i][cnt];
        bool ans = false;
        if (s[i] == '(')
            ans = checkParenthesis(i + 1, s, cnt + 1, dp);
        else if (s[i] == ')')
            ans = checkParenthesis(i + 1, s, cnt - 1, dp);
        else
        {

            ans = ans || (checkParenthesis(i + 1, s, cnt, dp) ||
                          checkParenthesis(i + 1, s, cnt + 1, dp) ||
                          checkParenthesis(i + 1, s, cnt - 1, dp));
        }
        return dp[i][cnt] = ans;
    }
    bool isValid(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return checkParenthesis(0, s, 0, dp);
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

// Optimal: We can use a greedy approach to keep track of the possible range of open parentheses

class Solution3
{
public:
    bool isValid(string s)
    {
        int minOpen = 0, maxOpen = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                minOpen++;//opening
                maxOpen++;//opening
            }
            else if (c == ')')
            {
                minOpen--;//closing
                maxOpen--;//closing
            }
            else if (c == '*')
            {
                minOpen--;//closing
                maxOpen++;//opening
            }
            if (maxOpen < 0) // If maxOpen is negative, we have more closing brackets than opening brackets so not valid
                return false;
            if (minOpen < 0) // Do not let minOpen go negative
                minOpen = 0;
        }

        return minOpen == 0;
    }
};