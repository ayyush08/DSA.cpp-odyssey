// PREORDER TRAVERSAL OF BINARY TREE
#include<bits/stdc++.h>
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
    void preorder(vector<int> &data, TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        data.push_back(root->data);
        preorder(data, root->left);
        preorder(data, root->right);
    }
    vector<int> preorder(TreeNode *root)
    {
        // your code goes here
        vector<int> data;
        preorder(data, root);
        return data;
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
    vector<int> data = s.preorder(root);
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }
    return 0;
}