
// https://leetcode.com/problems/longest-balanced-substring-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ans = 0;
    void checkSingle(string &s)
    {
        int n = s.size();
        int i = 0;
        while (i < n)
        {
            int j = i;
            while (j < n && s[i] == s[j])
                j++;
            ans = max(ans, j - i);
            i = j;
        }
    }
    void checkDouble(string &s, char x, char y, char skip)
    {
        int n = s.size();
        unordered_map<int, int> lastSeen;
        int cnt = 0;
        lastSeen[0] = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == skip)
            {
                cnt = 0;
                lastSeen.clear();
                lastSeen[0] = i;
                continue;
            }
            cnt += (s[i] == x ? 1 : -1);
            if (lastSeen.count(cnt))
            {
                ans = max(ans, i - lastSeen[cnt]);
            }
            else
            {
                lastSeen[cnt] = i;
            }
        }
    }
    void checkTriple(string &s)
    {
        int n = s.size();
        int cntA = 0;
        int cntB = 0;
        int cntC = 0;
        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
                cntA++;
            else if (s[i] == 'b')
                cntB++;
            else
                cntC++;

            int ab = cntA - cntB;
            int ac = cntA - cntC;

            pair<int, int> p = {ab, ac};
            if (mp.count(p))
            {
                ans = max(ans, i - mp[p]);
            }
            else
                mp[p] = i;
        }
    }
    int longestBalanced(string s)
    {
        checkSingle(s);
        checkDouble(s, 'a', 'b', 'c');
        checkDouble(s, 'a', 'c', 'b');
        checkDouble(s, 'b', 'c', 'a');
        checkTriple(s);
        return ans;
    }
};


int main()
{
    Solution sol;
    string s = "abcabc";
    cout << sol.longestBalanced(s) << endl; // Output: 6
    return 0;
}