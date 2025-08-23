// Count Set Cost
// Given two integers n and k, return the cost of flipping all set bits in n. One flip operation costs k.

// Examples:
// Input: n = 9, k = 10

// Output: 20

// Explanation: Binary representation of 9 = 1001.

// Number of set bits = 2, therefore cost = 2 * 10 = 20.

// Input: n = 8, k = 5

// Output: 5

// Explanation: Binary representation of 8 = 1000.

// Number of set bits = 1, therefore cost = 1 * 5 = 5.

// Constraints:
// 0 <= n < 231
// 0 <= k <= 104﻿

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int setBitCost(int n, int k)
    {
        int setBits = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n & (1 << i))
                setBits++;
        }
        return setBits * k;
    }
};