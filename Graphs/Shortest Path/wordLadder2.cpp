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

// APPROACH - We will use a Breadth-First Search (BFS) approach to find the shortest transformation sequences.
//  We will use a queue to store the current sequence of words and a set to keep track of the words that have been used at the current level of BFS.
//  For each word in the queue, we will generate all possible transformations by changing one letter at a time and check if the transformed word is in the word list.
//  If it is, we will add the transformed word to the current sequence and push the new sequence to the queue.
//  We will also keep track of the level of BFS and erase the words that have been used at the current level from the word list to avoid cycles.
//  If we reach the target word, we will add the current sequence to the answer list.
//  We will continue this process until the queue is empty.

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


// Time Complexity: O(N * M^2), where N is the number of words in the word list and M is the length of each word.
// Space Complexity: O(N * M), for storing the words in the queue and the set

// This will give TLE/MLE on leetcode for large test cases.

// To optimize further, we can first collect needed steps per valid word in a map using same method as word ladder 1 with bfs, then backtrack from endWord to startWord using the map to get all sequences in dfs manner.

class Solution
{
public:
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    void dfs(string word, vector<string> &temp, string &beginWord)
    {
        if (word == beginWord)
        {
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            reverse(temp.begin(), temp.end());
            return;
        }
        int steps = mp[word];
        int size = word.size();
        for (int i = 0; i < size; i++)
        {
            char org = word[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                if (c == org)
                    continue;
                word[i] = c;
                if (mp.count(word) && mp[word] + 1 == steps)
                {
                    temp.push_back(word);
                    dfs(word, temp, beginWord);
                    temp.pop_back();
                }
            }
            word[i] = org;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord))
            return {};
        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 1;
        int size = beginWord.size();
        st.erase(beginWord);
        while (q.size())
        {
            string word = q.front();
            q.pop();
            if (word == endWord)
                break;
            int steps = mp[word];
            for (int i = 0; i < size; i++)
            {
                char org = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (c == org)
                        continue;
                    word[i] = c;
                    if (st.count(word))
                    {
                        q.push(word);
                        st.erase(word);
                        mp[word] = steps + 1;
                    }
                }
                word[i] = org;
            }
        }
        if (mp.find(endWord) != mp.end())
        {
            vector<string> temp;
            temp.push_back(endWord);
            dfs(endWord, temp, beginWord);
        }
        return ans;
    }
};

//Time Complexity: O(N * M*26), where N is the number of words in the word list and M is the length of each word.
//Space Complexity: O(N * M), for storing the words in the queue and the map