// Alien Dictionary
// Given a sorted dictionary of an alien language having N words and K starting alphabets of a standard dictionary. Find the order of characters in the alien language.
// There may be multiple valid orders for a particular test case, thus you may return any valid order. The output will be True if the order returned by the function is correct, else False denoting an incorrect order.

// Examples:
// Input: N = 5, K = 4, dict = ["baa","abcd","abca","cab","cad"]
// Output: b d a c
// Explanation:
// We will analyze every consecutive pair to find out the order of the characters.
// The pair “baa” and “abcd” suggests ‘b’ appears before ‘a’ in the alien dictionary.
// The pair “abcd” and “abca” suggests ‘d’ appears before ‘a’ in the alien dictionary.
// The pair “abca” and “cab” suggests ‘a’ appears before ‘c’ in the alien dictionary.
// The pair “cab” and “cad” suggests ‘b’ appears before ‘d’ in the alien dictionary.
// So, [‘b’, ‘d’, ‘a’, ‘c’] is a valid ordering.

// Input: N = 3, K = 3, dict = ["caa","aaa","aab"]
// Output: c a b
// Explanation: Similarly, if we analyze the consecutive pair
// for this example, we will figure out [‘c’, ‘a’, ‘b’] is a valid ordering.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void compareAndInsert(string s1, string s2, vector<int> adj[])
    {
        int len = min(s1.length(), s2.length());
        for (int i = 0; i < len; i++)
        {
            if (s1[i] != s2[i])
            {
                adj[s1[i] - 'a'].push_back(s2[i] - 'a');
                break;
            }
        }
    }
    vector<int> topoSort(int V, vector<int> adj[])
    {
        queue<int> q;
        vector<int> ans;
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
                inDegree[it]++;
        }
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int front = q.front();
            ans.push_back(front);
            q.pop();
            for (auto it : adj[front])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        return ans;
    }

public:
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++)
        {
            compareAndInsert(dict[i], dict[i + 1], adj);
        }
        vector<int> topo = topoSort(K, adj);
        string ans;
        for (auto it : topo)
        {
            ans.push_back(it + 'a');
            ans.push_back(' ');
        }
        return ans;
    }
};
int main()
{
    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
    Solution obj;
    cout << obj.findOrder(dict, N, K) << endl;
    return 0;
}

// Time Complexity: O(K+N) (where K and N represents the number of nodes and edges in the given graph)

// Forming the graph takes O(N*len) time, where len is the average length of a word in the dictionary.
// Finding topological sort takes O(K+N) time.
// Space Complexity: O(K+N)

// Storing the graph takes O(N) space.
// Topological sorting algorithm uses extra O(K) computational space.

// Follow-up question for interview:

// When is the ordering of letters not possible:
// If every character matches and the largest word appears before the shortest word: For example, if “abcd” appears before “abc”, we can say the ordering is not possible.
// If there exists a cyclic dependency between the characters: For example, in the dictionary: dict: {“abc”, “bat”, “ade”} there exists a cyclic dependency between 'a' and 'b' because the dictionary states 'a' < 'b' < 'a', which is not possible.
