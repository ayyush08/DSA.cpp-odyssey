// Cleaning Windows

// 0

// 100
// Easy
// A building has n floors, with the ith floor having windows[i-1] windows to clean. A worker has h hours to clean all windows.

// Return the minimum number of windows he has to clean each hour to finish the job within the deadline. If his speed is k windows/hour and he is on a floor with less than k windows, he will clean those windows and not go to another floor till the hour is complete. If it cannot be completed return -1.

// Examples:
// Input: windows = [5, 7, 1, 8], h = 8.

// Output: 4

// Explanation: For k = 3, time needed = 5/3 + 7/3 + 1/3 + 8/3 = 2 + 3 + 1 + 3 = 9

// for k = 4, time needed = 5/4 + 7/4 + 1/4 + 8/4 = 2 + 2 + 1 + 2 = 7, thus 4 is the minimum speed needed.

// Input: windows = [5, 7, 8, 9, 10], h = 4.

// Output: -1

// Explanation: The minimum time needed is 5.

// Constraints:
// n == number of floors
// 0 <= n <= 105
// 1 <= windows[i] <= 5000
// 1 <= h <= 5 * 105

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canClean(vector<int> &windows, int time, int h)
    {
        int tot = 0;
        for (int w : windows)
        {
            tot += (ceil((double)w / time));
        }
        return tot <= h;
    }
    int cleaningWindows(vector<int> &windows, int h)
    {
        int n = windows.size();
        int ans = -1;
        int low = 1;
        int high = *max_element(windows.begin(), windows.end());
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (canClean(windows, mid, h))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};