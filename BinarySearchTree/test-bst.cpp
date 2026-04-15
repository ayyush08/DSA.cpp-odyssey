#include<bits/stdc++.h>
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

void deleteLeafNodes(TreeNode* root){
    if(!root) return;
    if(!root->left && !root->right){
        delete root;
        root = nullptr;
        return;
    }
}

bool checkIfCBT(TreeNode* root){
    if(!root) return true;
    checkIfCBT(root->left);
    checkIfCBT(root->right);
    if(root->left && !root->right) return false;
    if(root->right && !root->left) return false;
    return true;
}

bool checkHeightBalanced(TreeNode* root){
    
}


int main() {
    int nodeCount;
    cout << "Enter the number of nodes to insert: ";
    cin >> nodeCount;
    Solution obj;
    TreeNode* root = nullptr;
    for (int i = 0; i < nodeCount; i++) {
        int val;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        obj.insertIntoBST(root, val);
    }
    

    //Step1:Delete all Leaf Nodes
    deleteLeafNodes(root);
    //Step2: Check if resulting tree is a Complete Binary Tree or not (if not return -1)
    if(!checkIfCBT(root)) {
        cout << -1 << endl;
        return 0;
    }
    else{
        cout << "The tree becomes a Complete Binary Tree." << endl;
    }
    //Step3: Check if tree is Height Balanced (if not return -2)
    // Step4: Check if tree is Structurally Symmetric (if not return -3)
    // Step5: If all above contitions are satisfied return the sum of remaining leaf nodes;


    return 0;
}