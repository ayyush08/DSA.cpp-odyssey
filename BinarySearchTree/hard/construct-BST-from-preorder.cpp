// Construct a BST from a preorder traversal
// Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

// It is guaranteed that it is always possible to find a binary search tree with the given requirements for the given test cases.

// Note : As there can be many possible correct answers, the compiler outputs true if the solution is correct, else false.

// Examples:
// Input : preorder = [8, 5, 1, 7, 10, 12]

// Output : [8, 5, 10, 1, 7, null, 12]

// Explanation :

// Below is the BST image

// Input : preorder = [1, 3]

// Output : [1, null, 3]

// Submit
// Constraints:
// 1 <= preorder.length <= 100
// 1 <= preorder[i] <= 1000
// All the values of preorder are unique.


//Brute Force Approach :  keep construcing the BST by inserting each element one by one as per BST property. TIme Complexity : O(N^2) in worst case when tree is skewed.

//Better Approach : sort the preorder to get inorder traversal and then construct the tree using preorder and inorder. Time Complexity : O(NlogN) due to sorting.

//Optimal Approach : Using upper bound concept we can construct the BST in O(N) time.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *build(vector<int> &preorder, int &i, int upperBound)
    {
        if (i == preorder.size() || preorder[i] > upperBound)
            return NULL;
        TreeNode *root = new TreeNode(preorder[i]);
        i++;
        root->left = build(preorder, i, root->data);
        root->right = build(preorder, i, upperBound);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
};