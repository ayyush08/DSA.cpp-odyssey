// Set difference of two arrays

// 0

// 100
// Easy
// Given two sorted arrays nums1 and nums2, return an array that contains the set difference of these two arrays. The elements in the set difference must be in ascending order.

// The set difference of two arrays is an array where all values are distinct and are present in either the first array or the second array, but not in both.

// Examples:
// Input: nums1 = [1, 5, 7, 9], nums2 = [1, 3, 4, 7]

// Output: [3, 4, 5, 9]

// Explanation: [3, 4, 5, 9] where,

// [3, 4] come from nums2 and [5, 9] comes from nums1.

// Input: nums1 = [1, 2, 6, 6], nums2 = [-2, 2, 3, 4, 6]

// Output: [-2, 1, 3, 4]

// Explanation: [-2, 1, 3, 4] where,

// [1] comes from nums1 and [-2, 3, 4] from nums2.

// Constraints:
// 1 <= nums1.length, nums2.length <= 105
// -104 <= nums1[i] , nums2[i] <= 104
// Both nums1 and nums2 are sorted in non-decreasing order

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> setDifference(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans;
        int l = 0, r = 0;
        while (l < n1 && r < n2)
        {
            if (nums1[l] < nums2[r])
            {
                if (ans.size() == 0 || ans.back() != nums1[l])
                {
                    ans.push_back(nums1[l]);
                }
                int val = nums1[l];
                while (l < n1 && nums1[l] == val)
                    l++;
            }
            else if (nums1[l] > nums2[r])
            {
                if (ans.size() == 0 || ans.back() != nums2[r])
                {
                    ans.push_back(nums2[r]);
                }
                int val = nums2[r];
                while (r < n2 && nums2[r] == val)
                    r++;
            }
            else
            {
                int val = nums1[l];
                while (l < n1 && nums1[l] == val)
                    l++;
                while (r < n2 && nums2[r] == val)
                    r++;
            }
        }
        while (l < n1)
        {
            if (ans.empty() || ans.back() != nums1[l])
                ans.push_back(nums1[l]);
            int val = nums1[l];
            while (l < n1 && nums1[l] == val)
                l++;
        }
        while (r < n2)
        {
            if (ans.empty() || ans.back() != nums2[r])
                ans.push_back(nums2[r]);
            int val = nums2[r];
            while (r < n2 && nums2[r] == val)
                r++;
        }

        return ans;
    }
};


//Keypoints:
//Similar logic to reverse pairs and count inversion question, we can use two pointers to find the set difference of two sorted arrays.
//The key difference is to ensure that we only add distinct elements to the result vector, which we check after every addition to the result by moving the pointers forward until we find a different value.
//This ensures that the result is in ascending order and contains distinct elements always.

// Time Complexity:O(m+n) where n and m are the sizes of nums1 and nums2, respectively, since we iterate through both arrays at most once.
// Space Complexity:O(min(m,n)) in the worst case, where n and m are the sizes of nums1 and nums2, respectively, as the size of the answer vector `ans` is bounded by the smaller array's unique elements.