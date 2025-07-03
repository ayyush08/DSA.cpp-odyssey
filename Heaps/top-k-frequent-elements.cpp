// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.

#include <bits/stdc++.h>
using namespace std;
// Approach 1: Using a priority queue (max heap) with frequency count storage
class Solution1
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int n : nums)
            mp[n]++;
        priority_queue<pair<int, int>> pq;
        for (auto &it : mp)
        {
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        while (!pq.empty() && k)
        {
            ans.push_back(pq.top().second);
            k--;
            pq.pop();
        }
        return ans;
    }
};

// Approach 2: Maintaining a min heap of size k
class Solution2
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int n : nums)
            mp[n]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto &it : mp)
        {
            pq.push({it.second, it.first});
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};