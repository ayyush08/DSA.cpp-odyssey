// Subsets I
// Given an array nums of n integers.Return sum of all subsets of the array nums.
// Output can be printed in any order.

// Example 1
// Input : nums = [2, 3]
// Output : [0, 2, 3, 5]

// Explanation :
// When no elements is taken then Sum = 0
// When only 2 is taken then Sum = 2.
// When only 3 is taken then Sum = 3.
// When element 2 and 3 are taken then sum = 2+3 = 5.

// Example 2
// Input : nums = [5, 2, 1]

// Output : [0, 1, 2, 3, 5, 6, 7, 8]
// Explanation :
// When no elements is taken then Sum = 0.
// When only 5 is taken then Sum = 5.
// When only 2 is taken then Sum = 2.
// When only 1 is taken then Sum = 1.
// When element 2 and 1 are taken then sum = 2+1 = 3.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void func(int ind, vector<int> &ans, vector<int> &nums, int sum)
    {
        if (ind == nums.size())
        {
            ans.push_back(sum);
            return;
        }
        func(ind + 1, ans, nums, sum + nums[ind]);
        func(ind + 1, ans, nums, sum);
    }
    vector<int> subsetSums(vector<int> &nums)
    {
        // your code goes here
        vector<int> ans;
        func(0, ans, nums, 0);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution ob;
    vector<int> ans = ob.subsetSums(nums);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}