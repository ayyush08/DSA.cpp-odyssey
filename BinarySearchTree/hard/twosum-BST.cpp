// Two sum in BST

// Given the root of a binary search tree and an integer k.Return true if there exist two elements in the BST such that their sum is equal to k otherwise false.

// Examples:
// Input : root = [5, 3, 6, 2, 4, null, 7] , k = 9

// Output : true

// Explanation :

// The BST contains multiple pair of nodes that sum up to k.

// 3 + 6 => 9.

// 5 + 4 => 9.

// 2 + 7 => 9.

// Input : root = [5, 3, 6, 2, 4, null, 7] , k = 14

// Output : false

// Explanation :

// There is no pair in given BST that sum up to k.

#include <bits/stdc++.h>
using namespace std;

// brute force approach - store inorder traversal in array and use two pointer technique
//  Time Complexity : O(N) for inorder traversal + O(N) for two pointer traversal

// Optimal  Approach - use two iterators to simulate inorder and reverse inorder traversal using stack

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BSTIterator
{
private:
    stack<TreeNode *> st;
    bool reverse = true;
    void push(TreeNode *node)
    {
        while (node)
        {
            st.push(node);
            if (!reverse)
                node = node->left;
            else
                node = node->right;
        }
    }

public:
    BSTIterator(TreeNode *root, bool rev)
    {
        reverse = rev;
        push(root);
    }

    bool hasNext()
    {
        return !st.empty();
    }

    int next()
    {
        TreeNode *ans = st.top();
        st.pop();
        if (!reverse)
            push(ans->right);
        else
            push(ans->left);
        return ans->data;
    }
};

class Solution
{
public:
    bool twoSumBST(TreeNode *root, int k)
    {
        BSTIterator left(root, false);
        BSTIterator right(root, true);

        int l = left.next();
        int r = right.next();

        while (l < r)
        {
            if (l + r == k)
                return true;
            else if (l + r < k)
                l = left.next();
            else
                r = right.next();
        }
        return false;
    }
};