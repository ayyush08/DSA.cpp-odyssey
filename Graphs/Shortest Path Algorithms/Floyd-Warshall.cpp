// Floyd warshall algorithm
// Given a graph of V vertices numbered from 0 to V-1. Find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n x n. Matrix[i][j] denotes the weight of the edge from i to j. If matrix[i][j]=-1, it means there is no edge from i to j.

// Example 1
// Input: matrix = [[0, 2, -1, -1],[1, 0, 3, -1],[-1, -1, 0, 1],[3, 5, 4, 0]]
// Output: [[0, 2, 5, 6], [1, 0, 3, 4], [4, 6, 0, 1], [3, 5, 4, 0]]
// Explanation: matrix[0][0] is storing the distance from vertex 0 to vertex 0, the distance from vertex 0 to vertex 1 is 2 and so on.

// Example 2
// Input: matrix = [[0,25],[-1,0]]
// Output: [[0, 25],[-1, 0]]
// Explanation: The matrix already contains the shortest distance.


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	void shortestDistance(vector<vector<int>>&matrix) {
		int n = matrix.size();
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(matrix[i][k]==-1 || matrix[k][j]==-1) continue;
					if(matrix[i][j]==-1) matrix[i][j]=matrix[i][k]+matrix[k][j];
					else
					matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
				}
			}
		}
	}
};

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the adjacency matrix:" << endl;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    Solution obj;
    obj.shortestDistance(matrix);
    cout << "The shortest distances between every pair of vertices are:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}