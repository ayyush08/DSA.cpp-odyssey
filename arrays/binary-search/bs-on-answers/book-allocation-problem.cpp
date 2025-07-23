// Book Allocation Problem

// Hard

// Given an array nums of n integers, where nums[i] represents the number of pages in the i-th book, and an integer m representing the number of students, allocate all the books to the students so that each student gets at least one book, each book is allocated to only one student, and the allocation is contiguous.

// Allocate the books to m students in such a way that the maximum number of pages assigned to a student is minimized. If the allocation of books is not possible, return -1.

// Examples:
// Input: nums = [12, 34, 67, 90], m=2

// Output: 113

// Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.

// Input: nums = [25, 46, 28, 49, 24], m=4

// Output: 71

// Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int allocate(vector<int> &nums, int pages)
    {
        int allocatedStudents = 1, allocatedPages = 0;
        for (int book : nums)
        {
            if (book + allocatedPages <= pages)
            {
                allocatedPages += book;
            }
            else
            {
                allocatedStudents++;
                allocatedPages = book;
            }
        }
        return allocatedStudents;
    }
    int findPages(vector<int> &nums, int m)
    {
        if (m > nums.size())
            return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int allocatedStudents = allocate(nums, mid);
            if (allocatedStudents <= m) //successful allocation, try to minimize the maximum pages
                high = mid - 1;
            else
                low = mid + 1; // too many students, increase the maximum pages
        }
        return low;
    }
};

//Time Complexity: O(n log(sum of pages))
//Space Complexity: O(1)