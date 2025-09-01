// Max Consecutive Ones III

// Given a binary array nums and an integer k, flip at most k 0's.

// Return the maximum number of consecutive 1's after performing the flipping operation.

// Examples:
// Input : nums = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0] , k = 3

// Output : 10

// Explanation : The maximum number of consecutive 1's are obtained only if we flip the 0's present at position 3, 4, 5 (0 base indexing).

// The array after flipping becomes [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0].

// The number of consecutive 1's is 10.

// Input : nums = [0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1] , k = 3

// Output : 9

// Explanation : The underlines 1's are obtained by flipping 0's in the new array.

// [1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1].

// The number of consecutive 1's is 9.

#include <bits/stdc++.h>
using namespace std;

// Brute - generate all subarray of 0's and take the max subarray length in ans;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        // your code goes here
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int zero = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] == 0)
                    zero++;
                if (zero <= k)
                {
                    ans = max(ans, j - i + 1);
                }
                else
                {
                    break;
                }
            }
        }
        return ans;
    }
};

// Better use sliding window and shrink when zero count crosses k - O(2N)
class Solution2
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int ans = 0;
        int n = nums.size();

        int l = 0, r = 0;
        int zero = 0;
        while (r < n)
        {
            if (nums[r] == 0)
                zero++;
            while (zero > k)
            {
                if (nums[l] == 0)
                    zero--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};

// Optimal - extra O(N) of trimming can be avoided in a straightforward manner like this
class Solution3
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int ans = 0;
        int n = nums.size();

        int l = 0, r = 0;
        int zero = 0;
        while (r < n)
        {
            if (nums[r] == 0)
                zero++;
            if (zero > k)
            {
                if (nums[l] == 0)
                    zero--;
                l++;
            }
            else
            {
                ans = max(ans, r - l + 1);
            }
            r++;
        }
        return ans;
    }
};
