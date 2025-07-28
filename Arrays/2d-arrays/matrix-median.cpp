// Given a 2D array matrix that is row-wise sorted. The task is to find the median of the given matrix.

// Examples:
// Input: matrix=[ [1, 4, 9], [2, 5, 6], [3, 7, 8] ]

// Output: 5

// Explanation: If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. So, median = 5

// Input: matrix=[ [1, 3, 8], [2, 3, 4], [1, 2, 5] ]

// Output: 3

// Explanation: If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 8. So, median = 3

#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH - store in 1d array,sort then return middle element O(M*N) + O(M*N(log(M*N)))

// Optimal- search between least and max val in matrix and count the number of elements less than or equal to mid value. If count is less than or equal to (m*n)/2, then mid is not median, else it is median. O(log(max)) * O(N(logM))

class Solution
{
public:
    int countLessOrEqual(vector<vector<int>> &matrix, int mid)
    {
        int cnt = 0;
        for (auto row : matrix)
        {
            cnt += (upper_bound(row.begin(), row.end(), mid) - row.begin());
        }
        return cnt;
    }
    int findMedian(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int req = (n * m) / 2;
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m - 1]);
        }

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int count = countLessOrEqual(matrix, mid);
            if (count <= req)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};