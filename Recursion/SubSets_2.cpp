// Subsets II
// Given an integer array nums, which can have duplicate entries, provide the power set. Duplicate subsets cannot exist in the solution set. Return the answer in any sequence.

// Example 1
// Input : nums = [1, 2, 2]
// Output : [ [ ] , [1] , [1, 2] , [1, 2, 2] , [2] , [2, 2] ]

// Example 2
// Input : nums = [1, 2]
// Output : [ [ ], [1] , [2] , [1, 2] ]

// Example 3
// Input : nums = [1, 3, 3]
// Output:
// [ [ ], [1] , [1, 3] , [1, 3, 3] , [3] , [3, 3] ]


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void func(int ind, vector<int>& temp, vector<vector<int>>& ans,vector<int>& nums ){
        if(ind==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        func(ind+1,temp,ans,nums);
        temp.pop_back();
        for(int i=ind+1;i<nums.size();i++){
            if(nums[i]!=nums[ind]){
                func(i,temp,ans,nums);
                return;
            }
        }
        func(nums.size(),temp,ans,nums);
    }
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        //your code goes here
        vector<vector<int>> ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        func(0,temp,ans,nums);
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    vector<vector<int>>ans=ob.subsetsWithDup(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}