// Given two sorted arrays, nums1 and nums2, return an array containing the intersection of these two arrays. Each element in the result must appear as many times as it appears in both arrays.

// The intersection of two arrays is an array where all values are present in both arrays.

// Examples:
// Input: nums1 = [1, 2, 2, 3, 5], nums2 = [1, 2, 7]

// Output: [1, 2]

// Explanation: The elements 1, 2 are the only elements present in both nums1 and nums2

// Input: nums1 = [1, 2, 2, 3], nums2 = [4, 5, 7]

// Output: []

// Explanation: No elements appear in both nums1 and nums2

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> intersectionArray(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans;
        int l = 0, r = 0;
        while (l < n1 && r < n2)
        {
            if (nums1[l] == nums2[r])
            {
                ans.push_back(nums1[l]);
                l++;
                r++;
            }
            else if (nums1[l] < nums2[r])
                l++;
            else
                r++;
        }
        return ans;
    }
};