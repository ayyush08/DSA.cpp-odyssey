// Letter Combinations of a Phone Number
// Given a string consisting of digits from 2 to 9 (inclusive). Return all possible letter combinations that the number can represent.

// Mapping of digits to letters is given in first example.

// Examples:
// Input : digits = "34"

// Output : [ "dg", "dh", "di", "eg", "eh", "ei", "fg", "fh", "fi" ]

// Explanation : The 3 is mapped with "def" and 4 is mapped with "ghi".

// So all possible combination by replacing the digits with characters are shown in output.


// Input : digits = "3"

// Output : [ "d", "e", "f" ]

// Explanation : The 3 is mapped with "def".

// Input : digits = "8"

// Output:
// [ "t", "u", "v" ]



#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void fun(int btn, vector<string> &ans, string temp, string digits, string combos[])
    {
        if (btn == digits.size())
        {
            ans.push_back(temp);
            return;
        }
        int num = digits[btn] - '0';

        for (int i = 0; i < combos[num].size(); i++)
        {
            fun(btn + 1, ans, temp + combos[num][i], digits, combos);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        string combos[] = {"", "", "abc", "def", "ghi",
                           "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;

        fun(0, ans, "", digits, combos);
        return ans;
    }
};