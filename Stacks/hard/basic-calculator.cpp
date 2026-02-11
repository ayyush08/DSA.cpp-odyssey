// 224. Basic Calculator
// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

// Example 1:

// Input: s = "1 + 1"
// Output: 2
// Example 2:

// Input: s = " 2-1 + 2 "
// Output: 3
// Example 3:

// Input: s = "(1+(4+5+2)-3)+(6+8)"
// Output: 23

// Constraints:

// 1 <= s.length <= 3 * 105
// s consists of digits, '+', '-', '(', ')', and ' '.
// s represents a valid expression.
// '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
// '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
// There will be no two consecutive operators in the input.
// Every number and running calculation will fit in a signed 32-bit integer.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        stack<pair<int, int>> st;
        int sum = 0, sign = 1;
        long long num = 0;
        for (char c : s)
        {
            if (isdigit(c))
                num = num * 10 + (c - '0');
            else if (c == '+' || c == '-')
            {
                sum += (sign * num);
                num = 0;
                sign = c == '+' ? 1 : -1;
            }
            else if (c == '(')
            {
                st.push({sum, sign});
                sum = 0;
                sign = 1;
            }
            else if (c == ')')
            {
                sum += (sign * num);
                num = 0;
                int prevSum = st.top().first;
                int prevSign = st.top().second;
                sum = prevSum + prevSign * sum;
                st.pop();
            }
        }
        sum += (sign * num);
        return sum;
    }
};

// Time Complexity: O(n) where n is the length of the string
// Space Complexity: O(n) in worst case when all characters are '(' and we push them into the stack. In average case, it will be O(1) when there are no parentheses.