// 32. Longest Valid Parentheses
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

// Example 1:

// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
// Example 2:

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
// Example 3:

// Input: s = ""
// Output: 0

// Constraints:

// 0 <= s.length <= 3 * 104
// s[i] is '(', or ')'.

#include <bits/stdc++.h>
using namespace std;

// Approach 1 - Two passes - O(n) Time and O(1) Space
// Check from left to right and then from right to left and update max length of valid parentheses

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int open = 0, close = 0;
        int lvp = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                open++;
            else if (s[i] == ')')
                close++;
            if (open == close)
            {
                lvp = max(lvp, open + close);
            }
            if (close > open)
            {
                open = close = 0;
            }
        }
        open = close = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '(')
                open++;
            else if (s[i] == ')')
                close++;
            if (open == close)
            {
                lvp = max(lvp, open + close);
            }
            if (close < open)
            {
                open = close = 0;
            }
        }
        return lvp;
    }
};

// Approach 2 - Using Stack - O(n) Time and O(n) Space
//  We can use stack to store indices of opening brackets and when we encounter a closing bracket, we pop the top of stack and calculate the length of valid parentheses substring. Incase stack is empty after popping, we push the current index of closing bracket to stack to mark the end of valid parentheses substring.

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        stack<int> st;
        int ans = 0;
        st.push(-1);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                st.pop();
                if (st.empty())
                    st.push(i);
                else
                    ans = max(ans, i - st.top());
            }
        }
        return ans;
    }
};