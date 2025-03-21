// PostOrder Traversal of a Binary Tree

#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):data(val),left(nullptr),right(nullptr){}
};

class Solution{
	public:
		void postOrder(vector<int> &data,TreeNode* root){
			if(root==nullptr){
				return;
			}
			postOrder(data,root->left);
			postOrder(data,root->right);
			data.push_back(root->data);
		}
		vector<int> postorder(TreeNode* root){
	        //your code goes here
			vector<int>data;
			postOrder(data,root);
			return data;
		}
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Solution s;
    vector<int> data = s.postorder(root);
    for(int i=0;i<data.size();i++){
        cout<<data[i]<<" ";
    }
    return 0;
}