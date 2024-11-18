#include <iostream>
#include <vector>

using namespace std;

// Function to display the adjacency matrix
void displayMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Function to perform Warshall's Algorithm
void warshallAlgorithm(vector<vector<int>> &graph)
{
    int n = graph.size(); // Number of vertices

    // Update the graph to compute the transitive closure
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
}

int main()
{
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    // Initialize the adjacency matrix
    vector<vector<int>> graph(vertices, vector<int>(vertices, 0));

    cout << "Enter the number of edges: ";
    cin >> edges;

    // Input edges into the adjacency matrix
    cout << "Enter the edges (format: u v for an edge from u to v):" << endl;
    for (int i = 0; i < edges; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1; // Mark edge in the adjacency matrix
    }

    // Display the original adjacency matrix
    cout << "Original Adjacency Matrix:" << endl;
    displayMatrix(graph);

    // Perform Warshall's Algorithm
    warshallAlgorithm(graph);

    // Display the transitive closure
    cout << "Transitive Closure:" << endl;
    displayMatrix(graph);

    return 0;
}
