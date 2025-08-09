// Combination XOR
// Given an array of distinct integers nums and an integer k, return all unique non-empty combinations of elements with a bitwise XOR of k. Return an empty vector if no combinations are possible.

// Each element can be used only once in each combination. Two combinations are unique if at least one element is present in only one combination. Answer can be returned in any order.

// Examples:
// Input: nums = [57, 21, 8, 52, 41, 73], k = 57

// Output: [[8, 21, 41, 52, 57], [57]]

// Explanation: 8 xor 21 xor 41 xor 52 xor 57 = 57

// 57 itself is another combination.

// No other distinct combination exists.

// Input: nums = [1, 2, 3, 5], k = 1

// Output: [[1], [2, 3]]

// Explanation: 2 ^ 3 = 1

// 1 itself is another combination.

// No other distinct combination exists.

// Constraints:
// 1 <= nums.length <= 10
// 0 <= nums[i] <= 1000
// 0 <= k <= 1000

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void func(int ind, vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums,
                int k, int rnXr)
    {

        if (ind == nums.size())
        {
            if (rnXr == k && !temp.empty()) // avoid empty combinations
                ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        func(ind + 1, ans, temp, nums, k, rnXr ^ nums[ind]);
        temp.pop_back();
        func(ind + 1, ans, temp, nums, k, rnXr);
    }
    vector<vector<int>> combinationXor(vector<int> nums, int k)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        func(0, ans, temp, nums, k, 0);
        return ans;
    }
};

// Time Complexity:O(2^n * n * log n), where n is the size of the input vector nums. Sorting takes O(n log n). The recursive function func explores all 2^n subsets. Copying temp to ans takes O(n) in the worst case for each valid subset.
// Space Complexity:O(n), where n is the size of the input vector nums, due to the recursion depth and the auxiliary space used by temp.
