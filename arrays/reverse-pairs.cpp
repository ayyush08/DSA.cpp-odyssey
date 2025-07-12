// Given an integer array nums. Return the number of reverse pairs in the array.

// An index pair (i, j) is called a reverse pair if:

// 0 <= i < j < nums.length

// nums[i] > 2 * nums[j]

// Examples:
// Input: nums = [6, 4, 1, 2, 7]

// Output: 3

// Explanation: The reverse pairs are:

// (0, 2) : nums[0] = 6, nums[2] = 1, 6 > 2 * 1

// (0, 3) : nums[0] = 6, nums[3] = 2, 6 > 2 * 2

// (1, 2) : nums[1] = 4, nums[2] = 1, 4 > 2 * 1

// Input: nums = [5, 4, 4, 3, 3]

// Output: 0

// Explanation: No pairs satisfy both the conditons.

// Input: nums = [6, 4, 4, 2, 2]

// Output:
// 2
// Constraints:
// 1 <= nums.length <= 5 * 104
// -231 <= nums[i] <= 231 - 1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while (left <= mid)
        {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high)
        {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
            nums[i] = temp[i - low];
    }

    long long int countPairs(vector<int> &nums, int low, int mid, int high)
    {
        int cnt = 0, right = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && (long long)nums[i] > 2LL * nums[right])
                right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    long long int mergeSort(vector<int> &nums, int low, int high)
    {
        long long int cnt = 0;
        if (low < high)
        {
            int mid = low + (high - low) / 2;
            cnt += mergeSort(nums, low, mid);
            cnt += mergeSort(nums, mid + 1, high);
            cnt += countPairs(nums, low, mid, high);
            merge(nums, low, mid, high);
            return cnt;
        }
        return 0;
    }
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

//Similar to count inversions, we can use a modified merge sort to count the number of reverse pairs., right before merging we count the number of pairs that satisfy the condition nums[i] > 2 * nums[j].
//Time Complexity: O(2n log n) - The merge sort algorithm runs in O(n log n) time and we perform a linear scan to count pairs, which is O(n) for each merge step.
//Space Complexity: O(n) - We use a temporary array to store the merged results.
//Note: The countPairs function counts the number of valid pairs in the left half of the array that satisfy the condition with elements in the right half. It uses a two-pointer technique to efficiently count these pairs while merging.
//This approach ensures that we efficiently count the reverse pairs while maintaining the overall time complexity of the merge sort algorithm.