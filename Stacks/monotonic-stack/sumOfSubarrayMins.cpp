#include <bits/stdc++.h>
using namespace std;


// Given an array of integers arr of size n, calculate the sum of the minimum value in each (contiguous) subarray of arr. Since the result may be large, return the answer modulo 109 +7.
// Example 1
// Input: arr = [3, 1, 2, 5]
// Output: 18
// Explanation: The minimum of subarrays: [3], [1], [2], [5], [3, 1], [1, 2], [2, 5], [3, 1, 2], [1, 2, 5], [3, 1, 2, 5] are 3, 1, 2, 5, 1, 1, 2, 1, 1, 1 respectively and their sum is 18.
// Example 2
// Input: arr = [2, 3, 1]
// Output: 10
// Explanation: The minimum of subarrays: [2], [3], [1], [2,3], [3,1], [2,3,1] are 2, 3, 1, 2, 1, 1 respectively and their sum is 10.
class Solution {
public:
    vector<int>findNSE(vector<int>&arr){
        int n = arr.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]) st.pop();
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>findPSEE(vector<int>&arr){
        int n = arr.size();
        vector<int>psee(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]) st.pop();
            psee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int> &arr) {
        vector<int>nse = findNSE(arr);
        vector<int>psee = findPSEE(arr);
        int total = 0,mod = (int)1e9+7;
        for(int i=0;i<arr.size();i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            long long freq = right*left*1LL;
            int val = (freq*arr[i]*1LL)%mod;
            total=(total+val)%mod;
        }
        return total;
    }
};

int main()
{
    Solution s;
    // vector<int> arr = {3, 1, 2, 5};//input for subarray mins
    vector<int> arr = {1,3,3};//input for subarray range
    cout<<s.sumSubarrayMins(arr)<<endl;
    return 0;
}