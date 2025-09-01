// Fruit Into Baskets

// There is only one row of fruit trees on the farm, oriented left to right. An integer array called fruits represents the trees, where fruits[i] denotes the kind of fruit produced by the ith tree.
// The goal is to gather as much fruit as possible, adhering to the owner's stringent rules:
// 1) There are two baskets available, and each basket can only contain one kind of fruit. The quantity of fruit each basket can contain is unlimited.
// 2) Start at any tree, but as you proceed to the right, select exactly one fruit from each tree, including the starting tree. One of the baskets must hold the harvested fruits.
// 3) Once reaching a tree with fruit that cannot fit into any basket, stop.
// Return the maximum number of fruits that can be picked.

// Examples:
// Input : fruits = [1, 2, 1]
// Output : 3
// Explanation : We will start from first tree.
// The first tree produces the fruit of kind '1' and we will put that in the first basket.
// The second tree produces the fruit of kind '2' and we will put that in the second basket.
// The third tree produces the fruit of kind '1' and we have first basket that is already holding fruit of kind '1'. So we will put it in first basket.
// Hence we were able to collect total of 3 fruits.

// Input : fruits = [1, 2, 3, 2, 2]
// Output : 4
// Explanation : we will start from second tree.
// The first basket contains fruits from second , fourth and fifth.
// The second basket will contain fruit from third tree.
// Hence we collected total of 4 fruits.

#include <bits/stdc++.h>
using namespace std;

// brute - Generate all subarray with atmost 2 distinct fruits and find the maximum length
// Time Complexity: O(n^2)
// Space Complexity: O(3) //as set can take at most 3 elements

class Solution
{
public:
    int totalFruits(vector<int> &fruits)
    {
        int n = fruits.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> st;
            for (int j = i; j < n; j++)
            {
                st.insert(fruits[j]);

                if (st.size() <= 2)
                {
                    ans = max(ans, j - i + 1);
                }
                else
                    break;
            }
        }
        return ans;
    }
};

// Better - Use Sliding window and keep moving window till taken fruits are not 2
// Time Complexity: O(2n)
// Space Complexity: O(1)
class Solution
{
public:
    int totalFruits(vector<int> &fruits)
    {
        int n = fruits.size();
        int l = 0, r = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        while (r < n)
        {
            mp[fruits[r]]++;
            while (mp.size() > 2)
            {
                mp[fruits[l]]--;
                if (!mp[fruits[l]])
                    mp.erase(fruits[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};

// Optimal - Use Sliding window  but instead of extra O(n) of moving, just move by one place and move on
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
    int totalFruits(vector<int> &fruits)
    {
        int n = fruits.size();
        int l = 0, r = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        while (r < n)
        {
            mp[fruits[r]]++;
            if (mp.size() > 2)
            {
                mp[fruits[l]]--;
                if (!mp[fruits[l]])
                    mp.erase(fruits[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};