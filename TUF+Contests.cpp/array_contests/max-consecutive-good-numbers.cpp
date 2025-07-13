// Maximum Consecutive Good Numbers

// 0

// 100
// Easy
// Given an array of integers nums and an array goodNumbers, return the maximum number of consecutive good numbers in the array.

// Any number present in the goodNumbers array is a good number.

// Examples:
// Input: nums = [1, 2, 3, 5, 4, 5, 1], goodNumbers = [3, 5]

// Output: 2

// Explanation: [1, 2, 3, 5, 4, 5, 1] the underlined numbers are all good numbers and give the maximum length.

// Input: nums = [4, 8, 1, 2, 0, 4, 6], goodNumbers = [1, 4, 2, 6]

// Output: 2

// Explanation: [4, 8, 1, 2, 0, 4, 6] the underlined numbers are all good numbers and give the maximum length.

// Note that the segment with index [6, 7] was also a possible answer.

// Constraints:
// 1 <= nums.length <= 105
// 1 <= goodNumbers.length <= 105
// -104 <= nums[i], goodNumbers[i] <= 104

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxConsecutiveGoodNums(vector<int> &nums, vector<int> &goodNumbers)
    {
        int cnt = 0, mxCount = 0;
        unordered_set<int> st(goodNumbers.begin(), goodNumbers.end()); //Why not use the vector directly? Because we need O(1) average time complexity for lookups, using count() or find() on a vector would be O(n) which led to TLE in the test cases.(O(m*n) (Inefficient) vs O(m + n) (Efficient))
        // Using unordered_set helps to achieve O(1) amortized time complexity for lookups.
        for (int i = 0; i < nums.size(); i++)
        {
            if (st.count(nums[i])) 
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            mxCount = max(mxCount, cnt);
        }
        return mxCount;
    }
};