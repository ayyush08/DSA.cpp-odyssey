// 3699. Number of ZigZag Arrays I
// You are given three integers n, l, and r.

// A ZigZag array of length n is defined as follows:

// Each element lies in the range [l, r].
// No two adjacent elements are equal.
// No three consecutive elements form a strictly increasing or strictly decreasing sequence.
// Return the total number of valid ZigZag arrays.

// Since the answer may be large, return it modulo 109 + 7.

// A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).

// A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).

// Example 1:

// Input: n = 3, l = 4, r = 5

// Output: 2

// Explanation:

// There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5]:

// [4, 5, 4]
// [5, 4, 5]​​​​​​​
// Example 2:

// Input: n = 3, l = 1, r = 3

// Output: 10

// Explanation:

// There are 10 valid ZigZag arrays of length n = 3 using values in the range [1, 3]:

// [1, 2, 1], [1, 3, 1], [1, 3, 2]
// [2, 1, 2], [2, 1, 3], [2, 3, 1], [2, 3, 2]
// [3, 1, 2], [3, 1, 3], [3, 2, 3]
// All arrays meet the ZigZag conditions.

// Constraints:

// 3 <= n <= 2000
// 1 <= l < r <= 2000

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long mod = 1e9 + 7;
    vector<vector<vector<long long>>> dp; // len,val,dir

    vector<long long> prefixDown;
    vector<long long> suffixUp;
    long long zigZagArrays(long long n, long long l, long long r)
    {
        // dp.assign(n + 1,
        //           vector<vector<long long>>(r + 1, vector<long long>(2, -1)));
        vector<vector<long long>> next(r + 1, vector<long long>(2));
        vector<vector<long long>> curr(r + 1, vector<long long>(2));
        prefixDown.assign(r + 1, 0);
        suffixUp.assign(r + 1, 0);
        for (int val = l; val <= r; val++)
        {
            next[val][0] = 1;
            next[val][1] = 1;
        }
        for (int len = n - 1; len >= 2; len--)
        {
            prefixDown[l] = next[l][0];
            for (int val = l + 1; val <= r; val++)
            {
                prefixDown[val] = (prefixDown[val - 1] + next[val][0]) % mod;
            }
            suffixUp[r] = next[r][1];
            for (int val = r - 1; val >= l; val--)
            {
                suffixUp[val] = (suffixUp[val + 1] + next[val][1]) % mod;
            }
            for (int val = l; val <= r; val++)
            {
                // last move was UP => next value must be smaller
                curr[val][1] = (val > l ? prefixDown[val - 1] : 0);
                // last move was DOWN => next value must be larger
                curr[val][0] = (val < r ? suffixUp[val + 1] : 0);
            }
            swap(curr, next);
        }
        long long ans = 0;
        for (int second = l; second <= r; second++)
        {
            long long smaller = second - l;
            long long larger = r - second;

            ans = (ans + smaller * next[second][1] + larger * next[second][0]) % mod;
        }
        return ans;
    }
};

//Memo and Bottom up with 3d dp will give TLE, so we need to optimize it using prefix and suffix sum with space optimization. The idea is to use prefix and suffix sum to calculate the number of valid zigzag arrays for each value in the range [l, r] and then combine the results to get the final answer.

//Time Complexity: O(n * (r - l + 1))
//Space Complexity: O(r - l + 1)