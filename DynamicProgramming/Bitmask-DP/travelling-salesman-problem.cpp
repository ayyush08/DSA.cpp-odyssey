// Travelling Salesman Problem
// Given a matrix cost of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.

// Examples:

// Input: cost = [[0, 111], [112, 0]]
// Output: 223
// Explanation: We can visit 0->1->0 and cost = 111 + 112.
// Input: cost = [[0, 1000, 5000], [5000, 0, 1000], [1000, 5000, 0]]
// Output: 3000
// Explanation: We can visit 0->1->2->0 and cost = 1000+1000+1000 = 3000

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Large value to represent "infinite" cost (for minimization)
    const int INF = 1e9;

    // DP table: dp[last][mask]
    // last = current city
    // mask = bitmask representing set of visited cities
    vector<vector<int>> dp;

private:
    /**
     * Recursive DP function.
     *
     * @param cost The cost matrix where cost[i][j] is cost from city i to j
     * @param dp Memoization table: dp[last][mask]
     * @param last Current city we are at
     * @param mask Bitmask representing which cities have been visited
     *
     * @return Minimum cost to complete the tour from 'last' with 'mask' visited
     */
    int fun(vector<vector<int>> &cost, vector<vector<int>> &dp, int last, int mask)
    {
        // If we have already computed this state, return it
        if (dp[last][mask] != -1)
            return dp[last][mask];

        int n = cost.size();

        // Base Case:
        // If all cities have been visited (mask has all n bits set)
        if (mask == (1 << n) - 1)
            return cost[last][0]; // Return to starting city (0)

        int ans = INF;

        // Try going to any unvisited city 'i'
        for (int i = 0; i < n; i++)
        {
            // Check if city 'i' is unvisited in 'mask'
            if ((mask & (1 << i)) == 0)
            {
                // Mark city 'i' as visited by setting its bit in mask
                int newMask = mask | (1 << i);

                // Cost = cost to go from 'last' to 'i' + cost of completing the tour from 'i'
                ans = min(ans, cost[last][i] + fun(cost, dp, i, newMask));
            }
        }

        // Store and return the computed minimum cost
        return dp[last][mask] = ans;
    }

public:
    /**
     * Solves the Travelling Salesman Problem.
     *
     * @param cost The cost matrix
     *
     * @return Minimum cost of visiting all cities exactly once and returning to the start
     */
    int tsp(vector<vector<int>> &cost)
    {
        int n = cost.size();

        // Note:
        // There are 2^n possible masks, each representing a subset of visited cities
        // Example for n=3:
        // mask = 5 (binary 101) => cities 0 and 2 are visited
        //
        // dp[last][mask] stores minimum cost to complete the tour
        // - being at city 'last'
        // - having visited the set of cities in 'mask'

        // Use (1 << n) instead of pow(2,n) to avoid precision issues
        dp.assign(n, vector<int>(1 << n, -1));

        // We start from city 0 with only city 0 visited
        return fun(cost, dp, 0, 1);
    }
};
