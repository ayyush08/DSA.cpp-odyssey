// Number of islands II

// Given n, m denoting the row and column of the 2D matrix, and an array A of size k denoting the number of operations. Matrix elements are 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integers A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many islands are there in the matrix after each operation.

// The answer array will be of size k.

// Examples:
// Input: n = 4, m = 5, k = 4, A = [[1,1],[0,1],[3,3],[3,4]]

// Output: [1, 1, 2, 2]

// Explanation: The following illustration is the representation of the operation:

// Input: n = 4, m = 5, k = 12, A = [[0,0],[0,0],[1,1],[1,0],[0,1],[0,3],[1,3],[0,4], [3,2], [2,2],[1,2], [0,2]]

// Output: [1, 1, 2, 1, 1, 2, 2, 2, 3, 3, 1, 1]

// Explanation: If we follow the process like in example 1, we will get the above result.

// Submit
// Constraints:
//   1 <= n, m <= 1000
//   1 <= k <= 104
//   0 <= A[i][0] < n
//   0 <= A[i][1] < m

#include <bits/stdc++.h>
using namespace std;

// Intuition: Use a DSU to keep track of connected components. For each operation, add the new land and union it with its adjacent lands if they exist. Count the number of unique roots to get the number of islands.

struct DSU
{
    vector<int> parent;
    vector<int> rank;
    void init(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void unionByRank(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
};
class Solution
{
public:
    bool isValid(int r, int c, int m, int n)
    {
        return r >= 0 && r < m && c >= 0 && c < n;
    }
    vector<int> numOfIslands(int m, int n, vector<vector<int>> &A)
    {
        DSU dsu;
        dsu.init(m * n);
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int cnt = 0;
        vector<int> ans;
            vector<int> dir = {-1, 1, 0, 0};
            vector<int> dic = {0, 0, 1, -1};
        for (auto query : A)
        {
            int r = query[0];
            int c = query[1];

            if (visited[r][c])
            {
                ans.push_back(cnt);
                continue;
            }
            visited[r][c] = 1;
            cnt++;
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dir[i];
                int nc = c + dic[i];

                if (isValid(nr, nc, m, n) && visited[nr][nc])
                {
                    int currNode = r * n + c;
                    int adjNode = nr * n + nc;
                    if (dsu.find(currNode) != dsu.find(adjNode))
                    {
                        cnt--;
                        dsu.unionByRank(currNode, adjNode);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

// Time Complexity: O(k * α(n*m)), where k is the number of operations and α is the inverse Ackermann function, which is very slow-growing and for all practical purposes can be considered almost constant.
// Space Complexity:O(k)+O(n*m) for the DSU and visited array,