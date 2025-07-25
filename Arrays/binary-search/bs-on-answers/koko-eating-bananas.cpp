// Koko eating bananas

// A monkey is given n piles of bananas, where the 'ith' pile has nums[i] bananas. An integer h represents the total time in hours to eat all the bananas.

// Each hour, the monkey chooses a non-empty pile of bananas and eats k bananas. If the pile contains fewer than k bananas, the monkey eats all the bananas in that pile and does not consume any more bananas in that hour.

// Determine the minimum number of bananas the monkey must eat per hour to finish all the bananas within h hours.

// Examples:
// Input: n = 4, nums = [7, 15, 6, 3], h = 8

// Output: 5

// Explanation: If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. So, he will take 8 hours to complete all the piles.

// Input: n = 5, nums = [25, 12, 8, 14, 19], h = 5

// Output: 25

// Explanation: If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour to eat the piles accordingly. So, he will take 5 hours to complete all the piles.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxEle(vector<int> &arr)
    {
        int ans = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            ans = max(ans, arr[i]);
        }
        return ans;
    }
    bool canEat(vector<int> &nums, int hrs, int &h)
    {
        long long tot = 0;
        for (int i : nums)
        {
            tot += ceil((long long)i / (double)hrs);
        }
        return tot <= h;
    }

    int minimumRateToEatBananas(vector<int> nums, int h)
    {
        int end = maxEle(nums);
        int low = 1, high = end;
        while (low <= high)
        {
            long long mid = (low + high) / 2;
            if (canEat(nums, mid, h))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

//NOTE: This can also be done with linear search, but for large inputs that will throw TLE.  Since for linear search we will have to check for each value from 1 to maxEle(nums) which will take O(n * maxEle(nums)) time, but with binary search we can do it in O(n * log(maxEle(nums))) time.
// So, binary search is the optimal solution for this problem.


//Intution: The range for koko to eat bananas is between 1 and maxEle(nums). Because after maxEle(nums) ,the time taken to eat bananas will remain same for koko.