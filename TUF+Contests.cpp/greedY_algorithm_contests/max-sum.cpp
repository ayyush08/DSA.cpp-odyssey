// Maximum sum

// 0

// 100
// Easy
// Jax is trying to solve a problem but he has to go out to play with friends. So he ask you to solve the problem and he went to play with his friends.

// You are given an array and you have to maximize the sum of the array by using below two operations each once.

// 1) You can choose any prefix of the array (possibly empty) and multiply with -1.

// 2) You can choose any suffix of the array (possibly empty) and multiply with -1.

// The chosen prefix and suffix may intersect. You have to find the maximum sum of the array by performing the above operations.

// Examples:
// Input : nums = [-1, 2 , -3]

// Output : 6

// Explanation :

// In first operation we will choose the prefix array as [-1] and multiply it with -1.

// In second operation we will choose the suffix array as [-3] and multiply it with -1.

// The new array after the operations performed will be [1, 2, 3].

// The maximum sum would be => 1 + 2 + 3 => 6.

// Input : nums = [-1, 10, -5, 10, -2]

// Output : 18

// Explanation :

// The prefix chosen is [-1].

// The suffix chosen is [-2].

// The new array will be -> [1, 10, -5, 10, 2].

// Sum would be => 1 + 10 + (-5) + 10 + 2 => 18.

// Constraints:
// 1 <= n <= 105
// 10-4 <= nums[i] <= 10-4

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);

        vector<long long> pref(n + 1, 0), suff(n + 1, 0);
        

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];
        
        for (int i = n - 1; i >= 0; i--)
            suff[i] = suff[i + 1] + nums[i];
        
        long long ans = total;
        
        // Store minimum suffix sums to optimize the search for best suffix to flip
        vector<long long> minSuff(n + 2, LLONG_MAX);
        minSuff[n] = suff[n];
        for (int i = n - 1; i >= 0; i--)
            minSuff[i] = min(suff[i], minSuff[i + 1]);

        // Try all possible combinations of prefix and suffix flips
        // When we flip a number, its contribution to sum changes by -2 times its value
        // total - 2 * pref[i] - 2 * minSuff[i] represents sum after flipping prefix till i and optimal suffix
        for (int i = 0; i <= n; i++)
            ans = max(ans, total - 2 * pref[i] - 2 * minSuff[i]);

        return ans;
    }
};

class Solution2
{
public:
    int maxSum(vector<int> &nums)
    {
        int n = nums.size();
        long long sum = 0;

        // Flip prefix negatives
        int i = 0;
        while (i < n && nums[i] < 0)
        {
            nums[i] = -nums[i];
            i++;
        }

        // Flip suffix negatives
        int j = n - 1;
        while (j >= 0 && nums[j] < 0)
        {
            nums[j] = -nums[j];
            j--;
        }

        // Compute total sum after flips
        for (int x : nums)
            sum += x;

        return sum;
    }
};