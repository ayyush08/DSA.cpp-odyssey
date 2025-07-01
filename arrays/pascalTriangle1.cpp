// Pascal's Triangle I
// Given two integers r and c, return the value at the rth row and cth column (1-indexed) in a Pascal's Triangle.

// In Pascal's triangle:

// The first row has one element with a value of 1.
// Each row has one more element in it than its previous row.
// The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.

// Examples:
// Input: r = 4, c = 2

// Output: 3

// Explanation: The Pascal's Triangle is as follows:

// 1

// 1 1

// 1 2 1

// 1 3 3 1

// ....

// Thus, value at row 4 and column 2 = 3

// Input: r = 5, c = 3

// Output: 6

// Explanation: The Pascal's Triangle is as follows:

// 1

// 1 1

// 1 2 1

// 1 3 3 1

// 1 4 6 4 1

// ....

// Thus, value at row 5 and column 3 = 6

#include<bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int nCr(int n, int r) { //ncr of row-1Ccol-1 gives value at exact position
        if (r > n - r) r = n - r;

        if (r == 1) return n;
        int res = 1;
        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }
    int pascalTriangleI(int r, int c) { return nCr(r - 1, c - 1); }
};