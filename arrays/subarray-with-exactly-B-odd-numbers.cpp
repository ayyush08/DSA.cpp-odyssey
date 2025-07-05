// Subarray with B odd numbers

// Given an array of integers A and an integer B.

// Find the total number of subarrays having exactly B odd numbers.

// Problem Constraints
// 1 <= length of the array <= 105

// 1 <= A[i] <= 109

// 0 <= B <= A

// Input Format
// The first argument given is the integer array A.

// The second argument given is integer B.

// Output Format
// Return the total number of subarrays having exactly B odd numbers.

// Example Input
// Input 1:

//  A = [4, 3, 2, 3, 4]
//  B = 2
// Input 2:

//  A = [5, 6, 7, 8, 9]
//  B = 3

// Example Output
// Output 1:

//  4
// Output 2:

//  1

// Example Explanation
// Explanation 1:

//  The subarrays having exactly B odd numbers are:
//  [4, 3, 2, 3], [4, 3, 2, 3, 4], [3, 2, 3], [3, 2, 3, 4]
// Explanation 2:

//  The subarrays having exactly B odd numbers is [5, 6, 7, 8, 9]

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Using Prefix Sum and Hash Map

int solve(vector<int> &A, int B)
{
    unordered_map<int, int> mp;
    int cumulative_odds = 0, ans = 0;
    mp[0] = 1;
    int n = A.size();
    for (int num : A)
    {
        if (num % 2 == 1)
            cumulative_odds++;
        if (mp.find(cumulative_odds - B) != mp.end())
        {
            ans += mp[cumulative_odds - B];
        }
        mp[cumulative_odds]++;
    }
    return ans;
}

// Intuition:
//  The idea is to maintain a count of cumulative odd numbers seen so far.
//  For each element in the array, we check how many times we have seen a cumulative count of odd numbers that is exactly B less than the current count.
//  This is done using a hash map to store the frequency of cumulative odd counts.
//  This way, we can efficiently count the number of subarrays with exactly B odd numbers in O(n) time complexity.
//  The space complexity is O(n) due to the hash map used to store cumulative counts.

// Approach 2: Using Two Pointers Technique(Sliding Window) to avoid using extra space

int subsum(vector<int> &A, int k)
{
    if (k < 0)
        return 0;
    int sum = 0, l = 0, r = 0;
    int cnt = 0;
    while (r < A.size())
    {
        sum += (A[r] % 2);
        while (sum > k)
        {
            sum -= (A[l] % 2);
            l++;
        }
        cnt += (r - l + 1);
        r++;
    }
    return cnt;
}

int solve(vector<int> &A, int B)
{
    return (subsum(A, B) - subsum(A, B - 1)); // Count of subarrays with exactly B odd numbers  = Count of subarrays with at most B odd numbers - Count of subarrays with at most B-1 odd numbers
}
