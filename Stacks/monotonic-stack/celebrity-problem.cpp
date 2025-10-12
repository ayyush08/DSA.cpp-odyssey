// Celebrity Problem

// A celebrity is a person who is known by everyone else at the party but does not know anyone in return. Given a square matrix M of size N x N where M[i][j] is 1 if person i knows person j, and 0 otherwise, determine if there is a celebrity at the party. Return the index of the celebrity or -1 if no such person exists.

// Note that M[i][i] is always 0.

// Examples:
// Input: M = [ [0, 1, 1, 0], [0, 0, 0, 0], [1, 1, 0, 0], [0, 1, 1, 0] ]

// Output: 1

// Explanation: Person 1 does not know anyone and is known by persons 0, 2, and 3. Therefore, person 1 is the celebrity.

// Input: M = [ [0, 1], [1, 0] ]

// Output: -1

// Explanation: Both persons know each other, so there is no celebrity.

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach: O(n^2) - track who knows how many people and who is known by how many people

class Solution
{
public:
    int celebrity(vector<vector<int>> &M)
    {
        int n = M.size();
        vector<int> knowsme(n, 0);
        vector<int> iknow(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (M[i][j])
                {
                    knowsme[j]++;
                    iknow[i]++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (knowsme[i] == n - 1 && iknow[i] == 0)
                return i;
        }
        return -1;
    }
};

// Better Approach: O(2N) use top and down pointer to find a potential celebrity and then verify

class Solution2
{
public:
    int celebrity(vector<vector<int>> &M)
    {
        int n = M.size();
        int top = 0, down = n - 1;

        while (top < down)
        {
            if (M[top][down])
                top++;
            else if (M[down][top])
                down--;
            else
            {
                top++;
                down--;
            }
        }

        if (top > down)
            return -1;
        for (int i = 0; i < n; i++)
        {
            if (i == top)
                continue;
            if (M[top][i] != 0 || M[i][top] != 1) // celeb should not know anyone and everyone should know celeb
                return -1;
        }
        return top;
    }
};

// Optimal Approach: O(n) - use stack to find a potential celebrity using pairwise comparison and then verify
class Solution3
{
public:
    int celebrity(vector<vector<int>> &M)
    {
        int n = M.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
            st.push(i);
        while (st.size() > 1)
        {
            int i = st.top();
            st.pop();
            int j = st.top();
            st.pop();
            if (M[i][j])
                st.push(j);
            else
                st.push(i);
        }
        int top = st.top();
        for (int i = 0; i < n; i++)
        {
            if (i == top)
                continue;
            if (M[top][i] != 0 || M[i][top] != 1)
                return -1;
        }
        return top;
    }
};
