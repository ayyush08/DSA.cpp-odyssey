// 3510. Minimum Pair Removal to Sort Array II
// Given an array nums, you can perform the following operation any number of times:

// Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
// Replace the pair with their sum.
// Return the minimum number of operations needed to make the array non-decreasing.

// An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

// Example 1:

// Input: nums = [5,2,3,1]

// Output: 2

// Explanation:

// The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
// The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
// The array nums became non-decreasing in two operations.

// Example 2:

// Input: nums = [1,2,2]

// Output: 0

// Explanation:

// The array nums is already sorted.

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumPairRemoval(vector<int> &nums)
    {
        int ops = 0;
        int n = nums.size();
        vector<long long> temp(n); //clone to store largeer sums
        for (int i = 0; i < n; i++)
            temp[i] = nums[i];

        //precompute prev and next indices
        vector<int> prev(n);
        vector<int> next(n);
        set<pair<long long, int>> st;
        int badPairs = 0;
        for (int i = 0; i < n; i++)
        {
            prev[i] = i - 1;
            next[i] = i + 1;
            if (i + 1 < n)
            {
                st.insert({temp[i] + temp[i + 1], i});
                if (temp[i] > temp[i + 1])
                    badPairs++;
            }
        }

        while (badPairs)
        {
            int first = st.begin()->second;
            int second = next[first];

            int first_left = prev[first];
            int second_right = next[second];

            if (temp[first] > temp[second]) //start working on this bad pair
                badPairs--;
            st.erase(st.begin());
            if (first_left >= 0)
            {
                if (temp[first_left] <= temp[first] && temp[first_left] > temp[first] + temp[second]) //first_left earlier made good pair with first but now becomes bad
                    badPairs++;
                else if (temp[first_left] > temp[first] && temp[first_left] <= temp[first] + temp[second]) //first_left earlier made bad pair with first but now becomes good
                    badPairs--;
            }

            if (second_right < n)
            {
                if (temp[second] <= temp[second_right] &&
                    temp[first] + temp[second] > temp[second_right])//second earlier made good pair with second but now becomes bad
                    badPairs++;
                else if (temp[second] > temp[second_right] &&
                         temp[first] + temp[second] <= temp[second_right]) //second earlier made bad pair with second but now becomes good
                    badPairs--;
            }
            if (first_left >= 0)
            {
                st.erase({temp[first_left] + temp[first], first_left}); //erase old pairs
                st.insert({temp[first_left] + temp[first] + temp[second], first_left}); //insert new pair
            }

            if (second_right < n)
            {
                st.erase({temp[second_right] + temp[second], second});
                st.insert({temp[second_right] + temp[first] + temp[second], first});
                prev[second_right] = first; //update links
            }
            next[first] = second_right;
            //merge the pairs
            temp[first] += temp[second];
            ops++;
        }
        return ops;
    }
};

//Time Complexity: O(n log n) where n is the number of elements in the array
//Space Complexity: O(n) for the temp, prev, next arrays and the set