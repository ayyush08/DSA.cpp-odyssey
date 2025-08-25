// Job sequencing Problem
// Given an 2D array Jobs of size Nx3, where Jobs[i][0] represents JobID , Jobs[i][1] represents Deadline , Jobs[i][2] represents Profit associated with that job. Each Job takes 1 unit of time to complete and only one job can be scheduled at a time.

// The profit associated with a job is earned only if it is completed by its deadline. Find the number of jobs and maximum profit.

// Examples:
// Input : Jobs = [ [1, 4, 20] , [2, 1, 10] , [3, 1, 40] , [4, 1, 30] ]

// Output : 2 60

// Explanation : Job with JobID 3 can be performed at time t=1 giving a profit of 40.

// Job with JobID 1 can be performed at time t=2 giving a profit of 20.

// No more jobs can be scheduled, So total Profit = 40 + 20 => 60.

// Total number of jobs completed are two, JobID 1, JobID 3.

// So answer is 2 60.

// Input : Jobs = [ [1, 2, 100] , [2, 1, 19] , [3, 2, 27] , [4, 1, 25] , [5, 1, 15] ]

// Output : 2 127

// Explanation : Job with JobID 1 can be performed at time time t=1 giving a profit of 100.

// Job with JobID 3 can be performed at time t=2 giving a profit of 27.

// No more jobs can be scheduled, So total Profit = 100 + 27 => 127.

// Total number of jobs completed are two, JobID 1, JobID 3.

// So answer is 2 127.

// Greedy TC: : O(N logN + N^2)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool static compare(const vector<int> &a, const vector<int> &b)
    {
        return a[2] > b[2];
    }
    vector<int> JobScheduling(vector<vector<int>> &Jobs)
    {
        sort(Jobs.begin(), Jobs.end(), compare);

        int n = Jobs.size();

        int maxDeadline = -1;
        for (auto job : Jobs)
            maxDeadline = max(maxDeadline, job[1]);

        vector<int> scheduledJobs(maxDeadline + 1, -1);

        int jobsCount = 0;
        int totalProfit = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = Jobs[i][1] - 1; j >= 0; j--)
            {
                if (scheduledJobs[j] == -1)
                {
                    jobsCount++;
                    scheduledJobs[j] = Jobs[i][0];
                    totalProfit += Jobs[i][2];
                    break;
                }
            }
        }

        return {jobsCount, totalProfit};
    }
};

// Optimized by DSU: O(NlogN)

class Solution2
{
public:
    struct DSU
    {
        vector<int> parent;
        void init(int n)
        {
            parent.assign(n, 0);
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int v)
        {
            if (parent[v] == v)
                return v;
            return parent[v] = find(parent[v]);
        }
        void occupySlot(int v)
        {
            parent[v] = find(v - 1);
        }
    };
    bool static compare(const vector<int> &a, const vector<int> &b)
    {
        return a[2] > b[2];
    }
    vector<int> JobScheduling(vector<vector<int>> &Jobs)
    {
        sort(Jobs.begin(), Jobs.end(), compare);

        int n = Jobs.size();

        int maxDeadline = -1;
        for (auto job : Jobs)
            maxDeadline = max(maxDeadline, job[1]);
        DSU scheduledJobs;
        scheduledJobs.init(maxDeadline + 1);

        int jobsCount = 0;
        int totalProfit = 0;

        for (int i = 0; i < n; i++)
        {
            int deadline = Jobs[i][1];
            int availableSlot = scheduledJobs.find(deadline);

            if (availableSlot > 0)
            {
                jobsCount++;
                totalProfit += Jobs[i][2];
                scheduledJobs.occupySlot(availableSlot);
            }
        }

        return {jobsCount, totalProfit};
    }
};