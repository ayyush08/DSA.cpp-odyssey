// Insert Interval
// Given a 2D array Intervals, where Intervals[i] = [start[i], end[i]] represents the start and end of the ith interval, the array represents non-overlapping intervals sorted in ascending order by start[i].

// Given another array newInterval, where newInterval = [start, end] represents the start and end of another interval, merge newInterval into Intervals such that Intervals remain non-overlapping and sorted in ascending order by start[i].

// Return Intervals after the insertion of newInterval.

// Examples:
// Input : Intervals = [ [1, 3] , [6, 9] ] , newInterval = [2, 5]

// Output : [ [1, 5] , [6, 9] ]

// Explanation : After inserting the newInterval the Intervals array becomes [ [1, 3] , [2, 5] , [6, 9] ].

// So to make them non overlapping we can merge the intervals [1, 3] and [2, 5].

// So the Intervals array is [ [1, 5] , [6, 9] ].

// Input : Intervals = [ [1, 2] , [3, 5] , [6, 7] , [8,10] ] , newInterval = [4, 8]

// Output : [ [1, 2] , [3, 10] ]

// Explanation : The Intervals array after inserting newInterval is [ [1, 2] , [3, 5] , [4, 8] , [6, 7] , [8, 10] ].

// We merge the required intervals to make it non overlapping.

// So final array is [ [1, 2] , [3, 10] ].

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insertNewInterval(vector<vector<int>> &Intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;

        int i = 0;
        while (i < Intervals.size() && Intervals[i][1] < newInterval[0])
        {
            ans.push_back(Intervals[i]);
            i++;
        }
        while (i < Intervals.size() && Intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(Intervals[i][0], newInterval[0]);
            newInterval[1] = max(Intervals[i][1], newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);
        while (i < Intervals.size())
        {
            ans.push_back(Intervals[i]);
            i++;
        }
        return ans;
    }
};