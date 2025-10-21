// Requirements needed to construct a unique BT
// Given a pair of tree traversal, return true if a unique binary tree can be constructed otherwise false. Each traversal is represented with integer: 1 -> Preorder , 2 -> Inorder , 3 -> Postorder.

// Examples:
// Input : 1 2

// Output : true

// Explanation : Answer is True.

// It is possible to construct a unique binary tree. This is because the preorder traversal provides the root of the tree, and the inorder traversal helps determine the left and right subtrees.

// Input : 2 2

// Output : false

// Explanation : Two inorder traversals are insufficient to uniquely determine a binary tree.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniqueBinaryTree(int a, int b)
    {
        return (a == 1 && b == 2 || a == 2 && b == 1) || (a == 2 && b == 3 || a == 3 && b == 2);
    }
};