// Word ladder I
// Given are the two distinct words startWord and targetWord, and a list of size N, denoting wordList of unique words of equal size M. Find the length of the shortest transformation sequence from startWord to targetWord.

// Keep the following conditions in mind:
// A word can only consist of lowercase characters.
// Only one letter can be changed in each transformation.
// Each transformed word must exist in the wordList including the targetWord.
// startWord may or may not be part of the wordList

// Note: If there’s no possible way to transform the sequence from startWord to targetWord return 0.

// Examples:
// Input: wordList = ["des","der","dfr","dgt","dfs"], startWord = "der", targetWord = "dfs"
// Output: 3
// Explanation: The length of the smallest transformation sequence from "der" to "dfs" is 3 i.e. "der" -> (replace ‘e’ by ‘f’) -> "dfr" -> (replace ‘r’ by ‘s’) -> "dfs". So, it takes 3 different strings for us to reach the targetWord. Each of these strings are present in the wordList.

// Input: wordList = ["geek", "gefk"], startWord = "gedk", targetWord= "geek"
// Output: 2
// Explanation: The length of the smallest transformation sequence from "gedk" to "geek" is 2 i.e. "gedk" -> (replace ‘d’ by ‘e’) -> "geek" .
// So, it takes 2 different strings for us to reach the targetWord. Each of these strings are present in the wordList.

// Approach
// We will use the BFS approach to solve this problem. We will start from the startWord and keep changing one character at a time and check if the new word is present in the wordList. If it is present, we will add it to the queue and increment the length of the transformation sequence. We will keep doing this until we reach the targetWord. If we reach the targetWord, we will return the length of the transformation sequence. If we are not able to reach the targetWord, we will return 0.


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);

        while (!q.empty())
        {
            string word = q.front().first;
            int len = q.front().second;
            q.pop();
            if (word == targetWord)
                return len;
            for (int i = 0; i < word.size(); i++)
            {
                char originalChar = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, len + 1});
                    }
                }
                word[i] = originalChar;
            }
        }
        return 0;
    }
};

int main()
{
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
    Solution obj;
    cout << obj.wordLadderLength(startWord, targetWord, wordList);
    return 0;
}

// Time Complexity: N * M * 26
// Space Complexity: O(N) + O(M) + O(26) + O(N) = O(N)