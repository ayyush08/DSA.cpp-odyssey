// Given a root of binary search tree and a key(node) value, find the floor and ceil value for that particular key value.
// Floor Value Node: Node with the greatest data lesser than or equal to the key value.
// Ceil Value Node: Node with the smallest data larger than or equal to the key value.
// If a particular floor or ceil value is not present then output -1.

// Example 1
// Input : root = [8, 4, 12, 2, 6, 10, 14] , key = 11
// Output : [10, 12]

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
    vector<int> floorCeilOfBST(TreeNode *root, int key)
    {
        // your code goes here
        int floor = -1;
        int ceil = -1;
        TreeNode *temp = root;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                floor = temp->data;
                break;
            }
            else if (temp->data < key)
            {
                floor = temp->data;
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        temp = root;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                ceil = temp->data;
                break;
            }
            else if (temp->data > key)
            {
                ceil = temp->data;
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return {floor, ceil};
    }
};

int main()
{
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    Solution obj;
    vector<int> res = obj.floorCeilOfBST(root, 11);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}