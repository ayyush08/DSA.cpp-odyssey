// Median of 2 sorted arrays
// Hard

// Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays.

// The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.

// Examples:
// Input: arr1 = [2, 4, 6], arr2 = [1, 3, 5]

// Output: 3.5

// Explanation: The array after merging arr1 and arr2 will be [ 1, 2, 3, 4, 5, 6 ]. As the length of the merged list is even, the median is the average of the two middle elements. Here two medians are 3 and 4. So the median will be the average of 3 and 4, which is 3.5.

// Input: arr1 = [2, 4, 6], arr2 = [1, 3]

// Output: 3.0

// Explanation: The array after merging arr1 and arr2 will be [ 1, 2, 3, 4, 6 ]. The median is simply 3.

// Brute Force Approach: Merge both arrays and find the median. (Time Complexity: O(m + n), Space Complexity: O(m + n))

// Better Approach: Optimize space by tracking  the indices of the two arrays instead of merging them.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double median(vector<int> &arr1, vector<int> &arr2)
    {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n = n1 + n2;
        int ind1 = n / 2, ind2 = ind1 - 1, cnt = 0;
        int i = 0, j = 0, e1 = -1, e2 = -1;
        while (i < n1 && j < n2)
        {
            if (arr1[i] < arr2[j])
            {
                if (cnt == ind1)
                    e1 = arr1[i];
                if (cnt == ind2)
                    e2 = arr1[i];
                cnt++;
                i++;
            }
            else
            {
                if (cnt == ind1)
                    e1 = arr2[j];
                if (cnt == ind2)
                    e2 = arr2[j];
                cnt++;
                j++;
            }
        }
        while (i < n1)
        {
            if (cnt == ind1)
                e1 = arr1[i];
            if (cnt == ind2)
                e2 = arr1[i];
            i++;
            cnt++;
        }
        while (j < n2)
        {
            if (cnt == ind1)
                e1 = arr2[j];
            if (cnt == ind2)
                e2 = arr2[j];
            j++;
            cnt++;
        }
        if (n % 2 == 1)
            return (double)e1;
        return (double)((double)(e1 + e2)) / 2.0;
    }
};


//Time Complexity: O(m + n), where m and n are the sizes of the two arrays.
//Space Complexity: O(1), as we are using only a constant amount of extra space

// Optimal Approach: Use binary search to split the two arrays into two halves such that all elements in the left half are less than or equal to all elements in the right half.

class Solution2
{
public:
    double median(vector<int> &arr1, vector<int> &arr2)
    {
        int n1 = arr1.size();
        int n2 = arr2.size();
        if (n1 > n2)
            return median(arr2, arr1);
        int n = n1 + n2;
        int low = 0, high = n1;
        int leftHalf = (n + 1) / 2;

        while (low <= high)
        {
            int mid1 = (low + high) >> 1; //elements in arr1's left half
            int mid2 = leftHalf - mid1;/// elements in arr2's left half
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1)
                r1 = arr1[mid1];
            if (mid2 < n2)
                r2 = arr2[mid2];
            if (mid1 - 1 >= 0)
                l1 = arr1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = arr2[mid2 - 1];
            if (l1 <= r2 && l2 <= r1) // found the correct partition for median
            {
                if (n % 2 == 1)
                    return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2) // too many elements in arr1's left half, reduce it
            {
                high = mid1 - 1;
            }
            else // too many elements in arr2's left half, increase arr1's left half
                low = mid1 + 1;
        }
        return 0;
    }
};

//Time Complexity: O(log(min(m, n))), where m and n are the sizes of the two arrays.
//Space Complexity: O(1), as we are using only a constant amount of extra space