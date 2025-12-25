// 2054. Two Best Non-Overlapping Events
// You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

// Return this maximum sum.

// Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

// Example 1:

// Input: events = [[1,3,2],[4,5,2],[2,4,3]]
// Output: 4
// Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
// Example 2:

// Example 1 Diagram
// Input: events = [[1,3,2],[4,5,2],[1,5,5]]
// Output: 5
// Explanation: Choose event 2 for a sum of 5.
// Example 3:

// Input: events = [[1,5,3],[1,5,1],[6,6,5]]
// Output: 8
// Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.

// Constraints:

// 2 <= events.length <= 105
// events[i].length == 3
// 1 <= startTimei <= endTimei <= 109
// 1 <= valuei <= 106

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    int upperBound(vector<vector<int>> &events, int endTime)
    {
        int l = 0;
        int r = n - 1;
        int validInd = n;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (events[mid][0] > endTime)
            {
                validInd = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return validInd;
    }
    int func(vector<vector<int>> &events, vector<vector<int>> &dp, int i, int count)
    {
        if (count == 2 || i >= n)
            return 0;
        if (dp[i][count] != -1)
            return dp[i][count];

        int dontTake = func(events, dp, i + 1, count);
        int nextValidIndex = upperBound(events, events[i][1]);
        int take = events[i][2] + func(events, dp, nextValidIndex, count + 1);

        return dp[i][count] = max(take, dontTake);
    }
    int maxTwoEvents(vector<vector<int>> &events)
    {
        n = events.size();

        vector<vector<int>> dp(n, vector<int>(3, -1));

        sort(events.begin(), events.end());

        int count = 0;

        return func(events, dp, 0, count);
    }
};