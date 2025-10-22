// 433. Minimum Genetic Mutation
// A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

// Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

// For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
// There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

// Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

// Note that the starting point is assumed to be valid, so it might not be included in the bank.

// Example 1:

// Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
// Output: 1
// Example 2:

// Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
// Output: 2

// Constraints:

// 0 <= bank.length <= 10
// startGene.length == endGene.length == bank[i].length == 8
// startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        if (startGene == endGene)
            return 1;
        if (!bank.size())
            return -1;
        int n = startGene.size();
        set<string> geneBank;
        for (string gene : bank)
            geneBank.insert(gene); //for faster access
        if (!geneBank.count(endGene)) //no endgene to reach
            return -1;
        set<string> visited;
        queue<string> q;
        q.push(startGene);
        visited.insert(startGene);
        vector<char> muts = {'A', 'C', 'G', 'T'};
        int ans = 0;
        while (!q.empty())
        {
            int size = q.size();
            ans++;//each level is one mutation
            for (int k = 0; k < size; k++)
            {
                string st = q.front();
                q.pop();
                for (int i = 0; i < st.size(); i++)
                {
                    string s = st;
                    for (char c : muts)
                    {
                        if (s[i] == c)
                            continue;
                        s[i] = c;
                        if (s == endGene)
                            return ans;
                        if (!visited.count(s) && geneBank.count(s))
                        {
                            visited.insert(s);
                            q.push(s);
                        }
                    }
                }
            }
        }
        return -1;
    }
};

// Time Complexity: O(N * M * 4) where N is the number of genes in the bank and M is the length of each gene (8 in this case).
// Space Complexity: O(N) for the queue and visited set.