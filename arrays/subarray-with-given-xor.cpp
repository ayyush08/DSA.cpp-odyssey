// Subarray with given XOR
// Problem Description

// Given an array of integers A and an integer B.
// Find the total number of subarrays having bitwise XOR of all elements equals to B.

// Problem Constraints
// 1 <= length of the array <= 105
// 1 <= A[i], B <= 109

// Input Format
// The first argument given is the integer array A.
// The second argument given is integer B.

// Output Format
// Return the total number of subarrays having bitwise XOR equals to B.
// Example Input
// Input 1:
//  A = [4, 2, 2, 6, 4]
//  B = 6
// Input 2:
//  A = [5, 6, 7, 8, 9]
//  B = 5

// Example Output
// Output 1:
//  4
// Output 2:
//  2

// Example Explanation
// Explanation 1:
//  The subarrays having XOR of their elements as 6 are:
//  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
// Explanation 2:
//  The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int length=0;
    int n1 = A.size();
    int x = 0;
    unordered_map<int,int>prefSum;
    for(int i=0;i<n1;i++){
        x^=A[i];
        if(x==B) length++;
        if(prefSum.find(x^B)!=prefSum.end()){
            length+=prefSum[x^B];
        }
        prefSum[x]++;
    }
    return length;
}

//build subarray with given XOR, check if  the XOR of the subarray equals B, if yes, increment the count
//use a hashmap to store the prefix XORs, check if current xor with B(which is equal to 0 if current xor is equal to B) exists in the hashmap, meaning there is already a subarray with the same XOR, increment the count by the number of times it has occurred
// add current XOR to the hashmap, incrementing its count