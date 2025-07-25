// Aggressive Cows
// Hard
// Given an array nums of size n, which denotes the positions of stalls, and an integer k, which denotes the number of aggressive cows, assign stalls to k cows such that the minimum distance between any two cows is the maximum possible. Find the maximum possible minimum distance.

// Examples:
// Input: n = 6, k = 4, nums = [0, 3, 4, 7, 10, 9]

// Output: 3

// Explanation: The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions [0, 3, 7, 10]. Here the distances between cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater than 3 in any ways.

// Input : n = 5, k = 2, nums = [4, 2, 1, 3, 6]

// Output: 5

// Explanation: The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions [1, 6].


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlace(vector<int> &nums,int dist,int cows){
        int placedCows=1,lastPlaced = nums[0];
        for(int stall: nums){
            if(stall==lastPlaced) continue;
            if(stall-lastPlaced>=dist){
                placedCows++;
                lastPlaced=stall;
            }
        }
        return placedCows>=cows;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(),nums.end());
        int low=1,high = nums[nums.size()-1]-nums[0];
        
        while(low<=high){
            int mid = (low+high)/2;
            if(canPlace(nums,mid,k)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};


//Intuition: We can use binary search to find the maximum possible minimum distance between cows. The search space is between 1 and the difference between the maximum and minimum positions in the stalls array. For each mid value, we check if it's possible to place k cows such that the minimum distance between any two cows is at least mid, if yes maximize the distance.  
//Time Complexity: O(n log(max-min distance)))

// Space Complexity: O(1)