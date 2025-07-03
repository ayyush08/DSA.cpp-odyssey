// 1094. Car Pooling
// There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

// You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

// Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

// Example 1:

// Input: trips = [[2,1,5],[3,3,7]], capacity = 4
// Output: false
// Example 2:

// Input: trips = [[2,1,5],[3,3,7]], capacity = 5
// Output: true

// Constraints:

// 1 <= trips.length <= 1000
// trips[i].length == 3
// 1 <= numPassengersi <= 100
// 0 <= fromi < toi <= 1000
// 1 <= capacity <= 105

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        sort(trips.begin(), trips.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; });
        int inside = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (auto &trip : trips)
        {
            int numPassengers = trip[0], from = trip[1], to = trip[2];

            while (!pq.empty() && pq.top().first <= from)
            {
                inside -= pq.top().second;
                pq.pop();
            }

            inside += numPassengers;
            if (inside > capacity)
                return false;

            pq.push({to, numPassengers});
        }
        return true;
    }
};

//1. Sort the trips based on the from location.
//2. Use a priority queue to keep track of the trips that are currently in progress.
//3. For each trip, remove the trips that have ended before the current trip's from location (i.e., the end time is less than or equal to the current trip's from location).
//4. Add the current trip's number of passengers to the inside count.
//5. If at any point the inside count exceeds the capacity, return false.
//6. Finally, if all trips can be accommodated without exceeding the capacity, return true.