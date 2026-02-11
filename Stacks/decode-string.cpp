// 394. Decode String
// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed 105.

// Example 1:

// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"
// Example 2:

// Input: s = "3[a2[c]]"
// Output: "accaccacc"
// Example 3:

// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"

// Constraints:

// 1 <= s.length <= 30
// s consists of lowercase English letters, digits, and square brackets '[]'.
// s is guaranteed to be a valid input.
// All the integers in s are in the range [1, 300].

#include <bits/stdc++.h>
using namespace std;

//Two stacks - one for numbers and one for strings
//Time Complexity: O(n) where n is the length of the string

class Solution
{
public:
    string decodeString(string s)
    {
        int k = 0;
        stack<int> ks;
        stack<string> dec;
        string curr = "";
        for (char c : s)
        {
            if (isdigit(c))
                k = k * 10 + (c - '0');
            else if (c == '[')
            {
                ks.push(k);
                dec.push(curr);
                k = 0;
                curr = "";
            }
            else if (c == ']')
            {
                int repeat = ks.top();
                ks.pop();
                string str = dec.top();
                dec.pop();
                while (repeat--)
                {
                    str += curr;
                }
                curr = str;
            }
            else
                curr += c;
        }
        return curr;
    }
};

// One Stack Solution - O(n) Time and O(n) Space

class Solution
{
public:
    string decodeString(string s)
    {
        int k = 0;
        stack<pair<int, string>> st;
        string curr = "";
        for (char c : s)
        {
            if (isdigit(c))
                k = k * 10 + (c - '0');
            else if (c == '[')
            {
                st.push({k, curr});
                k = 0;
                curr = "";
            }
            else if (c == ']')
            {
                int repeat = st.top().first;
                string str = st.top().second;
                st.pop();
                while (repeat--)
                {
                    str += curr;
                }
                curr = str;
            }
            else
                curr += c;
        }
        return curr;
    }
};