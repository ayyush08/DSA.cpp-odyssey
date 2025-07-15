// Maximum Points on a Line

// 0

// 100
// Easy
// Given an array of unqiue points nums, where each point is represented as nums[i] = [xi, yi] on a 2D plane, find the maximum number of points that lie on the same line.

// Examples:
// Input: nums = [[0,0], [1,1], [2,2], [3,3]]

// Output: 4

// Explanation: All four points lie on the line with slope 1, so the maximum number of points on the same line is 4.

// Input: nums = [[0,1], [2,3], [4,5], [1,2], [3,4], [2,2]]

// Output: 5

// Explanation: The points [0,1], [1,2], [2,3], [3,4], and [4,5] all lie on the same straight line, so the maximum number is 5.

// Constraints:
// 1 <= nums.length <= 500
// nums[i].length == 2
// -104 <= xi, yi <= 104

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumPointsOnALine(vector<vector<int>> &nums)
    {
        int ans = 0;
        if (nums.size() <= 2)
            return nums.size();
        for (auto point1 : nums)
        {
            unordered_map<double, int> mp;
            int x1 = point1[0], y1 = point1[1];
            for (auto point2 : nums)
            {
                if (point1 == point2)
                    continue;
                double slope;
                int x2 = point2[0], y2 = point2[1];
                if (x2 - x1 == 0)
                    slope = 1e9;
                else
                {
                    slope = (double)(y2 - y1) / (x2 - x1);
                }
                mp[slope]++;
                ans = max(ans, mp[slope]);
            }
        }
        return ans + 1; // including initial point;
    }
};
