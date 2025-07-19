// Given a sorted array of nums and an integer x, write a program to find the lower bound of x.

// The lower bound algorithm finds the first and smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

// If no such index is found, return the size of the array.

// Examples:
// Input : nums= [1,2,2,3], x = 2

// Output:1

// Explanation:

// Index 1 is the smallest index such that arr[1] >= x.

// Input : nums= [3,5,8,15,19], x = 9

// Output: 3

// Explanation:

// Index 3 is the smallest index such that arr[3] >= x.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lowerBound(vector<int> &nums, int x)
    {
        int l = 0, r = nums.size();
        int ans = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] >= x)
            {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return ans == -1 ? nums.size() : ans;
    }
};
