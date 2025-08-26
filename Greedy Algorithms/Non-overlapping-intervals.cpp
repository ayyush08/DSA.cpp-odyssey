// Non-overlapping Intervals

// Given an array of N intervals in the form of (start[i], end[i]), where start[i] is the starting point of the interval and end[i] is the ending point of the interval, return the minimum number of intervals that need to be removed to make the remaining intervals non-overlapping.

// Examples:
// Input : Intervals = [ [1, 2] , [2, 3] , [3, 4] ,[1, 3] ]

// Output : 1

// Explanation : You can remove the interval [1, 3] to make the remaining interval non overlapping.

// Input : Intervals = [ [1, 3] , [1, 4] , [3, 5] , [3, 4] , [4, 5] ]

// Output : 2

// Explanation : You can remove the intervals [1, 4] and [3, 5] and the remaining intervals becomes non overlapping.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int MaximumNonOverlappingIntervals(vector<vector<int>> &Intervals)
    {
        sort(Intervals.begin(), Intervals.end(), compare);

        int lastEnd = -1;

        int cnt = 0;

        for (auto interval : Intervals)
        {
            if (interval[0] >= lastEnd)
            {
                cnt++;
                lastEnd = interval[1];
            }
        }

        return Intervals.size() - cnt;
    }
};