// Combination Sum III

// 63

// 100
// Medium

// Determine all possible set of k numbers that can be added together to equal n while meeting the following requirements:

// There is only use of numerals 1 through 9.
// A single use is made of each number.

// Return list of every feasible combination that is allowed. The combinations can be returned in any order, but the list cannot have the same combination twice.

// Examples:
// Input : k = 3 , n = 7

// Output : [ [1, 2, 4] ]

// Explanation :

// 1 + 2 + 4 = 7

// There are no other valid combinations.

// Input : k = 3, n = 9

// Output : [[1, 2, 6],[1, 3, 5],[2, 3, 4]]

// Explanation :

// 1 + 2 + 6 = 9

// 1 + 3 + 5 = 9

// 2 + 3 + 4 = 9

// There are no other valid combinations.

// Input : k = 3, n = 8

// Output:
// [ [1, 2, 3, 4] ]
// Constraints:
// 2 <= k <= 9
// 1 <= n <= 60

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void func(int sum, int k, int i, vector<vector<int>> &ans, vector<int> &temp)
    {
        if (sum == 0 && temp.size() == k) //maintain k size window
        {
            ans.push_back(temp);
            return;
        }
        if (sum <= 0 || temp.size() > k) //maintain k size window
            return;

        for (int j = i; j <= 9; j++) 
        {
            if (j <= sum) // check if j can be part of the combination
            {
                temp.push_back(j); // add j to the current combination
                func(sum - j, k, j + 1, ans, temp); // move to the next number
                temp.pop_back(); // backtrack to explore other combinations (branching)
            }
            else
                break;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        // your code goes here
        vector<vector<int>> ans;
        vector<int> temp;
        func(n, k, 1, ans, temp);
        return ans;
    }
};
