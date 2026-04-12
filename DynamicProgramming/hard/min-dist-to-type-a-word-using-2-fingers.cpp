// 1320. Minimum Distance to Type a Word Using Two Fingers

// You have a keyboard layout as shown above in the X-Y plane, where each English uppercase letter is located at some coordinate.

// For example, the letter 'A' is located at coordinate (0, 0), the letter 'B' is located at coordinate (0, 1), the letter 'P' is located at coordinate (2, 3) and the letter 'Z' is located at coordinate (4, 1).
// Given the string word, return the minimum total distance to type such string using only two fingers.

// The distance between coordinates (x1, y1) and (x2, y2) is |x1 - x2| + |y1 - y2|.

// Note that the initial positions of your two fingers are considered free so do not count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.

// Example 1:

// Input: word = "CAKE"
// Output: 3
// Explanation: Using two fingers, one optimal way to type "CAKE" is:
// Finger 1 on letter 'C' -> cost = 0
// Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2
// Finger 2 on letter 'K' -> cost = 0
// Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1
// Total distance = 3
// Example 2:

// Input: word = "HAPPY"
// Output: 6
// Explanation: Using two fingers, one optimal way to type "HAPPY" is:
// Finger 1 on letter 'H' -> cost = 0
// Finger 1 on letter 'A' -> cost = Distance from letter 'H' to letter 'A' = 2
// Finger 2 on letter 'P' -> cost = 0
// Finger 2 on letter 'P' -> cost = Distance from letter 'P' to letter 'P' = 0
// Finger 1 on letter 'Y' -> cost = Distance from letter 'A' to letter 'Y' = 4
// Total distance = 6

// Constraints:

// 2 <= word.length <= 300
// word consists of uppercase English letters.

#include <bits/stdc++.h>
using namespace std;

// Approach 1: 5D DP
//  Time Complexity: O(n*26*26) where n is the length of the input

class Solution
{
public:
    int dp[301][7][7][7][7];

    pair<int, int> getCoordinate(char ch)
    {
        int pos = ch - 'A';
        return {pos / 6, pos % 6};
    }

    int getDistance(int x1, int y1, int x2, int y2)
    {
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(string &word, int i, int x1, int y1, int x2, int y2)
    {
        if (i == word.size())
            return 0;

        if (dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] != -1)
            return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1];

        auto [x, y] = getCoordinate(word[i]);

        // Case 1: first finger not used
        if (x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1)
        {
            // using finger 1
            return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] = solve(word, i + 1, x, y, x2, y2); // Choose any finger (1 or 2), both symmetric
        }

        // Case 2: second finger not used
        if (x2 == -1 && y2 == -1)
        {
            int moveF2 = solve(word, i + 1, x1, y1, x, y);

            int moveF1 = solve(word, i + 1, x, y, x2, y2) + getDistance(x1, y1, x, y);

            return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] = min(moveF1, moveF2);
        }

        // Case 3: both fingers used
        int moveF1 = solve(word, i + 1, x, y, x2, y2) + getDistance(x1, y1, x, y);

        int moveF2 = solve(word, i + 1, x1, y1, x, y) + getDistance(x2, y2, x, y);

        return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] = min(moveF1, moveF2);
    }

    int minimumDistance(string word)
    {
        // finger1 = (x1, y1)
        // finger2 = (x2, y2)
        memset(dp, -1, sizeof(dp));
        return solve(word, 0, -1, -1, -1, -1);
    }
};

// Approach 2: 3D DP

class Solution {
public:
    vector<vector<vector<int>>>dp;
    pair<int, int> getCoord(int pos) {
        return {pos/6, pos%6};
    }
    int getDistance(int pos1, int pos2) {
        auto[x1, y1] = getCoord(pos1);
        auto[x2, y2] = getCoord(pos2);
        return abs(x1 - x2) + abs(y1-y2);
    }
    int solve(string &word, int i, int finger1,int finger2) {
        if (i == word.size()) 
            return 0;

        if (dp[i][finger1][finger2] != -1) return dp[i][finger1][finger2];

        int curr = word[i]-'A';

        if(finger1==26 && finger2==26){

            return dp[i][finger1][finger2] = solve(word,i+1,curr,finger2);
        }

        if(finger2==26){
            int moveFinger2 = solve(word,i+1,finger1,curr);
            int moveFinger1 = getDistance(finger1,curr) + solve(word,i+1,curr,finger2);

            return dp[i][finger1][finger2] = min(moveFinger1,moveFinger2);
        }

        int moveFinger1 = getDistance(finger1,curr) + solve(word,i+1,curr,finger2);
        int moveFinger2 = getDistance(finger2,curr) + solve(word,i+1,finger1,curr);

        return dp[i][finger1][finger2] = min(moveFinger1,moveFinger2);
        
    }

    int minimumDistance(string word) {
        int n = word.size();
        dp.assign(n,vector<vector<int>>(27,vector<int>(27,-1)));
        return solve(word, 0, 26,26);
    }
};