// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

// Given an integer n, return the nth ugly number.

// Example 1:

// Input: n = 10
// Output: 12
// Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
// Example 2:

// Input: n = 1
// Output: 1
// Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

#include <bits/stdc++.h>
using namespace std;

#define LL long long
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        priority_queue<LL, vector<LL>, greater<LL>> pq;
        unordered_set<LL> st;
        pq.push(1);
        st.insert(1);
        for (int i = 2; i <= n; i++)
        {
            LL last = pq.top();
            pq.pop();
            if (st.insert(last * 2).second)
                pq.push(last * 2);
            if (st.insert(last * 3).second)
                pq.push(last * 3);
            if (st.insert(last * 5).second)
                pq.push(last * 5);
        }
        return pq.top();
    }
};