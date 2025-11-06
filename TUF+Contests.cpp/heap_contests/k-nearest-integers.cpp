// K Nearest Integers
// Given an integer array arr and two integers k and x. Your task is to find k numbers from the array that are nearest to the value x. The nearness of a integer is determined by its absolute difference from x. If two integers have the same difference from x, choose the smaller integer. Return the selected integers sorted in ascending order.

// Examples:
// Input: arr = [4, 1, 3, 2, 5], k = 3, x = 3

// Output: [2, 3, 4]

// Explanation: The integers nearest to 3 are 3 (distance 0), 2 (distance 1), and 4 (distance 1). After sorting, the result is [2, 3, 4].

// Input: arr = [10, 5, 2, 1, 7], k = 4, x = 6

// Output:[2, 5, 7, 10]

// Explanation: The nearest integers to 6 are 5 (distance 1), 7 (distance 1), 10 (distance 4), and 2 (distance 4). After Sorting, the result is [2, 5, 7, 10].

// Constraints:
// 1 <= k <= arr.length
// 1 <= arr.length <= 104
// arr is sorted in ascending order.
// -104 <= arr[i], x <= 104

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef pair<int, int> P;
    vector<int> kNearestIntegers(vector<int> &nums, int k, int x)
    {
        priority_queue<P> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            int diff = abs(nums[i] - x);
            if (pq.size() < k)
                pq.push({diff, nums[i]});
            else if (diff < pq.top().first)
            {
                pq.pop();
                pq.push({diff, nums[i]});
            }
            else if (diff == pq.top().first)
            {
                if (pq.top().second > nums[i])
                {
                    pq.pop();
                    pq.push({diff, nums[i]});
                }
            }
        }
        vector<int> ans;
        while (pq.size())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// O(n log k + k log k) Time Complexity - Used heap just for contest can be optimized to O(n log k) by using two pointers+binary search 
// O(k) Space Complexity