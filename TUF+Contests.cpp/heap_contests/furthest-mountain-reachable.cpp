// Furthest Reachable Mountain
// Given an integer array heights representing the heights of peaks in a mountain range, and two integers energyDrinks and climbingRopes, you are tasked with determining how far you can climb starting from the first peak (index 0).
// You can move from peak i to peak i+1 by using one of the following options:
// If the next peak is lower or equal to the current peak, no resources are needed.
// If the next peak is higher, you can either:
// Use energy drinks equal to the difference in heights (heights[i+1] - heights[i]).
// Use one climbing rope to bypass the height difference.
// The Task is to find the furthest peak (index 0-based) you can reach using the available climbing ropes and energy drinks optimally.

// Examples:
// Input: heights = [10, 15, 5, 12, 8, 20, 30, 35] energyDrinks = 13 climbingRopes = 2
// Output: 6
// Explanation:
// Start at peak 0 (height 10).
// Move to peak 1 (height 15) by using 5 energy drinks (15 - 10 = 5).
// Move to peak 2 (height 5) without using any resources since 15 ≥ 5.
// Move to peak 3 (height 12) without using 7energydrinks (12-5=7).
// Move to peak 4 (height 8) without using any resources since 12 ≥ 8.
// Move to peak 5 (height 20) by using 1 climbing rope.
// Move to peak 6 (height 32) by using 1 climbing rope.
// It is impossible to move beyond peak 6 as there are no more sufficient resources available.

// Input: heights = [7, 9, 12, 3, 15, 19, 18] energyDrinks = 10 climbingRopes = 0
// Output: 3
// Explanation:
// Start at peak 0 (height 7).
// Move to peak 1 (height 9) by using 2 energy drinks (9 - 7 = 2).
// Move to peak 2 (height 12) by using 3 energy drinks (12 - 9 = 3).
// Move to peak 3 (height 3) without using any resources since 12 ≥ 3.
// It is impossible to move beyond peak 3 as there are no more sufficient resources available.

// Constraints:
// heights.length ≤ 10^5
// heights[i] ≤ 10^6
// 0 ≤ energyDrinks ≤ 10^9
// 0 ≤ climbingRopes ≤ heights.length

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int furthestReachableBuilding(vector<int> &heights, int energyDrinks, int climbingRopes)
    {
        int n = heights.size();

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n - 1; i++)
        {
            int diff = heights[i + 1] - heights[i];

            if (diff > 0)
            {
                pq.push(diff);

                if (pq.size() > climbingRopes)
                {
                    energyDrinks -= pq.top();
                    pq.pop();
                    if (energyDrinks < 0)
                        return i;
                }
            }
        }
        return n - 1;
    }
};

//Time Complexity: O(n log k) where n is the number of peaks and k is the number of climbing ropes. This is because we may need to push up to n-1 height differences into the priority queue, and each push operation takes O(log k) time in the worst case when the size of the priority queue exceeds k.
//Space Complexity: O(k) for the priority queue that stores the height differences where k is the number of climbing ropes.