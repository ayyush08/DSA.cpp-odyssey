// Minimize Max Distance to Gas Station
// Given a sorted array arr of size n, containing integer positions of n gas stations on the X-axis, and an integer k, place k new gas stations on the X-axis.

// The new gas stations can be placed anywhere on the non-negative side of the X-axis, including non-integer positions.

// Let dist be the maximum distance between adjacent gas stations after adding the k new gas stations.

// Find the minimum value of dist.

// Examples:
// Input: n = 10, arr = [1, 2, 3, 4, 5, 6 ,7, 8, 9, 10], k = 9

// Output: 0.50000

// Explanation:

// One of the possible ways to place 10 gas stations is [1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10].

// Thus the maximum difference between adjacent gas stations is 0.5.

// Hence, the value of dist is 0.5.

// It can be shown that there is no possible way to add 10 gas stations in such a way that the value of dist is lower than this.

// Input : n = 10, arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 1

// Output: 1.00000

// Explanation:

// One of the possible ways to place 1 gas station is [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11].
// New Gas Station is at 11.
// Thus the maximum difference between adjacent gas stations is still 1.
// Hence, the value of dist is 1.
// It can be shown that there is no possible way to add 1 gas station in such a way that the value of dist is lower than this.

// BRUTE APPROACH
// Distribute the k stations greedily one-by-one to the segment that currently has the largest distance between existing (or already placed) stations, so we can reduce the worst-case gap each time.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long double minimiseMaxDistance(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> placed(n - 1, 0);
        long double maxAns = -1;
        for (int station = 1; station <= k; station++)
        {
            double sectionMax = -1;
            int indMax = -1;
            for (int i = 0; i < n - 1; i++)
            {
                long double diff = arr[i + 1] - arr[i];
                long double sectionSize = diff / (placed[i] + 1); // segment with the largest current section size:

                if (sectionSize > sectionMax)
                {
                    sectionMax = sectionSize;
                    indMax = i;
                }
            }
            placed[indMax]++; // place the station in the segment
        }
        // find max dis after placing
        for (int i = 0; i < n - 1; i++)
        {
            long double diff = arr[i + 1] - arr[i];
            long double sectionSize = diff / (placed[i] + 1);
            maxAns = max(maxAns, sectionSize);
        }
        return maxAns;
    }
};

// Time Complexity: O(k*N) + O(N)
// Space Complexity: O(N-1) for placed array

// BETTER APPROACH
//  Max dist finding can be improvised with the help of priority queue(Max Heap) to find the segment with the largest current section size in O(logN) time. Instead of scanning all segments for the max every time (like in brute force), use a max-heap to always get the segment with the largest current section size in O(log n) time.

class Solution2
{
public:
    long double minimiseMaxDistance(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> placed(n - 1, 0);
        priority_queue<pair<long double, int>> pq;
        long double maxAns = -1;
        for (int i = 0; i < n - 1; i++)
            pq.push({(long double)(arr[i + 1] - arr[i]), i});
        for (int station = 1; station <= k; station++)
        {
            auto tp = pq.top();
            pq.pop();
            int secInd = tp.second;
            placed[secInd]++; // place the station in the segment
            long double diff = (long double)(arr[secInd + 1] - arr[secInd]);
            long double secLen = diff / (long double)(placed[secInd] + 1);

            pq.push({secLen, secInd}); // update the segment with the new section size
        }

        return pq.top().first;
    }
};

// Time Complexity: O(NlogN + klogN)
// Space Complexity: O(N-1) for placed array and O(N-1) for priority queue

// OPTIMAL APPROACH
//  Binary Search on the answers
// The intuition is to use binary search on the answer space (a range of decimal values) to find the minimum possible maximum distance between gas stations after placing k new ones. The search space lies between 0 and the maximum distance between any two existing stations, which is sorted and thus suitable for binary search. Since we're working with decimal precision, the traditional integer binary search conditions are adjusted: we stop when high - low ≤ 1e-6, and update bounds using low = mid or high = mid instead of skipping over values to avoid missing precise answers. This approach efficiently narrows down the smallest distance such that at most k additional stations are enough

class Solution3
{
public:
    int requiredGasStations(vector<int> &arr, long double dist)
    {
        int cnt = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            int stationsNeeded = ((arr[i] - arr[i - 1]) / dist);

            if ((arr[i] - arr[i - 1]) == dist * stationsNeeded) //has one extra station due to exact division
            {
                stationsNeeded--;
            }
            cnt += stationsNeeded;
        }
        return cnt;
    }
    long double minimiseMaxDistance(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> placed(n - 1, 0);
        long double low = 0, high = 0;
        for (int i = 1; i < n; i++)
            high = max(high, ((long double)(arr[i] - arr[i - 1]))); //maximum possible distance between gas stations is maximum distance between any two existing stations

        while (high - low > 1e-6) // precision condition for decimal values
        {
            long double mid = (low + high) / 2.0;
            int cnt = requiredGasStations(arr, mid);
            if (cnt > k)
                low = mid; //found more stations than allowed, so increase the distance
            else
                high = mid; //found less or equal stations than allowed, so decrease the distance
        }
        return high; 
    }
};


//Time Complexity: O(N*log(Len)) + O(N), Len is length of answer space
//Space Complexity: O(1) 