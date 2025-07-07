
// Find the repeating and missing number
// Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array, except for A, which appears twice and B which is missing.

// Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.

// Examples:
// Input: nums = [3, 5, 4, 1, 1]

// Output: [1, 2]

// Explanation: 1 appears two times in the array and 2 is missing from nums

// Input: nums = [1, 2, 3, 6, 7, 5, 7]

// Output: [7, 4]

// Explanation: 7 appears two times in the array and 4 is missing from nums.
#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int n = a.size(); // size of the array

    int xr = 0;

    // Step 1: Find XOR of all elements:
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    // Step 2: Find the differentiating bit number:
    int number = (xr & ~(xr - 1));

    // Step 3: Group the numbers:
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        // part of 1 group:
        if ((a[i] & number) != 0)
        {
            one = one ^ a[i];
        }
        // part of 0 group:
        else
        {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        // part of 1 group:
        if ((i & number) != 0)
        {
            one = one ^ i;
        }
        // part of 0 group:
        else
        {
            zero = zero ^ i;
        }
    }

    // Last step: Identify the numbers:
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == zero)
            cnt++;
    }

    if (cnt == 2)
        return {zero, one};
    return {one, zero};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
          << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}
