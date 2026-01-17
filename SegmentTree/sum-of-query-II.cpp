// Sum of Query II
// You are given an array arr[] of n integers and q queries in an array queries[] of length 2*q containing l, r pair for all q queries. You need to compute the following sum over q queries.

// Note : Array is 1-Indexed.

// Examples :

// Input: n = 4, arr = {1, 2, 3, 4}, q = 2, queries = {1, 4, 2, 3}
// Output: 10 5
// Explaination: In the first query we need sum from 1 to 4 which is 1+2+3+4 = 10. In the second query we need sum from 2 to 3 which is 2 + 3 = 5.
// Input: n = 5, arr = {26, 30, 48, 29, 8}, q = 2, queries = {4, 4, 2, 3}
// Output: 29 78
// Explaination: In the first query we need sum from 4 to 4 which is 29. In the second query we need sum from 2 to 3 which is 30 + 48 = 78.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function querySum() which takes n, arr, q and queries as input parameters and returns the answer for all the queries.

// Expected Time Complexity: O(n+q)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 ≤ n, q ≤ 105
// 1 ≤ arri ≤ 103
// 1 ≤ l ≤ r ≤ n

#include <bits/stdc++.h>
using namespace std;



class Solution {
  private:
  void buildSegmentTree(int arr[],int i, int left,int right, vector<int>& segmentTree){
      if(left==right){
          segmentTree[i] = arr[left];
          return;
      }
      int mid = left+(right-left)/2;
      buildSegmentTree(arr,2*i+1,left,mid,segmentTree);
      buildSegmentTree(arr,2*i+2,mid+1,right,segmentTree);
      
      segmentTree[i] = segmentTree[2*i+1]+segmentTree[2*i+2];
  }
  int query(vector<int>& segmentTree,int start,int end,int i,int left,int right){
      if(left>end || right<start) return 0;
      if(left >= start&& right<=end) return segmentTree[i];
      
      int mid = left+(right-left)/2;
      return query(segmentTree,start,end,2*i+1,left,mid)+query(segmentTree,start,end,2*i+2,mid+1,right);
  }
  public:
    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        vector<int>segmentTree(4*n);
        vector<int> ans;
        
        buildSegmentTree(arr,0,0,n-1,segmentTree);
        
        for(int i=0;i<2*q;i+=2){
            int start = queries[i]-1;
            int end = queries[i+1]-1;
            ans.push_back(query(segmentTree,start,end,0,0,n-1));
        }
        
        return ans;
        
    }
};

//Struct not used here as not required