// SJF (Shortest Job First) - Scheduling policy that selects the waiting process with the smallest execution time to execute next.

// Shortest Job First
// A software engineer is tasked with using the shortest job first (SJF) policy to calculate the average waiting time for each process. The shortest job first also known as shortest job next (SJN) scheduling policy selects the waiting process with the least execution time to run next.

// Given an array of n integers representing the burst times of processes, determine the average waiting time for all processes and return the closest whole number that is less than or equal to the result.

// Examples:
// Input : bt = [4, 1, 3, 7, 2]

// Output : 4

// Explanation : The total waiting time is 20.

// So the average waiting time will be 20/5 => 4.

// Input : bt = [1, 2, 3, 4]

// Output : 2

// Explanation : The total waiting time is 10.

// So the average waiting time will be 10/4 => 2.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long solve(vector<int> &bt)
    {
        sort(bt.begin(), bt.end());
        long long totalTime = 0;
        long long waitingTime = 0;
        for (int job : bt)
        {
            waitingTime += totalTime; //how long current process needs to wait till it gets executed
            totalTime += job; //how long processes have been executed
        }

        return waitingTime / bt.size();
    }
};