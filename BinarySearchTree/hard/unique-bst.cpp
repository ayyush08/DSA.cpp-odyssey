// 96. Unique Binary Search Trees
// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

// Example 1:

// Input: n = 3
// Output: 5
// Example 2:

// Input: n = 1
// Output: 1

// Constraints:

// 1 <= n <= 19

#include <bits/stdc++.h>
using namespace std;

// Use Catalan Number - Recursive Formula - C(n) = Σ C(i) * C(n-i-1) for i = 0 to n-1.
// Catalan numbers is a number sequence, which is found useful in a number of combinatorial problems, often involving recursively-defined objects.
// starting from 0, catalan series is like 1,1,2,5,14,42.... which is similar to our problem statement.

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> catalan(n + 1, 0);
        catalan[0] = 1;
        catalan[1] = 1;
        int ans = 0;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                catalan[i] += (catalan[j] * catalan[i - 1 - j]);
            }
        }

        return catalan[n];
    }
};