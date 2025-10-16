// 117. Populating Next Right Pointers in Each Node II

// Given a binary tree
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.

// Example 1:
// Input: root = [1,2,3,4,5,null,7]
// Output: [1,#,2,3,#,4,5,7,#]
// Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

// Example 2:[]
// Input: root = []
// Output: []

// Constraints:
// The number of nodes in the tree is in the range [0, 6000].
// -100 <= Node.val <= 100

// Follow-up:
// You may only use constant extra space.
// The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.

#include <bits/stdc++.h>
using namespace std;

// BFS Approach - Works for all Binary Trees ( i guess )

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;

        queue<Node *> q;
        q.push(root);

        while (q.size())
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                Node *node = q.front();
                q.pop();
                if (i != s - 1)
                    node->next = q.front();
                else
                    node->next = NULL;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return root;
    }
};

// DFS Approach - constant space

class Solution
{
public:
    Node *getNextest(Node *root)
    {
        if (!root)
            return root;
        Node *next = root->next;
        while (next)
        {
            if (next->left)
                return next->left;
            if (next->right)
                return next->right;
            next = next->next;
        }
        return NULL;
    }
    Node *connect(Node *root)
    {
        if (!root)
            return root;

        Node *nextest = getNextest(root);

        if (root->left)
            root->left->next = root->right ? root->right : nextest;
        if (root->right)
            root->right->next = nextest;

        connect(root->right);
        connect(root->left);
        return root;
    }
};