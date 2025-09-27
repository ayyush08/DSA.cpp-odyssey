// Minimum cost to cut the stick
// Given a wooden stick of length n units. The stick is labelled from 0 to n. Given an integer array cuts where cuts[i] denotes a position you should perform a cut at. Perform the cuts in any order, you can change the order of the cuts as you wish.

// The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When a stick is cut, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Return the minimum total cost of the cuts.

// Examples:
// Input : n = 7, cuts = [1, 3, 4, 5]

// Output : 16

// Explanation : Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

// The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.

// Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).

// Input : n = 7, cuts = [1, 3, 6]

// Output : 14

// Explanation : The optimal order for cutting the stick is [3, 1, 6].

// The cost will be => 7 + 3 + 4 => 14.

#include <bits/stdc++.h>
using namespace std;


//Memoization - O(c^3) time and O(c^2)+O(c) space

class Solution
{
public:
    int func(int i, int j, vector<vector<int>> &dp, vector<int> &cuts)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int res = INT_MAX;
        for (int k = i; k <= j; k++)
        {
            int cut = cuts[j + 1] - cuts[i - 1] + func(k + 1, j, dp, cuts) + func(i, k - 1, dp, cuts);
            res = min(res, cut);
        }
        return dp[i][j] = res;
    }
    int minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return func(1, c, dp, cuts);
    }
};