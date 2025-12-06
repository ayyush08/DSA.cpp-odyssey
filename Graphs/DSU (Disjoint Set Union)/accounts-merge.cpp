// 721. Accounts Merge
// Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

// Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

// Example 1:

// Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Explanation:
// The first and second John's are the same person as they have the common email "johnsmith@mail.com".
// The third John and Mary are different people as none of their email addresses are used by other accounts.
// We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'],
// ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
// Example 2:

// Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
// Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]

// Constraints:

// 1 <= accounts.length <= 1000
// 2 <= accounts[i].length <= 10
// 1 <= accounts[i][j].length <= 30
// accounts[i][0] consists of English letters.
// accounts[i][j] (for j > 0) is a valid email.

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> rank;
    void init(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void unionByRank(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DSU dsu;
        int n = accounts.size();
        dsu.init(n);
        unordered_map<string, int> emailMap;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (emailMap.count(mail)) {
                    dsu.unionByRank(i, emailMap[mail]);
                } else {
                    emailMap[mail] = i;
                }
            }
        }

        vector<vector<string>> temp(n);
        for (auto& it : emailMap) {
            string mail = it.first;
            int node = dsu.find(it.second);
            temp[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (temp[i].empty())
                continue;
            sort(temp[i].begin(), temp[i].end());
            temp[i].insert(temp[i].begin(),accounts[i][0]);
            ans.push_back(temp[i]);
        }

        return ans;
    }
};

//Time Complexity: O(N * α(N)) , where N is the total number of emails in all accounts and α is the Inverse Ackermann function which is very slow growing and for all practical purposes can be considered a constant less than 5.
//Space Complexity: O(N) for DSU data structure and the map to store email to node mapping.

//Intuition:
//We can use Disjoint Set Union (DSU) to group accounts that share common emails. If a mail is already present in the map, it means it belongs to an existing group, so we union the current account with that group. Then we process the emails to form the final merged accounts.
