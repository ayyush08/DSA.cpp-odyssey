// 3346. Maximum Frequency of an Element After Performing Operations I
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer array nums and two integers k and numOperations.

// You must perform an operation numOperations times on nums, where in each operation you:

// Select an index i that was not selected in any previous operations.
// Add an integer in the range [-k, k] to nums[i].
// Return the maximum possible frequency of any element in nums after performing the operations.

// Example 1:

// Input: nums = [1,4,5], k = 1, numOperations = 2

// Output: 2

// Explanation:

// We can achieve a maximum frequency of two by:

// Adding 0 to nums[1]. nums becomes [1, 4, 5].
// Adding -1 to nums[2]. nums becomes [1, 4, 4].
// Example 2:

// Input: nums = [5,11,20,20], k = 5, numOperations = 1

// Output: 2

// Explanation:

// We can achieve a maximum frequency of two by:

// Adding 0 to nums[1].

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105
// 0 <= k <= 105
// 0 <= numOperations <= nums.length

#include <bits/stdc++.h>
using namespace std;

// Difference Array Method

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        int maxSize = *max_element(nums.begin(), nums.end()) + k;
        vector<int> diffArr(maxSize + 2, 0);
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
            int l = max(0, nums[i] - k);       // keep in range
            int r = min(maxSize, nums[i] + k); // keep in range
            diffArr[l]++;
            diffArr[r + 1]--;
        }

        int ans = 1;

        for (int target = 0; target <= maxSize; target++)
        {
            diffArr[target] += (target > 0 ? diffArr[target - 1] : 0);
            int targetFreq = freq[target];
            int needConversions = diffArr[target] - targetFreq;
            int maxPossible = min(needConversions, numOperations);
            ans = max(ans, maxPossible + targetFreq);
        }
        return ans;
    }
};

// Time Complexity: O(N + M) where N is the size of nums and M is the range of numbers in nums after adding/subtracting k.
// Space Complexity: O(M) for the difference array.

// cumulative frequency method

class Solution2
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        int maxSize = *max_element(nums.begin(), nums.end()) + k + 1;
        vector<int> freq(maxSize + 1, 0);
        for (int n : nums)
            freq[n]++;
        for (int i = 1; i < maxSize; i++)
            freq[i] += freq[i - 1];

        int ans = 0;

        for (int target = 0; target < maxSize; target++)
        {
            if (freq[target] == 0)
                continue;
            int l = max(0, target - k);       // keep in range
            int r = min(maxSize, target + k); // keep in range
            int totalCount = freq[r] - (l > 0 ? freq[l - 1] : 0);
            int targetCount = freq[target] - (target > 0 ? freq[target - 1] : 0);
            int reqOps = totalCount - targetCount;
            int maxPossible = targetCount + min(numOperations, reqOps);
            ans = max(ans, maxPossible);
        }
        return ans;
    }
};

// Time Complexity: O(N + M) where N is the size of nums and M is the range of numbers in nums after adding/subtracting k.
// Space Complexity: O(M) for the frequency array.
