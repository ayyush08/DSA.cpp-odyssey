#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums, determine the range of a subarray, defined as the difference between the largest and smallest elements within the subarray. Calculate and return the sum of all subarray ranges of nums.
// A subarray is defined as a contiguous, non-empty sequence of elements within the array.
// Example 1
// Input: nums = [1, 2, 3]
// Output: 4
// Explanation: The 6 subarrays of nums are the following:
// [1], range = largest - smallest = 1 - 1 = 0 
// [2], range = 2 - 2 = 0
// [3], range = 3 - 3 = 0
// [1,2], range = 2 - 1 = 1
// [2,3], range = 3 - 2 = 1
// [1,2,3], range = 3 - 1 = 2

// So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
class Solution
{
    vector<int> findNSE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nse[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return nse;
    }
    vector<int> findNGE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            nge[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return nge;
    }
    vector<int> findPGEE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pgee(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            pgee[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return pgee;
    }
    vector<int> findPSEE(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            psee[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return psee;
    }
    long long sumSubarrayMins(vector<int> &arr)
    {
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);
        int n = arr.size();
        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            int left = i - psee[i];
            int right = nse[i] - i;
            long long freq = right * left * 1LL;
            long long val = (freq * arr[i] * 1LL);
            total += val;
        }
        return total;
    }
    long long sumSubarrayMaxs(vector<int> &arr)
    {
        vector<int> nge = findNGE(arr);
        vector<int> pgee = findPGEE(arr);
        long long total = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int left = i - pgee[i];
            int right = nge[i] - i;
            long long freq = right * left * 1LL;
            long long val = (freq * arr[i] * 1LL);
            total = (total + val);
        }
        return total;
    }

public:
    long long subArrayRanges(vector<int> &nums)
    {
        return (sumSubarrayMaxs(nums) - sumSubarrayMins(nums));
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,3,3};
    cout<<s.subArrayRanges(arr)<<endl;
    return 0;
}