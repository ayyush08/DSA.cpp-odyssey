#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //your code goes here
        if(root==NULL) return new TreeNode(val);
        TreeNode* temp=root;
        while(temp!=NULL){
            if(temp->data<=val){
                if(temp->right!=NULL) temp=temp->right;
                else{
                    temp->right=new TreeNode(val);
                    break;              
            }
        }
        else {
            if(temp->left!=NULL) temp=temp->left;
            else{
                temp->left=new TreeNode(val);
                break;
            }
        }
    }
    return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;
    TreeNode* res = obj.insertIntoBST(root, 5);
    cout << res->right->left->data << endl;
    return 0;
}