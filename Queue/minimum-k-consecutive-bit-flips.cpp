// You are given a binary array nums and an integer k.

// A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

// Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.

// A subarray is a contiguous part of an array.

// Example 1:

// Input: nums = [0,1,0], k = 1
// Output: 2
// Explanation: Flip nums[0], then flip nums[2].
// Example 2:

// Input: nums = [1,1,0], k = 2
// Output: -1
// Explanation: No matter how we flip subarrays of size 2, we cannot make the array become [1,1,1].
// Example 3:

// Input: nums = [0,0,0,1,0,1,1,0], k = 3
// Output: 3
// Explanation:
// Flip nums[0],nums[1],nums[2]: nums becomes [1,1,1,1,0,1,1,0]
// Flip nums[4],nums[5],nums[6]: nums becomes [1,1,1,1,1,0,0,0]
// Flip nums[5],nums[6],nums[7]: nums becomes [1,1,1,1,1,1,1,1]

// Constraints:

// 1 <= nums.length <= 105
// 1 <= k <= nums.length

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int n = nums.size();
        int fcnt = 0;
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (!q.empty() && q.front() <= i - k)
                q.pop();

            int flipsSoFar = q.size() % 2;
            if ((nums[i] + flipsSoFar) % 2 == 0)
            {
                if (i + k > n)
                    return -1;
                q.push(i);
                fcnt++;
            }
        }

        return fcnt;
    }
};

//Approach: 
// 1. Use a queue to keep track of the indices where flips are made.
// 2. For each index, check if the current bit is 0 after considering the flips so far.
// 3. If it is, and if flipping is possible (i.e., the subarray of length k can be flipped), push the index into the queue and increment the flip count.
// 4. If the queue's front index is out of the current window of size k, pop it from the queue.
// 5. Finally, return the total number of flips made, or -1 if it's not possible to make all bits 1.