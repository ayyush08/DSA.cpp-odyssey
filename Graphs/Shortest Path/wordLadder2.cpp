// Word ladder II
// Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.

// In this problem statement, we need to keep the following conditions in mind:
// A word can only consist of lowercase characters.
// Only one letter can be changed in each transformation.
// Each transformed word must exist in the wordList including the targetWord.
// startWord may or may not be part of the wordList.
// Return an empty list if there is no such transformation sequence.

// Examples:
// Input: startWord = "der", targetWord = "dfs", wordList = ["des", "der", "dfr", "dgt", "dfs"]
// Output: [ [ “der”, “dfr”, “dfs” ], [ “der”, “des”, “dfs”] ]
// Explanation: The length of the smallest transformation sequence here is 3.

// Following are the only two shortest ways to get to the targetWord from the startWord :
// "der" -> ( replace ‘r’ by ‘s’ ) -> "des" -> ( replace ‘e’ by ‘f’ ) -> "dfs".
// "der" -> ( replace ‘e’ by ‘f’ ) -> "dfr" -> ( replace ‘r’ by ‘s’ ) -> "dfs".

// Input: startWord = "gedk", targetWord= "geek", wordList = ["geek", "gefk"]
// Output: [ [ “gedk”, “geek” ] ]
// Explanation: The length of the smallest transformation sequence here is 2.
// Following is the only shortest way to get to the targetWord from the startWord :
// "gedk" -> ( replace ‘d’ by ‘e’ ) -> "geek".


//APPROACH - We will use a Breadth-First Search (BFS) approach to find the shortest transformation sequences. 
// We will use a queue to store the current sequence of words and a set to keep track of the words that have been used at the current level of BFS. 
// For each word in the queue, we will generate all possible transformations by changing one letter at a time and check if the transformed word is in the word list. 
// If it is, we will add the transformed word to the current sequence and push the new sequence to the queue. 
// We will also keep track of the level of BFS and erase the words that have been used at the current level from the word list to avoid cycles. 
// If we reach the target word, we will add the current sequence to the answer list. 
// We will continue this process until the queue is empty.


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                            vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        queue<vector<string>> q;
        vector<string> usedOn;
        q.push({beginWord});
        usedOn.push_back(beginWord);
        int level = 0;
        while (!q.empty())
        {
            vector<string> list = q.front();
            q.pop();
            if (list.size() > level)
            {
                level++;
                for (auto it : usedOn)
                {
                    st.erase(it);
                }
            }
            string recent = list.back();
            if (recent == endWord)
            {
                if (ans.size() == 0)
                    ans.push_back(list);
                else if (ans[0].size() == list.size())
                    ans.push_back(list);
            }
            for (int i = 0; i < recent.size(); i++)
            {
                char original = recent[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    recent[i] = c;
                    if (st.count(recent) > 0)
                    {
                        list.push_back(recent);
                        q.push(list);
                        usedOn.push_back(recent);
                        list.pop_back();
                    }
                }
                recent[i] = original;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string startWord = "der";
    string targetWord = "dfs";
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    
    vector<vector<string>> sequences = sol.findSequences(startWord, targetWord, wordList);
    
    for (const auto& seq : sequences) {
        for (const auto& word : seq) {
            cout << word << " ";
        }
        cout << endl;
    }
    
    return 0;
}