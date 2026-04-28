// 297. Serialize and Deserialize Binary Tree

// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

// Example 1:

// Input: root = [1,2,3,null,null,4,5]
// Output: [1,2,3,null,null,4,5]
// Example 2:

// Input: root = []
// Output: []

// Constraints:

// The number of nodes in the tree is in the range [0, 10^4].
// -1000 <= Node.val <= 1000

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    TreeNode *buildTree(vector<string> &preorder, int &i)
    {
        if (preorder[i] == "null")
        {
            i++;
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(preorder[i]));
        i++;
        root->left = buildTree(preorder, i);
        root->right = buildTree(preorder, i);
        return root;
    }
    string serialize(TreeNode *root)
    {
        if (!root)
            return "null,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return NULL;
        vector<string> preorder;
        stringstream ss(data);
        string str;
        while (getline(ss, str, ','))
        {
            if (str.size())
                preorder.push_back(str);
        }
        int i = 0;
        return buildTree(preorder, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
