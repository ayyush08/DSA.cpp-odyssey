// Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. The elements in the union must be in ascending order.

// The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.

// Examples:
// Input: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]

// Output: [1, 2, 3, 4, 5, 7]

// Explanation: The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2

// Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]

// Output: [1, 3, 4, 5, 6, 7, 8, 9]

// Explanation: The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from nums2

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans;
        int l = 0, r = 0;
        while (l < n1 && r < n2)
        {
            if (nums1[l] <= nums2[r])
            {
                if (ans.size() == 0 || ans.back() != nums1[l])
                {
                    ans.push_back(nums1[l]);
                }
                l++;
            }
            else
            {
                if (ans.size() == 0 || ans.back() != nums2[r])
                {
                    ans.push_back(nums2[r]);
                }
                r++;
            }
        }
        while (l < n1)
        {
            if (ans.back() != nums1[l])
                ans.push_back(nums1[l]);
            l++;
        }
        while (r < n2)
        {
            if (ans.back() != nums2[r])
                ans.push_back(nums2[r]);
            r++;
        }
        return ans;
    }
};
