// Given two integer arrays nums1 and nums2. Both arrays are sorted in non-decreasing order.

// Merge both the arrays into a single array sorted in non-decreasing order.

// The final sorted array should be stored inside the array nums1 and it should be done in-place.
// nums1 has a length of m + n, where the first m elements denote the elements of nums1 and rest are 0s.
// nums2 has a length of n.

// Examples:
// Input: nums1 = [-5, -2, 4, 5], nums2 = [-3, 1, 8]

// Output: [-5, -3, -2, 1, 4, 5, 8]

// Explanation: The merged array is: [-5, -3, -2, 1, 4, 5, 8], where [-5, -2, 4, 5] are from nums1 and [-3, 1, 8] are from nums2

// Input: nums1 = [0, 2, 7, 8], nums2 = [-7, -3, -1]

// Output: [-7, -3, -1, 0, 2, 7, 8]

// Explanation: The merged array is: [-7, -3, -1, 0, 2, 7, 8], where [0, 2, 7, 8] are from nums1 and [-7, -3, -1] are from nums2


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void swapIfGreater(vector<int> &nums1,vector<int> &nums2,int i,int j){
        if(nums1[i]>nums2[j]) swap(nums1[i],nums2[j]);
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m+n;
        int gap = (len/2)+(len%2);
        while(gap){
            int l=0;
            int r=l+gap;
            while(r<len){
                if(l<m && r>=m) swapIfGreater(nums1,nums2,l,r-m);
                else if(l>=m) swapIfGreater(nums2,nums2,l-m,r-m);
                else swapIfGreater(nums1,nums1,l,r);
                l++,r++;
            }
            if(gap==1)  break;
            gap = (gap/2) + (gap%2);
        }
        for(int i=m;i<m+n;i++) nums1[i] = nums2[i-m];
    }
};


//Time Complexity: O((m+n) * log(m+n)) - The while loop runs until the gap becomes 0, and in each iteration, we perform a linear scan of the array elements.
//Space Complexity: O(1) - We are using the input arrays themselves for merging,

//Intution: Use three pointers: i = m - 1 (last valid element in nums1) j = n - 1 (last element in nums2) k = m + n - 1 (last index in nums1). If nums1[i] > nums2[j], place nums1[i] at nums1[k]. Otherwise, place nums2[j] at nums1[k]. Move the pointer(s) accordingly.