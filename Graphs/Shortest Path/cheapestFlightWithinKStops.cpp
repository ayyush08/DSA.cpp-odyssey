// Cheapest flight within K stops
// There are n cities and m edges connected by some number of flights. Given an array of flights where flights[i] = [ fromi, toi, pricei] indicates that there is a flight from city fromi to city to with cost price. Given three integers src, dst, and k, and return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

// Examples:
// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output: 700
// Explanation: The optimal path with at most 1 stops from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

// Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
// Output: 200
// Explanation:The optimal path with at most 1 stops from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

// Approach : Dijkstra's Algorithm with a slight modification. We will keep track of the number of stops while traversing the graph. If the number of stops is greater than k, we will not add the node to the queue. Why queue? Because we need to keep track of stops taken therefore the idea of min-heap will not work  here.

#include <bits/stdc++.h>
using namespace std;
#define P pair<int, pair<int, int>>
class Solution
{
public:
    int CheapestFlight(int n, vector<vector<int>> &flights, int src, int dst,
                            int k)
    {
        vector<pair<int, int>> graph[n];

        for (auto it : flights)
        {
            graph[it[0]].push_back({it[1], it[2]});
        }

        queue<P> q;
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        q.push({0, {src, 0}});
        while (!q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int dis = q.front().second.second;
            q.pop();

            if (stops > k)
                continue;

            for (auto it : graph[node])
            {
                int adjNode = it.first;
                int weight = it.second;

                if (dis + weight < dist[adjNode] && stops <= k)
                {
                    dist[adjNode] = dis + weight;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;

        return dist[dst];
    }
};


int main()
{
    int n = 4;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    int src = 0, dst = 3, k = 1;
    Solution obj;
    cout << obj.CheapestFlight(n, flights, src, dst, k) << endl;
    return 0;
}