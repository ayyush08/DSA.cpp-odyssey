// Inorder successor and predecessor in BST

// Given the root node of a binary search tree (BST) and an integer key. Return the Inorder predecessor and successor of the given key from the provided BST.

// Note: key will always present in given BST.

// If predecessor or successor is missing then return -1.

// Examples:
// Input : root = [5, 2, 10, 1, 4, 7, 12] , key = 10

// Output : [7, 12]

// Explanation :

// Input : root = [5, 2, 10, 1, 4, 7, 12] , key = 12

// Output : [10, -1]

// Submit
// Constraints:
// 1 <= Number of Nodes <= 104
// 1 <= Node.val <= 105
// All the values Node.val are unique.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Brute - store inorder traversal in array and then find predecessor and successor from array using binary search for given key.
// Time Complexity : O(N) + (logN) ~= O(N)
// Space Complexity : O(N)+O(H) for recursion stack ~= O(N)

// Better Approach :  Maintain a previous Node pointer while traversing inorder to find predecessor and successor in single traversal.

class Solution
{
public:
    vector<int> ans = {-1, -1};
    void solve(TreeNode *root, int key, TreeNode *&prev)
    {
        if (!root)
            return;
        solve(root->left, key, prev);
        if (prev && prev->data < key)
        {
            ans[0] = prev->data; // any node less than key in inorder traversal is predecessor(keeps updating to get the last one)
        }
        if (root->data > key)
        {
            if (ans[1] == -1)
                ans[1] = root->data; // first node greater than key in inorder traversal is successor
        }
        prev = root;
        solve(root->right, key, prev);
    }
    vector<int> succPredBST(TreeNode *root, int key)
    {
        TreeNode *prev = NULL;
        solve(root, key, prev);
        return ans;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(H) for recursion stack

// Optimal Approach : Using BST properties to find predecessor and successor in single traversal.

class Solution
{
public:
    int getSuccessor(TreeNode *root, int key)
    {
        TreeNode *successor = NULL;
        while (root)
        {
            if (key >= root->data) //anything less than or equal to key cannot be successor
                root = root->right;
            else
            {
                successor = root;//potential successor
                root = root->left; //move left to find nearest successor
            }
        }
        return successor ? successor->data : -1;
    }
    int getPredecessor(TreeNode *root, int key)
    {
        TreeNode *predecessor = NULL;
        while (root)
        {
            if (key <= root->data) // anything greater than or equal to key cannot be predecessor
                root = root->left; 
            else
            {
                predecessor = root; //potential predecessor
                root = root->right; //move right to find nearest predecessor
            }
        }
        return predecessor ? predecessor->data : -1;
    }
    vector<int> succPredBST(TreeNode *root, int key)
    {
        TreeNode *prev = NULL;
        return {getPredecessor(root, key), getSuccessor(root, key)};
    }
};
//Time Complexity : O(H) where H is height of BST
//Space Complexity : O(1)