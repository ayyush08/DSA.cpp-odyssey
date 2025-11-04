// K-th Largest element in an array

// Given an array nums, return the kth largest element in the array.

// Examples:
// Input: nums = [1, 2, 3, 4, 5], k = 2

// Output: 4

// Input: nums = [-5, 4, 1, 2, -3], k = 5

// Output: -5

#include <bits/stdc++.h>
using namespace std;

// Brute-Better Approach -Since only the K largest elements matter, a min-heap of size K is maintained. While processing any element, it is checked if it is among the K largest elements encountered so far. If it is, the smallest element is removed from the min-heap and the new element is inserted.

// Time Complexity - O(NlogK)
// Space Complexity - O(K)

class Solution
{
public:
    int kthLargestElement(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<>> pq;

        for (int i = 0; i < k; i++)
            pq.push(nums[i]);

        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};

// Optimal - use quick sort partitioning logic
//  Time Complexity - O(N) on average, O(N^2) in worst case which is unlikely
//  Space Complexity - O(1)
class Solution2
{
public:
    int partitionAndReturnIndex(vector<int> &nums, int pivot, int l, int r)
    {
        swap(nums[l], nums[pivot]);
        int ind = l + 1;
        // int i=l+1;

        for (int i = l + 1; i <= r; i++)
        {
            if (nums[i] > nums[l])
            {
                swap(nums[ind], nums[i]);
                ind++;
            }
        }
        swap(nums[l], nums[ind - 1]);
        return ind - 1;
    }
    int getRandomisedIndex(int l, int r)
    {
        int len = r - l + 1;
        return (rand() % len) + l;
    }
    int kthLargestElement(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0, r = n - 1;

        while (true)
        {
            int pivot = getRandomisedIndex(l, r);
            pivot = partitionAndReturnIndex(nums, pivot, l, r);
            if (pivot == k - 1)
                return nums[pivot];
            else if (k - 1 < pivot)
            {
                r = pivot - 1;
            }
            else
                l = pivot + 1;
        }
        return -1;
    }
};