// Serialize and De-serialize BT
// Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. Ensure that a binary tree can be serialized to a string, and this string can be deserialized to the original tree structure.

// The encoded string should be as compact as possible.

// Examples:
// Input : root = [2, 1, 3]

// Output : [2, 1, 3]

// Input : root = [7, 3, 15, null, null, 9, 20]

// Output : [7, 3, 15, null, null, 9, 20]

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
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        string ans = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (!node)
                ans.append("#,");
            else
                ans.append(to_string(node->data) + ',');

            if (node)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }

    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            getline(s, str, ',');

            if (str == "#")
                node->left = NULL;
            else
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if (str == "#")
                node->right = NULL;
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

/*
 * Your Codec object will be instantiated and called as such:
 * Codec* ser = new Codec();
 * Codec* deser = new Codec();
 * string tree = ser->serialize(root);
 * TreeNode* ans = deser->deserialize(tree);
 * return ans;
 */