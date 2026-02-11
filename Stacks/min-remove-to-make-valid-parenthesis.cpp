// 1249. Minimum Remove to Make Valid Parentheses
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s of '(' , ')' and lowercase English characters.

// Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

// Formally, a parentheses string is valid if and only if:

// It is the empty string, contains only lowercase characters, or
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.

// Example 1:

// Input: s = "lee(t(c)o)de)"
// Output: "lee(t(c)o)de"
// Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
// Example 2:

// Input: s = "a)b(c)d"
// Output: "ab(c)d"
// Example 3:

// Input: s = "))(("
// Output: ""
// Explanation: An empty string is also valid.

// Constraints:

// 1 <= s.length <= 105
// s[i] is either '(' , ')', or lowercase English letter.

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Two passes - O(n) Time and O(n) Space
//  First pass to remove invalid ')' and second pass to remove invalid '('

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int n = s.size();
        string pre;
        int open = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                open++;
                pre.push_back(c);
            }
            else if (c == ')')
            {
                if (open)
                {
                    open--;
                    pre.push_back(c);
                }
            }
            else
                pre.push_back(c);
        }
        string ans;
        int close = 0;
        for (int i = pre.size() - 1; i >= 0; i--)
        {
            if (pre[i] == ')')
            {
                ans.push_back(pre[i]);
                close++;
            }
            else if (pre[i] == '(')
            {
                if (close)
                {
                    close--;
                    ans.push_back(pre[i]);
                }
            }
            else
                ans.push_back(pre[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Approach 2: Single pass using stack (2nd pass to build answer) - O(n) Time and O(n) Space

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int n = s.size();
        stack<int> st;
        vector<bool> toRemove(n, false);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')')
            {
                if (st.empty())
                    toRemove[i] = true;
                else
                    st.pop();
            }
        }
        while (st.size())
        {
            toRemove[st.top()] = true;
            st.pop();
        }

        string ans;
        for (int i = 0; i < n; i++)
        {
            if (!toRemove[i])
                ans.push_back(s[i]);
        }
        return ans;
    }
};