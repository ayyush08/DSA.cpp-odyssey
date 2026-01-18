// Range Minimum Query
// Given an array A[ ] and its size N your task is to complete two functions  a constructST  function which builds the segment tree  and a function RMQ which finds range minimum query in a range [a,b] of the given array.

// Input:
// The task is to complete two functions constructST and RMQ.
// The constructST function builds the segment tree and takes two arguments the array A[ ] and the size of the array N.
// It returns a pointer to the first element of the segment tree array.
// The RMQ function takes 4 arguments the first being the segment tree st constructed, second being the size N and then third and forth arguments are the range of query a and b. The function RMQ returns the min of the elements in the array from index range a and b. There are multiple test cases. For each test case, this method will be called individually.

// Output:
// The function RMQ should return the min element in the array from range a to b.

// Example:

// Input (To be used only for expected output)
// 1
// 4
// 1 2 3 4
// 2
// 0 2 2 3
// Output
// 1 3
// Explanation
// 1. For query 1 ie 0 2 the element in this range are 1 2 3
//    and the min element is 1.
// 2. For query 2 ie 2 3 the element in this range are 3 4
//    and the min element is 3.
// Constraints:
// 1<=T<=100
// 1<=N<=10^3+1

// 1<=A[i]<=10^9
// 1<=Q(no of queries)<=10000
// 0<=a<=b

#include <bits/stdc++.h>
using namespace std;

/* The functions which
builds the segment tree */

void buildSegmentTree(int i, int l, int r, int segmentTree[], int arr[])
{
    if (l == r)
    {
        segmentTree[i] = arr[l];
        return;
    }
    int mid = l + (r - l) / 2;
    buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
    buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);

    segmentTree[i] = min(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
}

int query(int start, int end, int i, int l, int r, int segmentTree[])
{
    if (l > end || r < start)
        return INT_MAX;
    if (l >= start && r <= end)
        return segmentTree[i];

    int mid = l + (r - l) / 2;
    return min(query(start, end, 2 * i + 1, l, mid, segmentTree), query(start, end, 2 * i + 2, mid + 1, r, segmentTree));
}

int *constructST(int arr[], int n)
{
    // Your code here
    int *segmentTree = new int[4 * n];
    buildSegmentTree(0, 0, n - 1, segmentTree, arr);
    return segmentTree;
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b)
{

    // Your code here
    return query(a, b, 0, 0, n - 1, st);
}