// 1106. Parsing A Boolean Expression
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

// 't' that evaluates to true.
// 'f' that evaluates to false.
// '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
// '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
// '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
// Given a string expression that represents a boolean expression, return the evaluation of that expression.

// It is guaranteed that the given expression is valid and follows the given rules.

// Example 1:

// Input: expression = "&(|(f))"
// Output: false
// Explanation:
// First, evaluate |(f) --> f. The expression is now "&(f)".
// Then, evaluate &(f) --> f. The expression is now "f".
// Finally, return false.
// Example 2:

// Input: expression = "|(f,f,f,t)"
// Output: true
// Explanation: The evaluation of (false OR false OR false OR true) is true.
// Example 3:

// Input: expression = "!(&(f,t))"
// Output: true
// Explanation:
// First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
// Then, evaluate !(f) --> NOT false --> true. We return true.

// Constraints:

// 1 <= expression.length <= 2 * 104
// expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char solve(vector<char> vals, char op)
    {
        if (op == '!')
            return vals[0] == 't' ? 'f' : 't';

        if (op == '&')
        {
            for (int v : vals)
            {
                if (v == 'f')
                    return 'f';
            }
            return 't';
        }

        if (op == '|')
        {
            for (int v : vals)
            {
                if (v == 't')
                    return 't';
            }
            return 'f';
        }

        return 't';
    }
    bool parseBoolExpr(string expression)
    {
        stack<char> st;

        for (char c : expression)
        {
            if (c == ',')
                continue;
            if (c == ')')
            {
                vector<char> vals;
                while (st.top() != '(')
                {
                    vals.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                st.push(solve(vals, op));
            }
            else
                st.push(c);
        }

        return st.top() == 't';
    }
};