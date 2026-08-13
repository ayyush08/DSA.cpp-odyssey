// 2213. Longest Substring of One Repeating Character
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of length k and a 0-indexed array of integer indices queryIndices of length k, both of which are used to describe k queries.

// The ith query updates the character in s at index queryIndices[i] to the character queryCharacters[i].

// Return an array lengths of length k where lengths[i] is the length of the longest substring of s consisting of only one repeating character after the ith query is performed.

// Example 1:

// Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
// Output: [3,3,4]
// Explanation:
// - 1st query updates s = "bbbacc". The longest substring consisting of one repeating character is "bbb" with length 3.
// - 2nd query updates s = "bbbccc".
//   The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
// - 3rd query updates s = "bbbbcc". The longest substring consisting of one repeating character is "bbbb" with length 4.
// Thus, we return [3,3,4].
// Example 2:

// Input: s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
// Output: [2,3]
// Explanation:
// - 1st query updates s = "abazz". The longest substring consisting of one repeating character is "zz" with length 2.
// - 2nd query updates s = "aaazz". The longest substring consisting of one repeating character is "aaa" with length 3.
// Thus, we return [2,3].

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.
// k == queryCharacters.length == queryIndices.length
// 1 <= k <= 105
// queryCharacters consists of lowercase English letters.
// 0 <= queryIndices[i] < s.length


#include<bits/stdc++.h>
using namespace std;


struct Node {
    int prefix; //left repeats
    int suffix; //right repeats
    int ans; //longest repeat
    int len; //length of segment
    char preChar; //prefix's repeating char
    char suffChar; //suffix's repeating char
};
 struct SegmentTree {
    vector<Node> tree;

    void init(int n) { tree.assign(4 * n, {}); }
    Node merge(Node left,Node right){
        Node merged;

        merged.len = left.len+right.len;
        merged.preChar = left.preChar;
        merged.suffChar = right.suffChar;

        merged.prefix = left.prefix;
        merged.suffix =  right.suffix;

        merged.ans = max(left.ans,right.ans);

        if(left.suffChar  == right.preChar){
            merged.ans = max(merged.ans,left.suffix+right.prefix);
            
            //left can join right
            if(left.prefix == left.len) merged.prefix = left.len+right.prefix; 

            //right can join left
            if(right.suffix == right.len) merged.suffix = right.len+left.suffix;

         }

         return merged;
    }
    void build(string &s, int left, int right, int idx) {
        if (left == right) {
            tree[idx].prefix = 1;
            tree[idx].suffix = 1;
            tree[idx].ans = 1;
            tree[idx].len = 1;
            tree[idx].preChar = s[left];
            tree[idx].suffChar = s[left];
            return;
        }
        int mid = (left + right) >> 1;
        build(s, left, mid, 2 * idx + 1);
        build(s, mid + 1, right, 2 * idx + 2);
        tree[idx] = merge(tree[2 * idx + 1], tree[2 * idx + 2]);
    }
    void update(int start, int end, int idx, char val, int node) {
        if (start == end) {
            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].ans = 1;
            tree[node].len = 1;
            tree[node].preChar = val;
            tree[node].suffChar = val;
            return;
        }
        int mid = (start + end) >> 1;
        if (idx <= mid) {
            update(start, mid, idx, val, 2 * node + 1);
        } else {
            update(mid + 1, end, idx, val, 2 * node + 2);
        }
        tree[node] =  merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

};
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters,vector<int>& queryIndices) {
        SegmentTree segTree;
        int n = s.size();
        segTree.init(n);
        segTree.build(s,0,n-1,0);

        vector<int> ans;

        for(int i=0;i<queryCharacters.size();i++){
            char ch = queryCharacters[i];
            int idx = queryIndices[i];

            segTree.update(0,n-1,idx,ch,0);

            ans.push_back(segTree.tree[0].ans);
        }

        return ans;
    }
};

//Time Complexity: O(n + k log n) where n is the length of the string and k is the number of queries. Building the segment tree takes O(n) time, and each update/query takes O(log n) time, leading to a total of O(k log n) for k queries.

//Space Complexity: O(n) for the segment tree, which requires space proportional to the size of the input string.