// 109. Convert Sorted List to Binary Search Tree
// Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

// Example 1:

// Input: head = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
// Example 2:

// Input: head = []
// Output: []

// Constraints:

// The number of nodes in head is in the range [0, 2 * 104].
// -105 <= Node.val <= 105

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    ListNode *getMiddle(ListNode *head, ListNode *tail)
    {
        if (!head)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != tail && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    TreeNode *convert(ListNode *start, ListNode *end)
    {
        if (start == end)
            return NULL;
        ListNode *mid = getMiddle(start, end);
        TreeNode *root = new TreeNode(mid->val);
        root->left = convert(start, mid);//left sorted list to left subtree
        root->right = convert(mid->next, end); //right sorted list to right subtree
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        return convert(head, NULL);
    }
};
