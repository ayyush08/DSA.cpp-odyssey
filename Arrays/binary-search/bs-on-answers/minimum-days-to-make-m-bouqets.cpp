// Minimum days to make M bouquets

// Given n roses and an array nums where nums[i] denotes that the 'ith' rose will bloom on the nums[i]th day, only adjacent bloomed roses can be picked to make a bouquet. Exactly k adjacent bloomed roses are required to make a single bouquet. Find the minimum number of days required to make at least m bouquets, each containing k roses. Return -1 if it is not possible.

// Examples:
// Input: n = 8, nums = [7, 7, 7, 7, 13, 11, 12, 7], m = 2, k = 3

// Output: 12

// Explanation: On the 12th the first 4 flowers and the last 3 flowers would have already bloomed. So, we can easily make 2 bouquets, one with the first 3 and another with the last 3 flowers.

// Input: n = 5, nums = [1, 10, 3, 10, 2], m = 3, k = 2

// Output: -1

// Explanation: If we want to make 3 bouquets of 2 flowers each, we need at least 6 flowers. But we are given only 5 flowers, so, we cannot make the bouquets.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canMake(vector<int> &nums, long long val, int &k, int &m)
    {
        long long bouquets = 0, cnt = 0;
        for (int day : nums)
        {
            if (day <= val)
                cnt++;
            else
            {
                bouquets += (cnt / k); //check how many bouquets can be made with the current count of adjacent bloomed roses
                cnt = 0;
            }
        }
        bouquets += (cnt / k); //make remaining bouquets
        return bouquets >= m;
    }
    int roseGarden(int n, vector<int> nums, int k, int m)
    {
        if (m * k > nums.size())
            return -1;
        int maxi = *max_element(nums.begin(), nums.end()); //At minimum, atleast one flower will bloom
        int mini = *min_element(nums.begin(), nums.end()); //At maximum, all flowers will bloom
        int low = mini, high = maxi;
        while (low <= high)
        {
            long long mid = (low + high) / 2;
            if (canMake(nums, mid, k, m))
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};