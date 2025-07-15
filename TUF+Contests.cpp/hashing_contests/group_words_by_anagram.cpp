// Group Words by Anagrams

// 0

// 100
// Easy
// Given an array of strings strs, group the words that are anagrams of each other.

// An anagram is a word formed by rearranging the letters of another word using all the original letters exactly once. You may return the groups in any order.

// Examples:
// Input: strs = ["race", "care", "acre", "bake", "beak", "keep"]

// Output: [["race", "care", "acre"], ["bake", "beak"], ["keep"]]

// Explanation:

// "race", "care", and "acre" are anagrams and can be rearranged to form each other.

// "bake" and "beak" are anagrams and form another group.

// "keep" does not have any anagrams in the list and forms its own group.

// Input: strs = ["bob", "obb", "boo", "oob", "bbo"]

// Output: [["bob", "obb", "bbo"], ["boo", "oob"]]

// Explanation:

// "bob", "obb", and "bbo" are anagrams and can be rearranged to form each other.

// "boo" and "oob" are anagrams and form another group.

// Constraints:
// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& nums) {
        vector<vector<string>>ans;
        int n = nums.size();
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<n;i++){
            string word = nums[i];
            sort(word.begin(),word.end());
            mp[word].push_back(nums[i]);
        }
        for(auto& it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
