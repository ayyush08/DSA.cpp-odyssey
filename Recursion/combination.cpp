// 77. Combinations
// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

// You may return the answer in any order.

// Example 1:

// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
// Example 2:

// Input: n = 1, k = 1
// Output: [[1]]
// Explanation: There is 1 choose 1 = 1 total combination.

// Constraints:

// 1 <= n <= 20
// 1 <= k <= n

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int end;
    void solve(int start, vector<vector<int>> &ans, vector<int> &temp, int n, int k)
    {
        if (n > end)
            return;
        if (temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            temp.push_back(i);
            solve(i + 1, ans, temp, n, k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        end = n;
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, ans, temp, n, k);
        return ans;
    }
};