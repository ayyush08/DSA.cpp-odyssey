// Kth element of 2 sorted arrays
// Given two sorted arrays a and b of size m and n respectively. Find the kth element of the final sorted array.

// Examples:
// Input: a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5

// Output: 6

// Explanation: The final sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

// Input: a = [100, 112, 256, 349, 770], b = [72, 86, 113, 119, 265, 445, 892], k = 7

// Output: 256

// Explanation: Final sorted array is - [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892], 7th element of this array is 256.

// NAIVE APPROACH - use two pointer till kth sorted index is reached

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        int n1 = a.size();
        int n2 = b.size();
        int cnt = 0;
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            int val;
            if (a[i] < b[j])
            {
                val = a[i];
                i++;
            }
            else
            {
                val = b[j];
                j++;
            }
            cnt++;
            if (cnt == k)
                return val;
        }
        while (i < n1)
        {
            cnt++;
            if (cnt == k)
                return a[i];
            i++;
        }
        while (j < n2)
        {
            cnt++;
            if (cnt == k)
                return b[j];
            j++;
        }
        return -1;
    }
};

// OPTIMAL APPROACH - Binary Search (Similar to median of two sorted arrays)

class Solution2
{
public:
    int kthElement(vector<int> &a, vector<int> &b, int k)
    {
        int n1 = a.size();
        int n2 = b.size();
        if (n1 > n2)
            return kthElement(b, a, k);
        int n = n1 + n2;
        int low = max(0, k - n2); //why? Because we must take at least (k - n2) elements from the smaller array to ensure the total is k if the larger array can't provide enough elements.
        int high = min(k, n1); // why? Because we can't take more than n1 elements from the smaller array, nor more than k total.
        int leftHalf = k;

        while (low <= high)
        {
            int mid1 = (low + high) >> 1; // elements in a's left half
            int mid2 = leftHalf - mid1;   /// elements in b's left half
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1)
                r1 = a[mid1];
            if (mid2 < n2)
                r2 = b[mid2];
            if (mid1 - 1 >= 0)
                l1 = a[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = b[mid2 - 1];
            if (l1 <= r2 && l2 <= r1) // found the correct partition for median
            {
                return max(l1, l2);
            }
            else if (l1 > r2) // too many elements in a's left half, reduce it
            {
                high = mid1 - 1;
            }
            else // too many elements in arr2's left half, increase a's left half
                low = mid1 + 1;
        }
        return -1;
    }
};