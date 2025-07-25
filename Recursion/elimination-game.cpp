// 390. Elimination Game
// You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order. Apply the following algorithm on arr:

// Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
// Repeat the previous step again, but this time from right to left, remove the rightmost number and every other number from the remaining numbers.
// Keep repeating the steps again, alternating left to right and right to left, until a single number remains.
// Given the integer n, return the last number that remains in arr.

// Example 1:

// Input: n = 9
// Output: 6
// Explanation:
// arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
// arr = [2, 4, 6, 8]
// arr = [2, 6]
// arr = [6]
// Example 2:

// Input: n = 1
// Output: 1

// Constraints:

// 1 <= n <= 109

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eliminate(int n, int l, int r, int d, bool direction)
    {
        if (l == r)
            return l;
        int len = (r - l) / d + 1; // no of elements
        if (len % 2)
        {
            return eliminate(n, l + d, r - d, 2 * d, !direction);
        }
        else
        {
            if (direction)
                return eliminate(n, l + d, r, 2 * d, !direction);
            return eliminate(n, l, r - d, 2 * d, !direction);
        }
    }
    int lastRemaining(int n) { return eliminate(n, 1, n, 1, true); }
};

//currentlenght -> (r - l) / d + 1;
// if current length is odd -> (l + d, r - d, 2 * d, !direction
// if current length is even ->
// if direction is left to right -> (l + d, r, 2 * d, !direction
// if direction is right to left -> (l, r - d, 2 * d, !direction)