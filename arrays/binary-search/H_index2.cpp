// Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper and citations is sorted in non-descending order, return the researcher's h-index.

// According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

// You must write an algorithm that runs in logarithmic time.

// Example 1:

// Input: citations = [0,1,3,5,6]
// Output: 3
// Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had received 0, 1, 3, 5, 6 citations respectively.
// Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
// Example 2:

// Input: citations = [1,2,100]
// Output: 2
// Given citations are sorted
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int l = 0, r = n - 1;
        int ans = 0;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (citations[mid] >= n - mid)
            {
                ans = n - mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};

class Solution2
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int l = 0, r = n;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int minCitations = mid == 0 ? 0 : citations[n - mid];

            if (minCitations >= mid)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r;
    }
};