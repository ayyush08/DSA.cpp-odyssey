// Sliding Window Maximum

// Given an array of integers arr, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

// Examples:
// Input: arr = [4, 0, -1, 3, 5, 3, 6, 8], k = 3

// Output: [4, 3, 5, 5, 6, 8]

// Explanation:

// Window position          Max

// ------------------------     -----

// [4 0 -1] 3 5 3 6 8      4

//  4 [0 -1 3] 5 3 6 8      3

//  4 0 [-1 3 5] 3 6 8      5

//  4 0 -1 [3 5 3] 6 8      5

//  4 0 -1 3 [5 3 6] 8      6

//  4 0 -1 3 5 [3 6 8]     8

// For each window of size k=3, we find the maximum element in the window and add it to our output array.

// Input: arr = [20, 25], k = 2

// Output: [25]

// Explanation: There’s just one window of size 2 that is possible and the maximum of the two elements is our answer.

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach - O(n-k*k), try each window and find max

// Optimal Approach - O(n) , use deque to store indices of useful elements
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &arr, int k)
    {
        deque<int> dq;
        vector<int> ans;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            while (!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();
            dq.push_back(i);
            if (i >= (k - 1))
                ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};
