// Flood Fill Algorithm

// You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill:

// Begin with the starting pixel and change its color to color.
// Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
// Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
// The process stops when there are no more adjacent pixels of the original color to update.
// Return the modified image after performing the flood fill.

// Example 1
// Input: image = [ [1, 1, 1], [1, 1, 0], [1, 0, 1] ], sr = 1, sc = 1, newColor = 2
// Output: [ [2, 2, 2], [2, 2, 0], [2, 0, 1] ]
// Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

// Example 2
// Input: image = [ [0, 1, 0], [1, 1, 0], [0, 0, 1] ], sr = 2, sc = 2, newColor = 3
// Output: [ [0, 1, 0], [1, 1, 0], [0, 0, 3] ]
// Explanation: Starting from the pixel at position (2, 2) (i.e., the blue pixel), we flood fill all adjacent pixels that have the same color as the starting pixel. In this case, only the pixel at position (2, 2) itself is of the same color. So, only that pixel gets colored with the new color, resulting in the updated image.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(int newColor, vector<vector<int>> &image, int row, int col)
    {
        int original = image[row][col];
        image[row][col] = newColor;
        int m = image.size();
        int n = image[0].size();
        vector<int> dir = {-1, 1, 0, 0};
        vector<int> dic = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dir[i];
            int newCol = col + dic[i];
            if (newRow < m && newRow >= 0 && newCol >= 0 &&
                newCol < n && image[newRow][newCol] == original)
            {
                dfs(newColor, image, newRow, newCol);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int m = image.size();
        int n = image[0].size();
        if (image[sr][sc] != color)
            dfs(color, image, sr, sc);
        return image;
    }
};

int main()
{
    vector<vector<int>> image = {{0, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    int sr = 2, sc = 2, newColor = 3;
    Solution obj;
    vector<vector<bool>> visited(3, vector<bool>(3, false));
    obj.floodFill(image, sr, sc, newColor);
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[0].size(); j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}