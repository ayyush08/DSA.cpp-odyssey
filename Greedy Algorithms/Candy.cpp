// Candy
// A line of N kids is standing there. The rating values listed in the integer array ratings are assigned to each kid.

// These kids are receiving candy, according to the following criteria:

// There must be at least one candy for every child.

// Kids whose scores are higher than their neighbours receive more candies than their neighbours.

// Return the minimum number of candies needed to distribute among children.

// Examples:
// Input : ratings = [1, 0, 5]

// Output : 5

// Explanation : The distribution of candies will be 2 , 1 , 2 to first , second , third child respectively.

// Input : ratings = [1, 2, 2]

// Output : 4

// Explanation : The distribution of candies will be 1 , 2 , 1 to first , second , third child respectively.

// The third gets only 1 candy because it satisfy above two criteria.

#include <bits/stdc++.h>
using namespace std;

// Brute: TC: O(3N), SC: O(2N)

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> left(n), right(n);

        left[0] = 1;
        right[n - 1] = 1;

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
            else
                left[i] = 1;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                right[i] = right[i + 1] + 1;
            }
            else
                right[i] = 1;
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += max(left[i], right[i]);
        }
        return sum;
    }
};

// Better: TC: O(2N), SC: O(N)
class Solution2
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> left(n);

        left[0] = 1;

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
            else
                left[i] = 1;
        }
        int curr = 1, right = 1;
        int sum = max(1, left[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                curr = right + 1;
                right = curr;
            }
            else
                curr = 1;
            sum += max(left[i], curr);
        }
        return sum;
    }
};

// Optimal: TC: O(N), SC: O(1)
// We use the concept of slope and keep track of the peak and down slopes , when we have a peak we keep increasing the candies and when we have a down slope we keep decreasing the candies, if we have a plateau we just keep the candies same. In case, we have a down slope after a peak we need to make sure that we have enough candies for the peak.
class Solution3
{
public:
    int candy(vector<int> &ratings)
    {
        int i = 1, ans = 1;
        int n = ratings.size();

        while (i < n)
        {
            if (ratings[i] == ratings[i - 1])
            {
                ans += 1;
                i++;
                continue;
            }
            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1])
            {
                peak += 1;
                ans += peak;
                i++;
            }
            int down = 1;
            while (i < n && ratings[i] < ratings[i - 1])
            {
                ans += down;
                down += 1;
                i++;
            }
            if (down > peak)
                ans += (down - peak);
        }
        return ans;
    }
};