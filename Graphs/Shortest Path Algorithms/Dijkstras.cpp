// Dijkstra's algorithm

// Given a weighted, undirected graph of V vertices, numbered from 0 to V-1, and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that edge .

// Given a source node S. Find the shortest distance of all the vertex from the source vertex S. Return a list of integers denoting shortest distance between each node and source vertex S. If a vertex is not reachable from source then its distance will be 109

// Input: V = 2, adj [] = [[[1, 9]], [[0, 9]]], S=0

// Output: [0, 9]

// Explanation: The shortest distance from node 0(source) to node 0 is 0 and the shortest distance from node 0 to node 1 is 6.

// Input: V = 3,adj = [[[1, 1], [2, 6]], [[2, 3], [0, 1]], [[1, 3], [0, 6]]], S=2

// Output: [4, 3, 0]

// Explanation:

// For node 0, the shortest path is 2->1->0 (distance=4)

// For node 1, the shortest path is 2->1 (distance=3)

// What is Dijkstra's algorithm?
// Dijkstra's Algorithm is used in connected graphs (undirected as well as directed) whenever it is required to find out the shortest distance from the source node to every other node.

// Conditions for Dijkstra's Algorithm to work?
// The graph must not have any non-negative edge weights.

// Approach 1 - Using Priority Queue (Min Heap)

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // declaring min heap using priority queue - here first arg is type of data, second arg is container, third arg is comparator

        vector<int> dist(V, 1e9);
        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int weight = pq.top().first;

            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgeWt = it[1];

                if (weight + edgeWt < dist[adjNode])
                {
                    dist[adjNode] = weight + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

// Approach 2 - Using Set
class Solution2
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;

        vector<int> dist(V, 1e9);

        dist[S] = 0;
        st.insert({0, S});

        while (!st.empty())
        {
            int dis = st.begin()->first;
            int node = st.begin()->second;
            st.erase(st.begin());
            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int weight = it[1];

                if (dis + weight < dist[adjNode])
                {
                    dist[adjNode] = dis + weight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

int main()
{
    int V = 3;
    vector<vector<int>> adj[V];

    // Given adjacency list representation
    adj[0] = {{1, 1}, {2, 6}};
    adj[1] = {{2, 3}, {0, 1}};
    adj[2] = {{1, 3}, {0, 6}};

    int S = 2;
    Solution obj;
    Solution2 obj2;
    // vector<int> res = obj.dijkstra(V, adj, S);
    vector<int> res = obj2.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        if (res[i] == 1e9)
            cout << "109 ";
        else
            cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}


// Time complexity: O(ElogV) where E is the number of edges and V is the number of vertices.
// Space complexity: O(V) where V is the number of vertices.


// Why priority queue is used in Dijkstra's Algorithm and why does it not work for negative edge weights?

// Priority Queue is used in Dijkstra's Algorithm because it helps in selecting the node with the minimum distance from the source node. This is done by using a min heap in the priority queue. The node with the minimum distance is always at the top of the min heap. If we would have taken a normal queue, then the time complexity would have been O(V^2) which is not efficient. By using priority queue, we are taking only the minimal paths hence avoid unnecessary iterations and making it a brute force approach.

// Dijkstra's Algorithm does not work for negative edge weights because it is based on the greedy approach. For example, if we have a negative edge weight, then we can always reduce the distance by taking that edge. This will lead to an infinite loop and the algorithm will not terminate. Hence, Dijkstra's Algorithm works only for non-negative edge weights.