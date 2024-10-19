// Given the root node of a binary search tree (BST) and an integer k.
// Return the kth smallest and largest value (1-indexed) of all values of the nodes in the tree.
// Example 1
// Input : root = [3,1,4,null,2] , k = 1
// Output : [1, 4]
// Explanation : The 1st smallest value in given BST is 1.
// The 1st largest value in given BST is 4.
// Example 2
// Input : root = [5, 3, 6, 2, null, null, null, 1] , k = 3
// Output : [3, 3]
// Explanation : The 3rd smallest value in given BST is 3.
// The 3rd largest value in given BST is 3.

// BRUTE FORCE : Inorder traversal of BST gives the sorted order of elements. So, we can find the kth smallest and kth largest element by doing inorder traversal and storing the elements in a vector and then returning the kth element from the start and end of the vector.
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
    void inorder(TreeNode *root, vector<int> &data)
    {
        if (root == NULL)
            return;
        inorder(root->left, data);
        data.push_back(root->data);
        inorder(root->right, data);
    }
    vector<int> kLargesSmall(TreeNode *root, int k)
    {
        // your code goes here
        vector<int> data;
        inorder(root, data);
        sort(data.begin(), data.end());
        return {data[k - 1], data[data.size() - k]};
    }
};

// OPTIMIZED : We can do inorder traversal of BST and keep track of the count of nodes visited so far. When the count becomes equal to k, we can return the current node value as the kth smallest element. Similarly, when the count becomes equal to n-k, we can return the current node value as the kth largest element.
class Solution2 {
public:
	void inorder(TreeNode* root,int& k,int& result ){
		if(root!=NULL){
		inorder(root->left,k,result);
			if(--k==0){
				result= root->data;
				return;
			}
		inorder(root->right,k,result);
		}
	}
	void reverse_inorder(TreeNode* root,int& k,int& result ){
		if(root!=NULL){
		reverse_inorder(root->right,k,result);
			if(--k==0){
				result= root->data;
				return;
			}
		reverse_inorder(root->left,k,result);
		}
	}
	vector<int> kLargesSmall(TreeNode* root,int k){
		//your code goes here
		int kth_largest=-1;
		int kthSmallest=-1;
		int limit = k;
		inorder(root,limit,kthSmallest);
		limit=k;
		reverse_inorder(root,limit,kth_largest);
		return {kthSmallest,kth_largest};
	}
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    Solution obj;
    vector<int> res = obj.kLargesSmall(root, 1);
    cout << res[0] << " " << res[1] << endl;
    Solution2 obj2;
    vector<int> res2 = obj2.kLargesSmall(root, 1);
    cout << res2[0] << " " << res2[1] << endl;
    return 0;
}
