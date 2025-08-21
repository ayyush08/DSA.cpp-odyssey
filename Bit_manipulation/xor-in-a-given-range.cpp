// XOR of numbers in a given range
// Given two integers L and R. Find the XOR of the elements in the range [L , R].

// Examples:
// Input : L = 3 , R = 5

// Output : 2

// Explanation : answer = (3 ^ 4 ^ 5) = 2.

// Input : L = 1, R = 3

// Output : 0

// Explanation : answer = (1 ^ 2 ^ 3) = 0.

// O(N) - we all know how to do it

// Here is an O(1) solution based on pattern recognition

class Solution
{
public:
    int XORtillN(int n)
    {
        if (n % 4 == 1)
            return 1;
        if (n % 4 == 2)
            return n + 1;
        if (n % 4 == 3)
            return 0;
        return n;
    }
    int findRangeXOR(int l, int r)
    {
        return XORtillN(l - 1) ^ XORtillN(r);
    }
};