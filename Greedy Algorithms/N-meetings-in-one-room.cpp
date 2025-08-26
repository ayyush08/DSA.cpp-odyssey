// N meetings in one room
// Given one meeting room and N meetings represented by two arrays, start and end, where start[i] represents the start time of the ith meeting and end[i] represents the end time of the ith meeting, determine the maximum number of meetings that can be accommodated in the meeting room if only one meeting can be held at a time.

// Examples:
// Input : Start = [1, 3, 0, 5, 8, 5] , End = [2, 4, 6, 7, 9, 9]

// Output : 4

// Explanation : The meetings that can be accommodated in meeting room are (1,2) , (3,4) , (5,7) , (8,9).

// Input : Start = [10, 12, 20] , End = [20, 25, 30]

// Output : 1

// Explanation : Given the start and end time, only one meeting can be held in meeting room.

// Input : Start = [1, 4, 6, 9] , End = [2, 5, 7, 12]

// Output:
// 4
// Constraints:
// 1 <= N <= 105
// 0 <= start[i] < end[i] <= 105

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool compare(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second < b.second;
    }
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        int n = start.size();
        vector<pair<int, int>> meetings;

        for (int i = 0; i < n; i++)
        {
            meetings.push_back({start[i], end[i]});
        }

        sort(meetings.begin(), meetings.end(), compare);

        int lastMeetingTime = meetings[0].second;
        int cnt = 1;

        for (auto meeting : meetings)
        {
            if (meeting.first > lastMeetingTime)
            {
                lastMeetingTime = meeting.second;
                cnt++;
            }
        }
        return cnt;
    }
};