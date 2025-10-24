// Maximum subtree sum

// You are given a binary tree. Each node of the tree is attached with value denoted by array nums. The ith node in binary tree has nums[i] value attached to it.

// You need to output the node and sum that has maximum subtree sum.

// Examples:
// Input : nums = [1, 2, 3, 4, 5, 6], root = 1 2 3 null 4 5 6
// Output : 1 21
// Explanation :
// The 6th node subtree sum is -> 6.
// The 5th node subtree sum is -> 5.
// The 4th node subtree sum is -> 4.
// The 3rd node subtree sum is -> 3 + 5 + 6 -> 14.
// The 2nd node subtree sum is -> 2 + 4 -> 6.
// The 1st node subtree sum is -> 1 + 2 + 3 + 4 + 5 + 6 -> 21.

// Input : nums = [1, -4, 3, -2, 5, 6], root = 1 2 3 null 4 5 6
// Output : 3 14
// Explanation :
// The 6th node subtree sum is -> 6.
// The 5th node subtree sum is -> 5.
// The 4th node subtree sum is -> -2.
// The 3rd node subtree sum is -> 3 + 5 + 6 -> 14.
// The 2nd node subtree sum is -> (-4) + (-2) -> -6.
// The 1st node subtree sum is -> 1 + (-4) + 3 + (-2) + 5 + 6 -> 9.

// Constraints:
// -105<= nums[i] <=105

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *maxNode = NULL;
    int maxSum = INT_MIN;
    int solve(TreeNode *root, vector<int> &nums)
    {
        if (!root)
            return 0;
        int left = solve(root->left, nums);
        int right = solve(root->right, nums);

        int sum = nums[root->data] + left + right;

        if (sum > maxSum)
        {
            maxSum = sum;
            maxNode = root;
        }

        return sum;
    }
    vector<int> maxSubtreeSum(TreeNode *root, vector<int> &nums)
    {
        if (!root)
            return {};
        solve(root, nums);
        return {maxNode->data, maxSum};
    }
};