#include <bits/stdc++.h>
using namespace std;

#define int long long
int mod = 1e9 + 7;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cities, flights;
    cin >> cities >> flights;
    vector<vector<int>> adj(cities + 1);
    for (int i = 0; i < flights; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[v].push_back(u);
    }

    vector<vector<int>> dp(1 << cities, vector<int>(cities, 0));

    dp[1][0] = 1; // Starting at city 0 with only city 0 visited

    for (int mask = 1; mask < (1 << cities); mask++)
    {
        if(!(mask&(1<<0))) continue; // Ensure starting city is included
        if((mask&(1<<(cities-1)) && mask != (1 << cities) - 1)) continue; // Ensure ending city is only included at the end
        for (int city = 0; city < cities; city++)
        {
            if(!(mask & (1 << city))) continue; // City not in the current mask

            int prevMask = mask ^ (1 << city); // Remove current city from mask

            for(auto it: adj[city]){
                if((mask&(1<<it))){ //bit is set in mask (City 'it' has been visited)
                    dp[mask][city] = (dp[mask][city] + dp[prevMask][it]) % mod;
                }
            }
        }
    }

    cout << dp[(1 << cities) - 1][cities - 1] << "\n";

    return 0;
}

//Time Complexity: O(n^2 * 2^n) where n is the number of cities
//Space Complexity: O(n * 2^n) for the dp array

//Intuition:
// We use bitmasking to represent the set of visited cities. Each bit in the mask
// corresponds to whether a city has been visited or not. The DP table dp[mask][city]
// stores the number of ways to reach 'city' having visited the cities represented
// by 'mask'. We iterate through all possible masks and for each city in the mask,
// we update the number of ways to reach that city by considering all possible previous
// cities that could have led to the current city.
// We ensure that the starting city (0) is always included in the mask and the ending
// city (cities-1) is only included at the end to form a valid Hamiltonian path.
// This approach efficiently counts all Hamiltonian paths from city 0 to city (cities-1)
// using the given flights.
