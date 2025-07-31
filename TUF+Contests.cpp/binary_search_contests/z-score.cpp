// Z-Score

// 0

// 100
// Easy
// Given an array of integers marks containing the marks of a student in each subject and a multiplicative factor k. Return the Z-Score of the student.

// Z-Score is defined as the maximum value of x, where the student has at least x subjects where they have scored at least x * k.

// Examples:
// Input: marks = [62, 69, 79, 85, 45], k = 20

// Output: 3

// Explanation: Number of subjects with marks >= 3 * k = 3 * 20 = 60 -> [62, 69, 79, 85, 45] = 5

// Number of subjects with marks >= 4 * k = 4 * 20 = 80 -> [85] = 1

// Thus, the maximum Z-Score is 3.

// Input: marks = [93, 64, 91, 85], k = 45

// Output: 2

// Explanation: Number of subjects with marks >= 2 * k = 2 * 45 = 90 -> [93, 91] = 2

// Number of subjects with marks >= 3 * k = 3 * 45 = 135 -> [ ] = 0

// Thus, the maximum Z-Score is 2.

// Constraints:
// n == Number of subjects
// 1 <= n <= 105
// 0 <= marks[i] <= 100
// 1 <= k <= 100

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool hasSubjects(vector<int> &marks, int x, int threshold)
    {
        int cnt = 0;
        for (int sub : marks)
        {
            if (sub >= threshold)
                cnt++;
        }
        return cnt >= x;
    }
    int ZScore(vector<int> &marks, int k)
    {
        int n = marks.size();
        int low = 1, high = n;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (hasSubjects(marks, mid, mid * k))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};