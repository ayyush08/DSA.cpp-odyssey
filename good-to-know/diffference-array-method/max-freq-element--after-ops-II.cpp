// 3347. Maximum Frequency of an Element After Performing Operations II

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

// Adding 0 to nums[1], after which nums becomes [1, 4, 5].
// Adding -1 to nums[2], after which nums becomes [1, 4, 4].
// Example 2:

// Input: nums = [5,11,20,20], k = 5, numOperations = 1

// Output: 2

// Explanation:

// We can achieve a maximum frequency of two by:

// Adding 0 to nums[1].

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 0 <= k <= 109
// 0 <= numOperations <= nums.length

#include <bits/stdc++.h>
using namespace std;

// Difference Array Method from previous problem won't work here as nums[i] can be as large as 10^9 and may give MLE.
//instead of a whole maxSize array, we can use a map to store only the required indices in the difference array. because in between those indices the values will remain same as no updates are made there.
//Make sure to have the given values in the map as well to consider their frequencies.
//rest of the logic remains same almost.
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        int maxSize = *max_element(nums.begin(), nums.end()) + k;
        map<int, int> diffMap;
        unordered_map<int, int> freq;
        // O(nlogn)
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
            int l = max(0, nums[i] - k);       // keep in range
            int r = min(maxSize, nums[i] + k); // keep in range
            diffMap[l]++;
            diffMap[r + 1]--;
            diffMap[nums[i]] += 0; // to include if not taken
        }

        int ans = 1;
        int cumulative_sum = 0;
        // O(n)
        for (auto it = diffMap.begin(); it != diffMap.end(); it++)
        {
            int target = it->first;
            it->second += cumulative_sum;
            int targetFreq = freq[target];
            int needConversions = it->second - targetFreq;
            int maxPossible = min(needConversions, numOperations);
            ans = max(ans, maxPossible + targetFreq);
            cumulative_sum = it->second;
        }
        return ans;
    }
};

// Time Complexity: O(N log N) where N is the size of nums due to map operations.
// Space Complexity: O(N) for the difference map and frequency map.