// Check for balanced binary tree
// Given a binary tree root, find if it is height-balanced or not.
// A tree is height-balanced if the difference between the heights of left and right subtrees is not more than one for all nodes of the tree.

// Example 1
// Input : [3, 9, 20, null, null, 15, 7]
// Output : Yes
// Example 2
// Input : [1, 2, null, null, 3]
// Output : No

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Brute Force Approach O(n^2)
class Solution
{
public:
    int getHeight(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        if (abs(rightHeight - leftHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        {
            return true;
        }
        return false;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    cout << obj.isBalanced(root) << endl;
    return 0;
}

// Optimal Approach O(n)

class Solution
{
public:
    int check(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = check(root->left);
        if (left == -1)
            return -1;
        int right = check(root->right);
        if (right == -1)
            return -1;
        int diff = abs(right - left);
        return diff <= 1 ? 1 + max(left, right) : -1;
    }
    bool isBalanced(TreeNode *root)
    {
        return check(root) != -1;
    }
};