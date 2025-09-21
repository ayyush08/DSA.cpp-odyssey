// Longest Bitonic Subsequence

// Given an array arr of n integers, the task is to find the length of the longest bitonic sequence. A sequence is considered bitonic if it first increases, then decreases. The sequence does not have to be contiguous.

// Examples:
// Input: arr = [5, 1, 4, 2, 3, 6, 8, 7]

// Output: 6

// Explanation: The longest bitonic sequence is [1, 2, 3, 6, 8, 7] with length 6.

// Input: arr = [10, 20, 30, 40, 50, 40, 30, 20]

// Output: 8

// Explanation: The entire array is bitonic, increasing up to 50 and then decreasing.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int LongestBitonicSequence(vector<int> arr)
    {
        int n = arr.size();
        vector<int> frontLis(n, 1);
        vector<int> backLis(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j] && frontLis[i] < frontLis[j] + 1)
                {
                    frontLis[i] = frontLis[j] + 1;
                }
            }
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (arr[i] > arr[j] && backLis[i] < backLis[j] + 1)
                {
                    backLis[i] = backLis[j] + 1;
                }
            }
            ans = max(ans, frontLis[i] + backLis[i] - 1);
        }
        return ans;
    }
};
