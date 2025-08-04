// Palindrome partitioning

// Given a string s partition string s such that every substring of partition is palindrome. Return all possible palindrome partition of string s.

// Examples:
// Input : s = "aabaa"

// Output : [ [ "a", "a", "b", "a", "a"] , [ "a", "a", "b", "aa"] , [ "a", "aba", "a"] , [ "aa", "b", "a", "a"] , [ "aa", "b", "aa" ] , [ "aabaa" ] ]

// Explanation : Above all are the possible ways in which the string can be partitioned so that each substring is a palindrome.

// Input : s = "baa"

// Output : [ [ "b", "a", "a"] , [ "b", "aa" ] ]

// Explanation : Above all are the possible ways in which the string can be partitioned so that each substring is a palindrome.

// Input : s = "ab"

// Output:
// [ [ "a"] , [ "b"] ]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s, int start, int end)
    {

        while (start <= end)
        {

            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
    void func(int partition, string s, vector<string> &temp, vector<vector<string>> &ans)
    {
        if (partition == s.size())
        {
            ans.push_back(temp);
            return;
        }
        for (int i = partition; i < s.size(); i++)
        {
            if (isPalindrome(s, partition, i))
            {
                temp.push_back(s.substr(partition, i - partition + 1));
                func(i + 1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        // your code goes here
        vector<string> temp;
        vector<vector<string>> ans;
        func(0, s, temp, ans);
        return ans;
    }
};


// Time Complexity:O(N * 2^N), where N is the length of the string. This is because, in the worst case, there can be 2^(N-1) possible partitions, and for each partition, we need to verify if it is a palindrome which takes O(N) time.
// Space Complexity:O(N), due to the recursion depth and the space used to store the temporary list of string partitions.