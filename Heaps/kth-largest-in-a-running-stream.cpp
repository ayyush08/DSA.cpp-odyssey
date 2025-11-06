// Kth largest element in a stream of running integers

// Implement a class KthLargest to find the kth largest number in a stream. It should have the following methods:

// KthLargest(int k, int [] nums) Initializes the object with the integer k and the initial stream of numbers in nums
// int add(int val) Appends the integer val to the stream and returns the kth largest element in the stream.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Examples:
// Input: [KthLargest(3, [1, 2, 3, 4]), add(5), add(2), add(7)]
// Output: [null, 3, 3, 4]
// Explanation: initial stream = [1, 2, 3, 4], k = 3.
// add(5): stream = [1, 2, 3, 4, 5] -> returns 3
// add(2): stream = [1, 2, 2, 3, 4, 5] -> returns 3
// add(7): stream = [1, 2, 2, 3, 4, 5, 7] -> returns 4

// Input: [KthLargest(2, [5, 5, 5, 5], add(2), add(6), add(60)]
// Output: [null, 5, 5, 6]
// Explanation: initial stream = [5, 5, 5, 5], k = 2.
// add(2): stream = [5, 5, 5, 5, 2] -> returns 5
// add(6): stream = [5, 5, 5, 5, 2, 6] -> returns 5
// add(60): stream = [5, 5, 5, 5, 2, 6, 60] -> returns 6

// Submit
// Constraints:
// 1 <= Number of instructions <= 1000
// -104 <= val & all initial values <= 104
// 1 <= k <= 104
// k - 1 <= nums.length <= 103
// The stream will have at least k elements during any add call.

#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
public:
    int limit;
    priority_queue<int, vector<int>, greater<>> pq;
    KthLargest(int k, vector<int> &nums)
    {
        limit = k;

        for (int i = 0; i < nums.size(); i++)
        {
            if (pq.size() < limit)
                pq.push(nums[i]);
            else if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }

    int add(int val)
    {
        if (pq.size() < limit)
        {
            pq.push(val);
            return pq.top();
        }
        if (val > pq.top())
        {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};


//Time Complexity: O(NlogK) for initial construction where N is size of nums and O(logK) for each add operation
//Space Complexity: O(K) for maintaining min-heap of size k
//Naive approach would be return k-1th element and in add sort before returning k-1th element which would be O(NlogN) for each add operation