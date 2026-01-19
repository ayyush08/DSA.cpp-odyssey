// 3816. Lexicographically Smallest String After Deleting Duplicate Characters
// You are given a string s that consists of lowercase English letters.

// You can perform the following operation any number of times (possibly zero times):

// Choose any letter that appears at least twice in the current string s and delete any one occurrence.
// Return the lexicographically smallest resulting string that can be formed this way.

// Example 1:

// Input: s = "aaccb"

// Output: "aacb"

// Explanation:

// We can form the strings "acb", "aacb", "accb", and "aaccb". "aacb" is the lexicographically smallest one.

// For example, we can obtain "aacb" by choosing 'c' and deleting its first occurrence.

// Example 2:

// Input: s = "z"

// Output: "z"

// Explanation:

// We cannot perform any operations. The only string we can form is "z".

// Constraints:

// 1 <= s.length <= 105
// s contains lowercase English letters only.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string lexSmallestAfterDeletion(string s)
    {
        vector<int> count(26, 0), ex(26, 0);
        for (char c : s)
            count[c - 'a']++;
        string ans;
        for (char c : s)
        {
            int i = c - 'a';
            count[i]--;
            while (!ans.empty())
            {
                int j = ans.back() - 'a';
                if (ans.back() > c && (count[j] > 0 || ex[j] > 1))
                {
                    ex[j]--;
                    ans.pop_back();
                }
                else
                    break;
            }
            ans += c;
            ex[i]++;
        }
        while (!ans.empty() && ex[ans.back() - 'a'] > 1)
        {
            ex[ans.back() - 'a']--;
            ans.pop_back();
        }
        return ans;
    }
};

//Time Complexity: O(N)
//Space Complexity: O(1)

//Approach:
//We maintain two arrays count and ex of size 26 to store the frequency of each character.
//We iterate through the string s and for each character c, we decrement its count in the count array.
//We then check if we can pop characters from the end of the answer string ans to make it lexicographically smaller.
//We can pop a character from ans if it is greater than c and it appears later in the string (i.e., its count in the count array is greater than 0) or if it appears more than once in ans (i.e., its count in the ex array is greater than 1).
//If we can pop a character, we decrement its count in the ex array and remove it from ans.
//We then add c to ans and increment its count in the ex array. 