// THIS QUESTION WAS ASKED BY GOOGLE BIG CODE TEST

// Crystal Frequency Tuning

// A research lab has N resonance crystals in a row, each emitting a base frequency.

// A tuning machine can perform the following operation:

// Select a contiguous block of at most L consecutive crystals

// Double every crystal's frequency in that block

// Operations can overlap, and the same crystal can be doubled multiple times.

// Given at most K operations, determine the maximum possible minimum frequency across all crystals.

// Because the block size is capped at L, the placement of operations matters significantly — unlike an unconstrained version, you cannot always cover every crystal equally with K operations.

// Parameters

// N (int) — Number of crystals
// K (int) — Maximum number of operations allowed
// L (int) — Maximum block length per operation
// freq (vector<long long>) — Base frequencies of the crystals

// Return a single long long representing the maximum possible minimum frequency after performing at most K operations.

// Output Format
// Print a single integer — the maximized minimum frequency.

// Constraints
// 2 ≤ N ≤ 10^5
// 1 ≤ K ≤ 600
// 1 ≤ L ≤ N
// 1 ≤ freq[i] ≤ 10^6

// Sample Input
// 6
// 5
// 3
// 3 12 5 8 2 7
// Sample Output
// 12
// Explanation

// We want to maximize the minimum possible frequency across all crystals after at most K = 5 operations, where each operation doubles a contiguous block of at most L = 3 crystals.

// One possible sequence:

// Apply 2 operations on block [0..2]
// Crystals 0,1,2 double twice:

// [3,12,5,8,2,7] → [12,48,20,8,2,7]

// Apply 1 operation on block [3..5]

// [12,48,20,16,4,14]

// Apply 2 operations on block [3..5]

// [12,48,20,64,16,56]

// Now the array is:

// [12,48,20,64,16,56]

// The minimum frequency = 12.

// It can be verified that no arrangement of 5 operations can achieve a minimum frequency of 13 or higher.

#include <bits/stdc++.h>
using namespace std;

bool can(long long x, vector<long long> &a, int n, int k, int L)
{
    vector<long long> diff(n + 1, 0);
    long long cur = 0;
    long long used = 0;

    for (int i = 0; i < n; i++)
    {
        cur += diff[i];

        long long need = 0;
        long long val = a[i];

        while (val < x)
        {
            val *= 2;
            need++;
        }

        if (cur < need)
        {
            long long extra = need - cur;
            used += extra;
            if (used > k)
                return false;

            cur += extra;
            if (i + L < n)
                diff[i + L] -= extra;
        }
    }

    return true;
}

long long crystalTuning(int n, int k, int L, vector<long long> &a)
{
    long long lo = 1, hi = 1e18, ans = 1;

    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;

        if (can(mid, a, n, k, L))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return ans;
}