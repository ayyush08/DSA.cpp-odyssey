// 241. Different Ways to Add Parentheses
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

// The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

// Example 1:

// Input: expression = "2-1-1"
// Output: [0,2]
// Explanation:
// ((2-1)-1) = 0
// (2-(1-1)) = 2
// Example 2:

// Input: expression = "2*3-4*5"
// Output: [-34,-14,-10,-10,10]
// Explanation:
// (2*(3-(4*5))) = -34
// ((2*3)-(4*5)) = -14
// ((2*(3-4))*5) = -10
// (2*((3-4)*5)) = -10
// (((2*3)-4)*5) = 10

// Constraints:

// 1 <= expression.length <= 20
// expression consists of digits and the operator '+', '-', and '*'.
// All the integer values in the input expression are in the range [0, 99].
// The integer values in the input expression do not have a leading '-' or '+' denoting the sign.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eval(int x, int y, char op)
    {
        if (op == '+')
            return x + y;
        else if (op == '-')
            return x - y;
        else if (op == '*')
            return x * y;
        return 0;
    }
    vector<int> solve(string exp)
    {
        vector<int> res;

        for (int i = 0; i < exp.size(); i++)
        {
            if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*')
            {
                vector<int> leftEval = solve(exp.substr(0, i));
                vector<int> rightEval = solve(exp.substr(i + 1));
                for (int x : leftEval)
                {
                    for (int y : rightEval)
                    {
                        res.push_back(eval(x, y, exp[i]));
                    }
                }
            }
        }

        if (res.empty())
            res.push_back(stoi(exp));

        return res;
    }
    vector<int> diffWaysToCompute(string expression)
    {
        return solve(expression);
    }
};