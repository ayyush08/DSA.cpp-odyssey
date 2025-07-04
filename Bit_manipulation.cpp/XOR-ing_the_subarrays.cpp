// Given an integer array A of size N.

// You need to find the value obtained by XOR-ing the contiguous subarrays, followed by XOR-ing the values thus obtained. Determine and return this value.

// For example, if A = [3, 4, 5] :

// Subarray    Operation   Result
// 3       None            3
// 4       None            4
// 5       None            5
// 3,4   3 XOR 4         7
// 4,5   4 XOR 5         1
// 3,4,5    3 XOR 4 XOR 5   2

// Now we take the resultant values and XOR them together:

// 3 ⊕ 4 ⊕ 5 ⊕ 7 ⊕ 1⊕ 2 = 6 we will return 6.

// Problem Constraints
// 1 <= N <= 105

// 1 <= A[i] <= 108

// Input Format
// First and only argument is an integer array A.

// Output Format
// Return a single integer denoting the value as described above.

// Example Input
// Input 1:

//  A = [1, 2, 3]
// Input 2:

//  A = [4, 5, 7, 5]

// Example Output
// Output 1:

//  2
// Output 2:

//  0

// Example Explanation
// Explanation 1:

//  1 ⊕ 2 ⊕ 3 ⊕  (1 ⊕ 2 ) ⊕ (2 ⊕ 3) ⊕ (1 ⊕ 2 ⊕ 3) = 2
// Explanation 2:

//  4 ⊕ 5 ⊕ 7 ⊕ 5 ⊕ (4 ⊕ 5) ⊕ (5 ⊕ 7) ⊕ (7 ⊕ 5) ⊕ (4 ⊕ 5 ⊕ 7) ⊕ (5 ⊕ 7 ⊕ 5) ⊕ (4 ⊕ 5 ⊕ 7 ⊕ 5) = 0

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A)
{
    int n = A.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int contri = (i + 1) * (n - i);
        if ((contri & 1) == 1)
            ans ^= A[i];
    }
    return ans;
}


//Approach:// 1. For each element A[i], calculate its contribution to the final XOR based on how many times it appears in the XOR of all subarrays.
// 2. The contribution of A[i] is determined by the number of subarrays that include it, which is given by (i + 1) * (n - i), where n is the size of the array.
// 3. If the contribution is odd, include A[i] in the final XOR, cuz if it was even, it would all cancel out.
// Time Complexity: O(n), where n is the number of elements in the input array.
// Space Complexity: O(1), since we are using only a constant amount of extra space
