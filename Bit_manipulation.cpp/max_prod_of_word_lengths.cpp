// Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.

// Example 1:

// Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
// Output: 16
// Explanation: The two words can be "abcw", "xtfn".
// Example 2:

// Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
// Output: 4
// Explanation: The two words can be "ab", "cd".
// Example 3:

// Input: words = ["a","aa","aaa","aaaa"]
// Output: 0
// Explanation: No such pair of words.

// Constraints:

// 2 <= words.length <= 1000
// 1 <= words[i].length <= 1000
// words[i] consists only of lowercase English letters.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        vector<int> masks(words.size(), 0);
        for (int i = 0; i < words.size(); i++)
        {
            for (char c : words[i])
            {
                masks[i] = masks[i] | (1 << (c - 'a')); // Set the bit corresponding to the character c
            }
        }

        int ans = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if ((masks[i] & masks[j]) == 0) 
                {
                    int prod = words[i].size() * words[j].size();
                    ans = max(ans, prod);
                }
            }
        }
        return ans;
    }
};