// BST iteratord

// Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):
// BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.

// boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
// int next() Moves the pointer to the right, then returns the number at the pointer.

// Notice that by initializing the pointer to a non-existent smallest number, the first call to the next() will return the smallest element in the BST.
// Assume that the next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when the next() is called.

// Examples:
// Input : [ "BSTIterator" , "next" , "next" , "hasNext" , "next" , "hasNext" , "next" , "hasNext" , "next" , "hasNext" ] , root = [7, 3, 15, null, null, 9, 20]
// Output : [3, 7, true, 9, true, 15, true, 20, false]
// Explanation :
// BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
// bSTIterator.next();  // return 3
// bSTIterator.next();  // return 7
// bSTIterator.hasNext(); // return True
// bSTIterator.next();  // return 9
// bSTIterator.hasNext(); // return True
// bSTIterator.next();  // return 15
// bSTIterator.hasNext(); // return True
// bSTIterator.next();  // return 20
// bSTIterator.hasNext(); // return False
// Input : [ "BSTIterator" , "next" , "next" , "next", "hasNext" , "next" , "hasNext" ] , root = [7, 3, 15, null, null, 9, 20]
// Output : [3, 7, 9, true, 15, true]
// Explanation :
// BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
// bSTIterator.next();  // return 3
// bSTIterator.next();  // return 7
// bSTIterator.next(); // return 9
// bSTIterator.hasNext(); // return True
// bSTIterator.next();  // return 15
// bSTIterator.hasNext(); // return True

#include <bits/stdc++.h>
using namespace std;

// Brute Force - store inorder traversal in array and use index to traverse through it.
//  Time Complexity : O(N) for inorder traversal + O(1) for next() and hasNext()
//  Space Complexity : O(N) for inorder traversal array

// Optimal Approach - Use stack to simulate inorder traversal iteratively.
//  Time Complexity : O(h) for constructor + O(1) amortized for next() and hasNext()
//  Space Complexity : O(h) for stack

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
    void pushLefts(TreeNode *node)
    {
        while (node)
        {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        pushLefts(root);
    }

    bool hasNext()
    {
        return !st.empty();
    }

    int next()
    {
        TreeNode *ans = st.top();
        st.pop();
        pushLefts(ans->right);
        return ans->data;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */