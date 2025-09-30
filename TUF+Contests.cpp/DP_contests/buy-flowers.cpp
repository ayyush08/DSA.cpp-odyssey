// Buy Flowers

// 0

// 100
// Easy
// There is a huge garden in the city. The Garden contains n numbers of flowers. James has arrived in that city to buy exactly k flowers. He then went to the owner of this garden to discuss the prices of flowers. The owner of the garden provides James with an array ‘cost’ of n numbers which denotes the prices of the flower, the price of ith flower is cost[i].

// Since today is the Birthday of Garden Owner , so he has provides a discount which is given by 2D array ‘discount’, where 1st column represents x and second column represent y. It represents that on buying any x flowers from the n flowers, the yth cheapest flower from that x flowers is free.

// Let's say we have flowers with cost [1, 1, 3, 4] then for x=3 and y=2, if we pick any three flowers say [1, 3, 4], then second cheapest flower that is flower with cost 3 is free and you have to pay only first and third flower i.e. 1+4=5.

// Also other way is, if you pick [1, 1, 3] then the second cheapest flower that is flower with cost '1' will be free and you will pay only for the cost of first and third flower i.e. 1+3=4.

// Since James has other plans as well, he wants to save money. So he has asked you to buy exactly k flowers with the minimum cost possible.

// Examples:
// Input : n = 5, m = 2, k = 4, cost = [2, 3, 1, 5, 4], discount = [ [2, 1], [3, 2] ]

// Output : 6

// Explanation : First James will buy 2 flowers of cost 1 and 2 and using 1st discount he will get both flowers in just 2 Rs.

// Then James will buy 2 more flowers of cost 3 and 4 and using 1st discount he will get both flowers in just 4 Rs.

// So total cost = 2 + 4 = 6.

// Input : n = 5, m = 2, k = 3, cost = [100, 100, 100, 100, 100], discount = [ [2, 1], [3, 3] ]

// Output : 200

// Explanation : First James will buy 2 flowers of cost 100 and 100 and using 1st discount he will get both flowers in just 100 Rs.

// Then james will buy 3rd flower of cost 100 and now there is no discount on buying 1 flower, so he will get 3rd flower in 100Rs.

// So total cost = 100 + 100 = 6.

// Constraints:
// 1 <= m <= n <= 2*105
// 0 <= k <= min(2000,n)
// 0 <= cost[i] <= 109
// 1 <= y <= x <= n

// REVIST

// Memoization - O(n*k) time and O(k) for dp array +O(k) for auxiliary stack space

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<long long> dp;
    vector<long long> prefix;
    vector<int> cost;
    vector<pair<int, int>> disc;
    int k;

    long long solve(int i)
    {
        if (i == 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        long long ans = LLONG_MAX;
        ans = min(ans, solve(i - 1) + cost[i - 1]);

        for (auto &[x, y] : disc)
        {
            if (x <= i)
            {
                long long sum_x = prefix[i] - prefix[i - x]; //sum of last x flowers
                long long free_cost = cost[i - x + y - 1];     //yth cheapest flower in last x flowers
                ans = min(ans, solve(i - x) + sum_x - free_cost);
            }
        }

        return dp[i] = ans;
    }

public:
    long long int buyFlowers(vector<int> &costInput, vector<vector<int>> &discountInput, int kInput)
    {
        k = kInput;
        cost = costInput;
        sort(cost.begin(), cost.end());

        disc.clear();
        for (auto &d : discountInput)
            disc.push_back({d[0], d[1]});

        prefix.assign(cost.size() + 1, 0);
        for (int i = 0; i < cost.size(); i++)
            prefix[i + 1] = prefix[i] + cost[i]; //prefix sum to get sum in O(1) time

        dp.assign(k + 1, -1);
        return solve(k);
    }
};
