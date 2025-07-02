// Longest Subarray Length
// Problem Description

// Given an integer array A of size N containing 0's and 1's only.
// You need to find the length of the longest subarray having count of 1’s one more than count of 0’s.
// Note: In the subarray count of 1's should be one more than the count of 0's.
// Problem Constraints
// 1 <= N <= 105

// Input Format
// First and only argument is an integer array A of size N.
// Output Format
// Return an integer denoting the longest length of the subarray.

// Example Input
// Input 1
//  A = [0, 1, 1, 0, 0, 1]
// Input 2:
//  A = [1, 0, 0, 1, 0]

// Example Output
// Output 1:
//  5
// Output 2:
//  1

// Example Explanation
// Explanation 1:
//  Subarray of length 5, index 1 to 5 i.e 1, 1, 0, 0, 1. Count of 1 = 3, Count of 0 = 2.
// Explanation 2
//  Subarray of length 1 will be only subarray that follow the above condition.

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A)
{
    int n = A.size(), l = 0;
    unordered_map<int, int> mp;
    int sm = 0, mxlen = 0;
    mp[0] = -1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 1)
            sm += 1;
        else
            sm += (-1);
        if (mp.find(sm - 1) != mp.end())
        {
            if (i - mp[sm - 1] > mxlen)
            {
                mxlen = i - mp[sm - 1];
            }
        }
        if (mp.find(sm) == mp.end())
            mp[sm] = i;
    }
    return mxlen;
}
