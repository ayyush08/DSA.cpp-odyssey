#include <bits/stdc++.h>
using namespace std;

class SolutionWithArray {
public:
    int partition(int nums[], int low, int high) {
        int i = low, j = high;
        int pivot = nums[low];
        while (i < j) {
            while (nums[i] <= pivot && i <= high - 1) i++;
            while (nums[j] > pivot && j >= low + 1) j--;
            if (i < j) swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        return j;
    }

    void quickSortHelper(int nums[], int low, int high) {
        if (low < high) {
            int partInd = partition(nums, low, high);
            quickSortHelper(nums, low, partInd - 1);
            quickSortHelper(nums, partInd + 1, high);
        }
    }

    void quickSort(int nums[], int n) {
        quickSortHelper(nums, 0, n - 1);
    }
};

class Solution {
public:
    int partition(vector<int>&nums,int low, int high){
        int i = low,j=high;
        int pivot = nums[low];
        while(i<j){
            while(nums[i]<=pivot && i<=high-1) i++;
            while(nums[j]>pivot && j>=low+1) j--;
            if(i<j) swap(nums[i],nums[j]);
        }
        swap(nums[low],nums[j]);
        return j;
    }
    void quickSortHelper(vector<int>&nums,int low,int high){
        if(low<high){

        int partInd = partition(nums,low,high);
        quickSortHelper(nums,low,partInd-1);
        quickSortHelper(nums,partInd+1,high);
        }
    }
    vector<int> quickSort(vector<int>& nums) {
        int n = nums.size();
        quickSortHelper(nums,0,n-1);
        return nums;
    }
};


int main(){
    Solution s;
    vector<int> nums = {3,2,1,5,6,4};
    vector<int> res = s.quickSort(nums);
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    cout<<endl;
    SolutionWithArray s1;
    int arr[] = {10,9,-9,7,6,50,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    s1.quickSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// Time Complexity: O(nlogn) - because of the partitioning and recursive calls
// Space Complexity: O(1) - no extra space is used