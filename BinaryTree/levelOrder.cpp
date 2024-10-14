// Level Order Traversal of Binary Tree

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // your code goes here
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
                temp.push_back(node->data);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution s;
    vector<vector<int>> data = s.levelOrder(root);
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}