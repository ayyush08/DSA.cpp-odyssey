// 3321. Find X-Sum of All K-Long Subarrays II
// You are given an array nums of n integers and two integers k and x.

// The x-sum of an array is calculated by the following procedure:

// Count the occurrences of all elements in the array.
// Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
// Calculate the sum of the resulting array.
// Note that if an array has less than x distinct elements, its x-sum is the sum of the array.

// Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].

// Example 1:

// Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2

// Output: [6,10,12]

// Explanation:

// For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
// For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
// For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
// Example 2:

// Input: nums = [3,8,7,8,7,5], k = 2, x = 2

// Output: [11,15,15,15,12]

// Explanation:

// Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].

// Constraints:

// nums.length == n
// 1 <= n <= 105
// 1 <= nums[i] <= 109
// 1 <= x <= k <= nums.length

#include <bits/stdc++.h>
using namespace std;

// Earlier approach will give TLE for larger constraints as O(N*K*logK) for each window we are building frequency map and min-heap

// Optimal Approach - Use sliding window to maintain frequency map of current k size window
// Use 2 ordered sets to maintain top x frequent elements and rest of the elements
// This way we can maintain sum of top x frequent elements in O(logK) time for each window and sum in O(1) time

class Solution
{
public:
    long long sum = 0;
    set<pair<int, int>> main;  // top-x-(freq,elements)
    set<pair<int, int>> other; // rest (freq,elements)
    void insertInSet(const pair<int, int> &p, int x)
    {
        if (main.size() < x || p > *main.begin())
        {
            sum += (1LL * p.first * p.second);
            main.insert(p);

            if (main.size() > x)
            { // remove smallest to maintain x size
                auto front = *main.begin();
                sum -= (1LL * front.first * front.second);
                main.erase(front);
                other.insert(front);
            }
        }
        else
        {
            other.insert(p);
        }
    }
    void removeFromSet(const pair<int, int> &p)
    {
        if (main.find(p) != main.end())
        {
            sum -= (1LL * p.first * p.second); // removing from main
            main.erase(p);

            if (!other.empty())
            {
                auto back = *other.rbegin(); // remove largest from other to add to main to maintain the x size;
                other.erase(back);
                main.insert(back);
                sum += (1LL * back.first * back.second);
            }
        }
        else
        {
            other.erase(p);
        }
    }
    vector<long long> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        int l = 0, r = 0;
        vector<long long> ans;
        unordered_map<int, int> mp; // ele ->freq;

        while (r < n)
        {
            if (mp[nums[r]] > 0)
            {
                removeFromSet({mp[nums[r]], nums[r]});
            }
            mp[nums[r]]++;
            insertInSet({mp[nums[r]], nums[r]}, x);

            if (r - l + 1 == k)
            {
                ans.push_back(sum);

                removeFromSet({mp[nums[l]], nums[l]});
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                else
                {
                    insertInSet({mp[nums[l]], nums[l]}, x);
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};

// TC: O(NlogN)
// Sc: O(k)