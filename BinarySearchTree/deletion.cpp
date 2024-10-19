
//APPROACH 1: reattach the right subtree of the node to be deleted to the rightmost node of the left subtree of the node to be deleted.
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //your code goes here
        if(root==NULL) return NULL;
        if(root->data==key){
            return helper(root);
        }
        TreeNode* temp = root;
        while(root!=NULL){
            if(root->data<=key){
                if(root->right!=NULL && root->right->data==key){
                    root->right=helper(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
            else{
                if(root->left!=NULL && root->left->data==key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
        }
        return temp;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        TreeNode* rightChild = root->right;
        TreeNode* extremeRightNode = findRightest(root->left);
        extremeRightNode->right = rightChild;
        return root->left;
    }
    TreeNode* findRightest(TreeNode* root){
        if(root->right==nullptr) return root;
        return findRightest(root->right);
    }
};

// APPROACH 2:  reattach the left subtree of the node to be deleted to the leftmost node of the right subtree of the node to be deleted.
class Solution2 {
public:
    TreeNode* deleteNode2(TreeNode* root, int key) {
        //your code goes here
        if(root==NULL) return NULL;
        if(root->data==key){
            return helper2(root);
        }
        TreeNode* temp = root;
        while(root!=NULL){
            if(root->data<=key){
                if(root->right!=NULL && root->right->data==key){
                    root->right=helper2(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
            else{
                if(root->left!=NULL && root->left->data==key){
                    root->left = helper2(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
        }
        return temp;
    }
    TreeNode* helper2(TreeNode* root){
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        TreeNode* leftchild = root->left;
        TreeNode* extremeRightNode = findLeftest(root->right);
        extremeRightNode->left = leftchild;
        return root->right;
    }
    TreeNode* findLeftest(TreeNode* root){
        if(root->left==nullptr) return root;
        return findLeftest(root->left);
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    Solution obj;
    TreeNode* res = obj.deleteNode(root, 3);
    cout << res->left->data << endl;
    Solution2 obj2;
    TreeNode* res2 = obj2.deleteNode2(root, 3);
    cout << res2->left->data << endl;
    return 0;
}