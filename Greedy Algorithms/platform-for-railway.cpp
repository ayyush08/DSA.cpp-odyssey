// Minimum number of platforms required for a railway
// Given the arrival and departure times of all trains reaching a particular railway station, determine the minimum number of platforms required so that no train is kept waiting. Consider all trains arrive and depart on the same day.

// In any particular instance, the same platform cannot be used for both the departure of one train and the arrival of another train, necessitating the use of different platforms in such cases.

// Examples:
// Input : Arrival = [0900, 0940, 0950, 1100, 1500, 1800] , Departure = [0910, 1200, 1120, 1130, 1900, 2000]

// Output : 3

// Explanation : The first , second , fifth number train can use the platform 1.

// The third and sixth train can use the platform 2.

// The fourth train will use platform 3.

// So total we need 3 different platforms for the railway station so that no train is kept waiting.

// Input : Arrival = [0900, 1100, 1235] , Departure = [1000, 1200, 1240]

// Output : 1

// Explanation : All the three trains can use the platform 1.

// So we required only 1 platform.

#include <bits/stdc++.h>
using namespace std;

// Brute force: O(N^2) (Can give TLE)
class Solution
{
public:
    int findPlatform(vector<int> &Arrival, vector<int> &Departure)
    {
        int n = Arrival.size();
        int platforms = 1;
        for (int i = 0; i < n; i++)
        {
            int cnt = 1;
            for (int j = 0; j < n; j++) // check all trains
            {
                if (i != j)
                {

                    // Four events:1. CA <= A && CD <= D (CA: CurrentArrival,CD: CurrentDeparture)
                    // The current train arrives before the main train's arrival and departs before or at the main train's departure.
                    // 2. CA <= A && CD > D
                    // The current train arrives before or at the main train's arrival and departs after the main train's departure.
                    // 3. CA <= D && CD <= D
                    // The current train arrives before or at the main train's departure and departs before or at the main train's departure.
                    // 4. CA <= D && CD > D
                    // The current train arrives before or at the main train's departure and departs after the main train's departure.
                    // Instead of Writing all 4 case we can use a logic that
                    // A<=CD && CA<=D this will cover all the 4 case
                    // A<=CD This mean that main train reaches before departure of current train
                    // CA<=D This mean that current train reached before departure of main train
                    if (Arrival[i] >= Arrival[j] && Departure[j] >= Arrival[i])
                    {
                        cnt++;
                    }
                    platforms = max(platforms, cnt);
                }
            }
        }
        return platforms;
    }
};

// Optimal Sol: Sort arrival and departure and count max platforms as the time goes,

class Solution2
{
public:
    int findPlatform(vector<int> &Arrival, vector<int> &Departure)
    {
        int n = Arrival.size();

        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());

        int ans = 1;
        int cnt = 1;
        int i = 0;
        int j = 1;
        while (i < n && j < n)
        {
            if (Departure[i] >= Arrival[j]) //another train is coming before current leaves, use one more platform
            {
                cnt++;
                j++;
            }
            else // current train departs before next train arrives, free up platform
            {
                cnt--;
                i++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};