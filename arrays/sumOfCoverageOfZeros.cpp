#include <vector>
using namespace std;

int sumCoverageOfZeros(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int totalCoverage = 0;

    // Directions for left, right, up, and down
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    // Traverse the matrix to find all zeros
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 0) {
                // Check the coverage for this zero
                int coverage = 0;
                for (auto& dir : directions) {
                    int ni = i + dir.first;
                    int nj = j + dir.second;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && matrix[ni][nj] == 1) {
                        coverage++;
                    }
                }
                totalCoverage += coverage;
            }
        }
    }

    return totalCoverage;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    int result = sumCoverageOfZeros(matrix);
    cout << "Total coverage of zeros: " << result << endl;

    return 0;
}
