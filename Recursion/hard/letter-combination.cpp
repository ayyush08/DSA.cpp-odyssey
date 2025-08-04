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