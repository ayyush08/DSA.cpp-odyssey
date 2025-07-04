// You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

// Return the minimum number of CPU intervals required to complete all tasks.

// Example 1:

// Input: tasks = ["A","A","A","B","B","B"], n = 2

// Output: 8

// Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

// After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

// Example 2:
// Input: tasks = ["A","C","A","B","D","B"], n = 1
// Output: 6
// Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
// With a cooling interval of 1, you can repeat a task after just one other task.

// Example 3:
// Input: tasks = ["A","A","A", "B","B","B"], n = 3
// Output: 10
// Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
// There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

// Constraints:
// 1 <= tasks.length <= 10^4
// tasks[i] is an uppercase English letter.
// 0 <= n <= 100

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> mp;
        for (char task : tasks)
            mp[task]++;
        priority_queue<int> pq;
        for (auto &[c, f] : mp)
        {
            pq.push(f);
        }
        queue<pair<int, int>> waiting;
        int intervals = 0;
        while (!pq.empty() || !waiting.empty())
        {
            intervals++;

            if (!pq.empty())
            {
                int topTask = pq.top();
                pq.pop();
                if (topTask - 1 > 0)
                    waiting.push({intervals + n, topTask - 1});
            }

            if (!waiting.empty() && waiting.front().first == intervals)
            {
                pq.push(waiting.front().second);
                waiting.pop();
            }
        }
        return intervals;
    }
};

//Maintain a maxheap to store the frequency of tasks. and a queue to store the tasks that are waiting for their cooldown period to end.
// In each interval, we pop the task with the highest frequency from the max heap and decrement its frequency. If its frequency is still greater than 0, we push it into the waiting queue with the next available interval after n intervals.
// If the waiting queue has tasks that are ready to be processed (i.e., their cooldown period has ended , equal to the current interval), we push them back into the max heap.
// We continue this process until both the max heap and the waiting queue are empty, counting the number of intervals required to complete all tasks.

//Time Complexity: O(N), where N is the number of tasks. Each task is processed once, and the operations on the priority queue and queue take logarithmic time in the worst case that too for 26 tasks (the number of uppercase English letters). which is treated as constant time.

//Space Complexity: O(1), since the maximum number of unique tasks is 26 (the uppercase English letters), the space used by the priority queue and the waiting queue is constant with respect to the input size. The unordered_map also uses O(1) space in this case.