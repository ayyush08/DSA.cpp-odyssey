// 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.

// Example 1:

// Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
// Output: 2
// Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
// Example 2:

// Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
// Output: 0

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 300
// 0 <= mat[i][j] <= 104
// 0 <= threshold <= 105

#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using 2D Prefix Sum and finding best side square)
// T.C : O(rows * cols * min(rows, cols))
// S.C : O(rows * cols)

class Solution
{
public:
    int sumSquare(int i, int j, int r2, int c2, vector<vector<int>> &prefix)
    {
        int sum = prefix[r2][c2];
        if (i > 0)
            sum -= prefix[i - 1][c2];
        if (j > 0)
            sum -= prefix[r2][j - 1];
        if (i > 0 && j > 0)
            sum += prefix[i - 1][j - 1];
        return sum;
    }
    int maxSideLength(vector<vector<int>> &mat, int threshold)
    {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> prefix(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                prefix[i][j] = mat[i][j] + (i > 0 ? prefix[i - 1][j] : 0) +
                               (j > 0 ? prefix[i][j - 1] : 0) -
                               (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0);
            }
        }

        int best = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                for (int k = best; k < min(rows - i, cols - j); k++)
                {
                    int r2 = i + k;
                    int c2 = j + k;

                    int sum = sumSquare(i, j, r2, c2, prefix);

                    if (sum <= threshold)
                    {
                        best = k + 1;
                    }
                    else
                    {
                        break; // because sum will increase only. Better move to
                               // next cell
                    }
                }
            }
        }
        return best;
    }
};

// Approach-2 (Using 2D Prefix Sum and binarysearch the square side)
// T.C : O(rows * cols * log(min(rows, cols)))
// S.C : O(rows * cols)

class Solution
{
public:
    int sumSquare(int i, int j, int r2, int c2, vector<vector<int>> &prefix)
    {
        int sum = prefix[r2][c2];
        if (i > 0)
            sum -= prefix[i - 1][c2];
        if (j > 0)
            sum -= prefix[r2][j - 1];
        if (i > 0 && j > 0)
            sum += prefix[i - 1][j - 1];
        return sum;
    }
    int maxSideLength(vector<vector<int>> &mat, int threshold)
    {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> prefix(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                prefix[i][j] = mat[i][j] + (i > 0 ? prefix[i - 1][j] : 0) +
                               (j > 0 ? prefix[i][j - 1] : 0) -
                               (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0);
            }
        }

        int best = 0;
        auto check = [&](int side)
        {
            for (int i = 0; i + side - 1 < rows; i++)
            {
                for (int j = 0; j + side - 1 < cols; j++)
                {
                    if (sumSquare(i, j, i + side - 1, j + side - 1, prefix) <=
                        threshold)
                    {
                        return true;
                    }
                }
            }
            return false;
        };

        int low = 1;
        int high = min(rows, cols);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid))
            {
                best = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return best;
    }
};