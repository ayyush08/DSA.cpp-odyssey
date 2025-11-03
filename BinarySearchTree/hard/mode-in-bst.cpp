// 501. Find Mode in Binary Search Tree
// Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

// If the tree has more than one mode, return them in any order.

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.

// Example 1:

// Input: root = [1,null,2,2]
// Output: [2]
// Example 2:

// Input: root = [0]
// Output: [0]

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -105 <= Node.val <= 105

// Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                        right(right) {}
};
class Solution
{
public:
    void check(int &cnt, int &maxFreq, int val, vector<int> &ans)
    {
        if (cnt == maxFreq)
            ans.push_back(val);
        else if (cnt > maxFreq)
        {
            maxFreq = cnt;
            ans.clear();
            ans.push_back(val);
        }
    }
    vector<int> findMode(TreeNode *root)
    {
        int last = -1;
        vector<int> ans;
        int maxFreq = 0;
        int cnt = 0;

        TreeNode *curr = root;
        //Morris Inorder Traversal for O(1) space optimization
        while (curr)
        {
            if (!curr->left)
            {

                if (curr->val == last)
                    cnt++;
                else
                {
                    last = curr->val;
                    cnt = 1;
                }
                check(cnt, maxFreq, curr->val, ans);
                curr = curr->right;
            }
            else
            {
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr)
                    prev = prev->right;
                if (!prev->right)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    if (curr->val == last)
                        cnt++;
                    else
                    {
                        last = curr->val;
                        cnt = 1;
                    }
                    check(cnt, maxFreq, curr->val, ans);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};