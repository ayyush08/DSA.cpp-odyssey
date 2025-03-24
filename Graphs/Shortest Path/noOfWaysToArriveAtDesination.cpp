// Number of ways to arrive at destination
// A city consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that one can reach any intersection from any other intersection and that there is at most one road between any two intersections.
// Given an integer n and a 2D integer array ‘roads’ where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. Determine the number of ways to travel from intersection 0 to intersection n - 1 in the shortest amount of time.
// Since the answer may be large, return it modulo 109 + 7.

// Examples:
// Input: n=7, m=10, roads= [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
// Output: 4
// Explanation:
// The four ways to get there in 7 minutes (which is the shortest calculated time) are:
// - 0 6
// - 0 4 6
// - 0 1 2 5 6
// - 0 1 3 5 6

// Input: n=6, m=8, roads= [[0,5,8],[0,2,2],[0,1,1],[1,3,3],[1,2,3],[2,5,6],[3,4,2],[4,5,2]]
// Output: 3
// Explanation:
// The three ways to get there in 8 minutes (which is the shortest calculated time) are:
// - 0 5
// - 0 2 5
// - 0 1 3 4 5

// Approach: Dijkstra's Algorithm with slight modification. We will keep track of the number of ways to reach a node. If the distance of the adjacent node is equal to the distance of the current node + the weight of the edge, then we will add the number of ways to reach the current node to the number of ways to reach the adjacent node. BUT since there could be multiple paths with same number of ways, we will keep it in check too with ways array.

#include <bits/stdc++.h>
using namespace std;

#define P pair<long long, int>
class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<int, int>> graph[n];
        int mod = 1e9 + 7;
        for (auto it : roads)
        {
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> ways(n, 0);
        vector<long long> time(n, LLONG_MAX);
        pq.push({0, 0});
        ways[0] = 1;
        time[0] = 0;

        while (!pq.empty())
        {
            int node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();

            for (auto it : graph[node])
            {
                int adjNode = it.first;
                int takenTime = it.second;

                if (takenTime + dis < time[adjNode])
                {
                    time[adjNode] = takenTime + dis;
                    ways[adjNode] = ways[node];
                    pq.push({time[adjNode], adjNode});
                }
                else if (takenTime + dis == time[adjNode])
                {
                    ways[adjNode] = (ways[node] + ways[adjNode]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};


int main()
{
    int n = 7, m = 10;
    vector<vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    Solution obj;
    cout << obj.countPaths(n, roads) << endl;
    return 0;
}