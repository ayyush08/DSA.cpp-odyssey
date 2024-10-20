// Given the root node of a binary search tree (BST) and two node values p,q.
// Return the lowest common ancestors(LCA) of the two nodes in BST.
// Example 1
// Input : root = [5, 3, 6, 2, 4, null, 7] , p = 2, q = 4
// Output : [3]
// Example 2
// Input : root = [5, 3, 6, 2, 4, null, 7] , p = 2, q = 7
// Output : [5]

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// BRUTE FORCE : recursively find the LCA of p and q in the left and right subtree. If root is null or the current node is either p or q, then return the current node as the LCA. If both are not null, then return the current node as the LCA. If one of them is null, then return the other one as the LCA. This way we keep track of common ancestor of p and q whilst also traversing and checking for the LCA in the left and right subtree.
//  Time complexity of this approach is O(n) where n is the number of nodes in the tree. Space complexity is O(n) due to recursion stack.

class Solution
{
public:
    TreeNode *findLCA(TreeNode *root, int p, int q)
    {
        if (root == NULL || root->data == p || root->data == q)
        {
            return root;
        }
        TreeNode *leftLCA = findLCA(root->left, p, q);
        TreeNode *rightLCA = findLCA(root->right, p, q);
        if (leftLCA && rightLCA)
            return root;
        return (leftLCA != nullptr) ? leftLCA : rightLCA;
    }
    TreeNode *lca(TreeNode *root, int p, int q)
    {
        // your code goes here
        return findLCA(root, p, q);
    }
};


// OPTIMIZED : We can optimize the above approach by using the property of BST. If the current node value is greater than both p and q, then the LCA lies in the left subtree. If the current node value is less than both p and q, then the LCA lies in the right subtree. If the current node value is between p and q, then the current node is the LCA. Time complexity of this approach is O(n) where n is the number of nodes in the tree. Space complexity is O(1) as we are not using any extra space.

class Solution2{	
	public:
		TreeNode* lca(TreeNode* root, int p, int q){
	        //your code goes here
			if(p>q) swap(p,q);
			while(root!=NULL){
				if(root->data>q){
					root=root->left;
				}
				else if(root->data<p){
					root=root->right;
				}
				else{
					return root;
				}
			}
			return nullptr;
		}
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    Solution obj;
    cout << obj.lca(root, 2, 4)->data << endl;
    Solution2 obj2;
    cout << obj2.lca(root, 2, 7)->data << endl;
    return 0;
}