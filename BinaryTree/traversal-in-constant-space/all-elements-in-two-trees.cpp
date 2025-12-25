// 1305. All Elements in Two Binary Search Trees
// Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

// Example 1:

// Input: root1 = [2,1,4], root2 = [1,0,3]
// Output: [0,1,1,2,3,4]
// Example 2:

// Input: root1 = [1,null,8], root2 = [8,1]
// Output: [1,1,8,8]

// Constraints:

// The number of nodes in each tree is in the range [0, 5000].
// -105 <= Node.val <= 105

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int getInorder(TreeNode *&root) //pass root by reference to maintain state across calls
    {
        if (!root)
            return INT_MAX; // Return INT_MAX when tree is exhausted
        while (root) //use root itself instead of curr (like in our usual morris) to maintain the state across calls
        {
            if (!root->left)
            {
                int val = root->val;
                root = root->right;
                return val; //return when there is no left subtree
            }
            else
            {
                TreeNode *prev = root->left;
                while (prev->right && prev->right != root)
                    prev = prev->right;
                if (!prev->right)
                {
                    prev->right = root;
                    root = root->left;
                }
                else
                {
                    prev->right = NULL;
                    int val = root->val;
                    root = root->right;
                    return val; //return when returning from left subtree
                }
            }
        }
        return root->val;
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> ans;

        int temp1 = getInorder(root1);
        int temp2 = getInorder(root2);

        while (temp1 != INT_MAX || temp2 != INT_MAX)
        {
            if (temp1 < temp2)
            {
                ans.push_back(temp1);
                temp1 = getInorder(root1); //get next from tree1
            }
            else
            {
                ans.push_back(temp2);
                temp2 = getInorder(root2); //get next from tree2
            }
        }
        return ans;
    }
};