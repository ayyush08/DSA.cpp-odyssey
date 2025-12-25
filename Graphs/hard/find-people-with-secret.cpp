// 2092. Find All People With Secret
// You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.

// Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.

// The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.

// Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.

// Example 1:

// Input: n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
// Output: [0,1,2,3,5]
// Explanation:
// At time 0, person 0 shares the secret with person 1.
// At time 5, person 1 shares the secret with person 2.
// At time 8, person 2 shares the secret with person 3.
// At time 10, person 1 shares the secret with person 5.​​​​
// Thus, people 0, 1, 2, 3, and 5 know the secret after all the meetings.
// Example 2:

// Input: n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3
// Output: [0,1,3]
// Explanation:
// At time 0, person 0 shares the secret with person 3.
// At time 2, neither person 1 nor person 2 know the secret.
// At time 3, person 3 shares the secret with person 0 and person 1.
// Thus, people 0, 1, and 3 know the secret after all the meetings.
// Example 3:

// Input: n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
// Output: [0,1,2,3,4]
// Explanation:
// At time 0, person 0 shares the secret with person 1.
// At time 1, person 1 shares the secret with person 2, and person 2 shares the secret with person 3.
// Note that person 2 can share the secret at the same time as receiving it.
// At time 2, person 3 shares the secret with person 4.
// Thus, people 0, 1, 2, 3, and 4 know the secret after all the meetings.

// Constraints:

// 2 <= n <= 105
// 1 <= meetings.length <= 105
// meetings[i].length == 3
// 0 <= xi, yi <= n - 1
// xi != yi
// 1 <= timei <= 105
// 1 <= firstPerson <= n - 1

#include <bits/stdc++.h>
using namespace std;

// Approach 1: First, group all meetings by their time and process them in increasing time order so the secret spreads chronologically. Initially, only person 0 and firstPerson know the secret. For each time group, build a temporary graph using only the people who meet at that exact time. Then, start a BFS from those nodes in this group who already know the secret; the BFS allows the secret to spread through connected components formed at that time. After finishing BFS for that time, update the global knowsSecret array and discard the temporary graph, ensuring secrets don’t leak across different times incorrectly. Finally, return all people marked as knowing the secret.

// Time Complexity: O(M log M + M + N) where M is the number of meetings and N is the number of people. Sorting meetings takes O(M log M), building graphs and BFS across all meetings takes O(M), and collecting results takes O(N).
// Space Complexity: O(M + N) for storing the meetings in a map and the knowsSecret array.

class Solution1
{
public:
    typedef pair<int, int> P;
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                              int firstPerson)
    {
        map<int, vector<P>> timeToMeetingsMap;
        for (auto meeting : meetings)
        {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time = meeting[2];
            timeToMeetingsMap[time].push_back({person1, person2});
        }

        vector<bool> knowsSecret(n, false);
        knowsSecret[0] = true;
        knowsSecret[firstPerson] = true;
        for (auto &it : timeToMeetingsMap)
        {
            int time = it.first;
            vector<P> meetings = it.second;

            unordered_map<int, vector<int>> adj;
            queue<int> q;
            unordered_set<int> seen;

            for (auto &[person1, person2] : meetings)
            {
                adj[person1].push_back(person2);
                adj[person2].push_back(person1);

                if (knowsSecret[person1] && !seen.count(person1))
                {
                    q.push(person1);
                    seen.insert(person1);
                }
                if (knowsSecret[person2] && !seen.count(person2))
                {
                    q.push(person2);
                    seen.insert(person2);
                }
            }

            while (!q.empty())
            {
                int person = q.front();
                q.pop();

                for (auto &nextPerson : adj[person])
                {
                    if (!knowsSecret[nextPerson])
                    {
                        knowsSecret[nextPerson] = true;
                        q.push(nextPerson);
                    }
                }
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (knowsSecret[i])
                ans.push_back(i);
        }
        return ans;
    }
};

// Appraoch 2:  Earlier, we processed meetings time by time, built a temporary graph for each timestamp, and ran BFS inside that snapshot.
//  Here, we build one global graph with time-stamped edges and do a single BFS that only moves forward in time.
//  Instead of “who knows the secret at this time?”, we track the earliest time each person can know the secret and relax edges only if the meeting happens after that time.
//  So the old approach was event-driven (per time block), while this one is state-driven (earliest-time propagation)—simpler and more compact.

// Time Complexity: O(M + N) where M is the number of meetings and N is the number of people. Building the graph takes O(M), and the BFS traversal takes O(M + N).

// Space Complexity: O(M + N) for storing the graph and the earliestSecretTime array.

// Gives TLE on leetcode so we use Approach 3 (Dijkstra's Algorithm based approach) in the final submission.

class Solution2
{
public:
    typedef pair<int, int> P;
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        unordered_map<int, vector<P>> adj;
        for (auto meeting : meetings)
        {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time = meeting[2];

            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }

        vector<int> earlySecret(n, INT_MAX);
        queue<P> q;
        q.push({0, 0});
        q.push({firstPerson, 0});
        earlySecret[0] = 0;
        earlySecret[firstPerson] = 0;

        while (q.size())
        {
            auto [person, time] = q.front();
            q.pop();

            for (auto &it : adj[person])
            {
                int ngbr = it.first;
                int t = it.second;
                if (t >= time && earlySecret[ngbr] > t)
                {
                    earlySecret[ngbr] = t;
                    q.push({ngbr, t});
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (earlySecret[i] != INT_MAX)
                ans.push_back(i);
        }
        return ans;
    }
};

// Appraoch 3: Dijkstra's Algorithm based approach

class Solution
{
public:
    typedef pair<int, int> P;
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        unordered_map<int, vector<P>> adj;

        for (vector<int> &meeting : meetings)
        {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time = meeting[2];

            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }

        priority_queue<P, vector<P>, greater<P>> pq; // I need the ones first having min time
        pq.push({0, 0});
        pq.push({0, firstPerson});

        vector<bool> visited(n, false);

        while (!pq.empty())
        {
            auto [time, person] = pq.top();
            pq.pop();

            if (visited[person] == true)
            {
                continue;
            }
            visited[person] = true;

            for (auto &ngbr : adj[person])
            {
                int nextPerson = ngbr.first;
                int t = ngbr.second;

                if (t >= time && !visited[nextPerson])
                {
                    pq.push({t, nextPerson});
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == true)
            {
                result.push_back(i);
            }
        }

        return result;
    }
};