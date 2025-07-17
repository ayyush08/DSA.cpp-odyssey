// Largest Continuous Sequence Zero Sum
// medium

// Problem Description

//  Given an array A of N integers.

// Find the largest continuous sequence in a array which sums to zero.

// Problem Constraints
// 1 <= N <= 106

//  -107 <= A[i] <= 107

// Example Input
// A = [1,2,-2,4,-4]

// Example Output
// [2,-2,4,-4]

// Example Explanation
// [2,-2,4,-4] is the longest sequence with total sum of zero.

#include <bits/stdc++.h>
using namespace std;

vector<int> lszero(vector<int> &A)
{
    int n = A.size(), l = -1, r = -1;
    unordered_map<int, int> mp;
    mp[0] = -1;
    int sm = 0, mxlen = 0;
    for (int i = 0; i < n; i++)
    {
        sm += A[i];
        if (mp.find(sm) != mp.end())
        {
            if (i - mp[sm] > mxlen)
            {
                mxlen = i - mp[sm];
                l = mp[sm] + 1;
                r = i;
            }
        }
        else
        {
            mp[sm] = i;
        }
    }
    vector<int> ans;
    if (l != -1 && r != -1)
    {

        for (int i = l; i <= r; i++)
        {
            ans.push_back(A[i]);
        }
    }
    return ans;
}
