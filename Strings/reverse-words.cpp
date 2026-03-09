// 151. Reverse Words in a String

// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

// Constraints:

// 1 <= s.length <= 104
// s contains English letters (upper-case and lower-case), digits, and spaces ' '.
// There is at least one word in s.

// Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

#include <bits/stdc++.h>
using namespace std;

// Brute-force: Store the words in a vector and then reverse the vector and join the words with a single space. TC: O(n) SC: O(n)

// Optimal: Reverse the entire string and then reverse each word in the reversed string. TC: O(n) SC: O(1)

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size();
        reverse(s.begin(), s.end());
        int i = 0, j = 0, start = 0, end = 0;
        while (j < n)
        {
            while (j < n && s[j] == ' ') //skip spaces
                j++;
            if (j == n)
                break;
            start = i;
            while (j < n && s[j] != ' ') //copy the word
            {
                swap(s[i++], s[j++]);
            }
            end = i - 1;
            reverse(s.begin() + start, s.begin() + end + 1); //reverse the word
            if (j < n)
                s[i++] = ' '; //append a single space after the word
        }
        if (i > 0 && s[i - 1] == ' ')
            i--; //remove trailing space
        return s.substr(0, i); //return the reversed string without leading and trailing spaces
    }
};