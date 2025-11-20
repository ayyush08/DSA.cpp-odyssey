// 757. Set Intersection Size At Least Two

// Hard

// You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.

// A containing set is an array nums where each interval from intervals has at least two integers in nums.

// For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.
// Return the minimum possible size of a containing set.

// Example 1:

// Input: intervals = [[1,3],[3,7],[8,9]]
// Output: 5
// Explanation: let nums = [2, 3, 4, 8, 9].
// It can be shown that there cannot be any containing array of size 4.
// Example 2:

// Input: intervals = [[1,3],[1,4],[2,5],[3,5]]
// Output: 3
// Explanation: let nums = [2, 3, 4].
// It can be shown that there cannot be any containing array of size 2.
// Example 3:

// Input: intervals = [[1,2],[2,3],[2,4],[4,5]]
// Output: 5
// Explanation: let nums = [1, 2, 3, 4, 5].
// It can be shown that there cannot be any containing array of size 4.

// Constraints:

// 1 <= intervals.length <= 3000
// intervals[i].length == 2
// 0 <= starti < endi <= 108

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        if (a[1] != b[1])
        {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), comp);

        int first = -1;
        int second = -1;

        int ans = 0;
        for (auto interval : intervals)
        {
            int l = interval[0];
            int r = interval[1];

            if (l <= first)
                continue;

            if (l > second)
            {
                first = r - 1;
                second = r;
                ans += 2;
            }
            else
            {
                first = second;
                second = r;
                ans += 1;
            }
        }
        return ans;
    }
};

//Intuition:
// To ensure that each interval has at least two integers in the containing set, we can use a greedy approach.
// We sort the intervals based on their end points. If two intervals have the same end point, we sort them in descending order of their start points.
// This way, we can maximize the overlap between intervals and minimize the size of the containing set.
//Approach:
// 1. Sort the intervals using the custom comparator `comp`.
// 2. Initialize two variables `first` and `second` to keep track of the last two integers added to the containing set.
// 3. Iterate through each interval:
//    - If the start of the interval is less than or equal to `first`, it means both integers are already included, so we continue.
//    - If the start of the interval is greater than `second`, we need to add
//      two new integers to the containing set (the last two integers of the current interval).
//    - If the start of the interval is between `first` and `second`, we need to add one new integer to the containing set (the last integer of the current interval).
// 4. Return the size of the containing set.`

// Time Complexity: O(n log n) due to sorting the intervals.
// Space Complexity: O(1) as we are using only a constant amount of extra space.