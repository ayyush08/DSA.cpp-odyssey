// Clone a LL with random and next pointer

// Given the head of a special linked list of n nodes where each node contains an additional pointer called 'random' which can point to any node in the list or null.

// Construct a deep copy of the linked list where,

// n new nodes are created with corresponding values as original linked list.
// The random pointers point to the corresponding new nodes as per their arrangement in the original list.
// Return the head of the newly constructed linked list.

// Note: For custom input, a n x 2 matrix is taken with each row having 2 values:[ val, random_index] where,

// val: an integer representing ListNode.val
// random_index: index of the node (0 - n-1) that the random pointer points to, otherwise -1.

// Examples:
// Input: [[1, -1], [2, 0], [3, 4], [4, 1], [5, 2]]

// Output: 1 2 3 4 5, true

// Explanation: All the nodes in the new list have same corresponding values as original nodes.

// All the random pointers point to their corresponding nodes in the new list.

// 'true' represents that the nodes and references were created new.

// Input: [[5, -1], [3, -1], [2, 1], [1, 1]]

// Output: 5 3 2 1, true

// Explanation: All the nodes in the new list have same corresponding values as original nodes.

// All the random pointers point to their corresponding nodes in the new list.

// 'true' represents that the nodes and references were created new.

// [[5, -1], [3, -1], [2, -1], [1, -1]] will be incorrect, although it has the same values.

#include <bits/stdc++.h>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode *random;
    ListNode()
    {
        val = 0;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* r)
    {
        val = data1;
        next = next1;
        random = r;
    }
};


//Brute Force - Use Hashmap to store original and a copy of each node, then traverse again to generate the deep copy
//Time Complexity: O(2N) because the linked list is traversed twice, once for creating copies of each node and for the second time to set the next and random pointers for each copied node. The time to access the nodes in the map is O(1) due to hashing. Here N is the length of the Linked List.
//Space Complexity: O(N)+O(N) where N is the number of nodes in the linked list as all nodes are stored in the map to maintain mappings and the copied linked list takes O(N) space as well.

class Solution
{
public:
    ListNode *copyRandomList(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *temp = head;
        unordered_map<ListNode *, ListNode *> mp;
        while (temp)
        {
            ListNode *newNode = new ListNode(temp->val);
            mp[temp] = newNode;
            temp = temp->next;
        }
        temp = head;
        while (temp)
        {
            ListNode *copiedNode = mp[temp];
            copiedNode->next = mp[temp->next];
            copiedNode->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
};

//Optimized Approach - Interweave the copy nodes in between the original list then
// separate the copied list from the original list

//Time Complexity: O(N) where N is the number of nodes in the linked list as we are doing a constant amount of work for each node.
//Space Complexity: O(1) as we are not using any extra space apart from a few pointers.

class Solution2 {
public:
    ListNode* copyRandomList(ListNode* head) {
        ListNode* temp = head;
        while(temp){
            ListNode* copy = new ListNode(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }
        temp = head;
        while(temp){
            ListNode* copy = temp->next;
            if(!temp->random) copy->random=NULL;
            else copy->random = temp->random->next;
            temp=temp->next->next;
        }
        temp = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;
        while(temp){
            res->next = temp->next;
            temp->next = temp->next->next;
            res=res->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};