// Minimum number of bracket reversals to make an expression balanced

// Given a string s consisting of only opening and closing brackets '(' and ')', find out the minimum number of reversals required to convert the string into a balanced expression.

// If it is not possible to make the brackets balanced, return -1. A reversal means changing '(' to ')' or vice-versa.

// Example 1

// Input: s = ")(())((("

// Output: 3

// Explanation: One way to balance is:

// "((())())". There is no balanced sequence

// that can be formed in lesser reversals.

// Example 2

// Input: s = "(()((()(())(("

// Output: -1

// Explanation: There's no way we can balance

// this sequence of braces.
// Constraints

// 1 <= s.length <= 104

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countRev(string s)
    {
        int n = s.size();
        if (n & 1)
            return -1;
        int open = 0, close = 0;
        for (char c : s)
        {
            if (c == '(')
                open++;
            else
            {
                if (open > 0)
                    open--;
                else
                    close++;
            }
        }
        return (open / 2) + (open % 2) + (close / 2) + (close % 2);
    }
};

// TC: O(n) SC: O(1)