// Pascal's Triangle III
// Given an integer n, return the first n (1-Indexed) rows of Pascal's triangle.

// In Pascal's triangle:

// The first row has one element with a value of 1.
// Each row has one more element in it than its previous row.
// The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.

// Examples:
// Input: n = 4

// Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1]]

// Explanation: The Pascal's Triangle is as follows:

// 1

// 1 1

// 1 2 1

// 1 3 3 1

// 1st Row has its value set to 1.

// All other cells take their value as the sum of the values directly above them

// Input: n = 5

// Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]

// Explanation: The Pascal's Triangle is as follows:

// 1

// 1 1

// 1 2 1

// 1 3 3 1

// 1 4 6 4 1

// 1st Row has its value set to 1.

// All other cells take their value as the sum of the values directly above them

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
vector<int> generateRow(int r){
    vector<int> ans(r);
        ans[0] = 1;
        for (int i = 1; i < r; i++)
        {
            ans[i] = ans[i - 1] * (r - i) / i; 
        }
        return ans;
}
public:
    vector<vector<int>> pascalTriangleIII(int n) {
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++) ans.push_back(generateRow(i));

        return ans;
    }
};