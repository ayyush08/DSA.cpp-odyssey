// Minimum Operations To Exceed Target
// You are given a 0-indexed integer array scores, where each element represents the score of a player in a competition, and an integer targetScore. Your task is to determine the minimum number of operations required to ensure that all scores in the array are greater than or equal to targetScore.

// If it is not possible to make all scores greater than or equal to target score return -1.
// In one operation, you must:
// Select the two lowest scores x and y from the array (only possible if the array has at least two elements).
// Remove x and y from the array.
// Add a new score equal to min(x, y) × 2 + max(x, y) to the array.

// Examples:
// Input: scores = [4, 1, 7, 3, 6]
// targetScore = 5
// Output: 2
// Explanation:
// Operation 1: Combine 1 and 3. The new score is 2 × 1 + 3 = 5. Updated scores: [4, 5, 7, 6].
// Operation 2: Combine 4 and 5. The new score is 2 × 4 + 5 = 13. Updated scores: [13, 7, 6]
// At this point, all scores are greater than or equal to 5.

// Input: scores = [5, 2, 8, 1, 10]
// targetScore = 12
// Output: 3
// Explanation:
// Operation 1: Combine 1 and 2. The new score is 2 × 1 + 2 = 4. Updated scores: [5, 4, 8, 10].
// Operation 2: Combine 4 and 5. The new score is 2 × 4 + 5 = 13. Updated scores: [13, 8, 10].
// Operation 3: Combine 8 and 10. The new score is 2 × 8 + 10 = 26. Updated scores: [26, 13].
// At this point, all scores are greater than or equal to 12.

// Constraints:
// 2 ≤ scores.length ≤ 2 × 105
// 1 ≤ scores[i] ≤ 109
// 1 ≤ targetScore ≤ 109

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperationsToExceedTarget(vector<int>& nums, int targetValue) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int score:nums) pq.push(score);
        int ops = 0;
        while(pq.top()<targetValue){
            if(pq.size()<2) return -1;
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
                int newScore = min(x,y)*2+max(x,y);
                ops++;
                pq.push(newScore);
            
        }
        return ops;


        }
};

//Time Complexity: O(n log n) where n is the number of scores in the input array. This is because we may need to perform up to n-1 operations, and each operation involves removing two elements from the priority queue and adding one new element, which takes O(log n) time.
//Space Complexity: O(n) for the priority queue that stores the scores.