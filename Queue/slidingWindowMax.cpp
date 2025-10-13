// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation:
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

#include <bits/stdc++.h>
using namespace std;

// Approach1: use multiset, add last to ans, and remove starter when window not k

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        multiset<int> ms;
        int n = nums.size();
        int l = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            ms.insert(nums[i]);
            if (i - l + 1 == k)
            {
                ans.push_back(*ms.rbegin());
                ms.erase(ms.find(nums[l]));
                l++;
            }
        }
        return ans;
    }
};

class Solution2
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;
        int n = nums.size(), l = 0;
        for (int i = 0; i < n; i++)
        {

            while (!dq.empty() && nums[dq.back()] <= nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i - l + 1 > k)
                l++;
            if (!dq.empty() && dq.front() < l)
                dq.pop_front();
            if (i - l + 1 == k)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

// Use deque and store indices of max elements of each window in a monotonic decreasing order
class Solution3//similar approach just different implementation
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