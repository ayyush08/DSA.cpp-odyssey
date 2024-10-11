// Combination Sum II
// Given collection of candidate numbers (candidates) and a integer target.Find all unique combinations in candidates where the sum is equal to the target.There can only be one usage of each number in the candidates combination and return the answer in sorted order.

// e.g : The combination [1, 1, 2] and [1, 2, 1] are not unique.

// Example 1
// Input : candidates = [2, 1, 2, 7, 6, 1, 5] , target = 8

// Output : [ [1, 1, 6] , [1, 2, 5] , [1, 7] , [2, 6] ]

// Explanation : The combinations sum up to target are

// 1 + 1 + 6 => 8.

// 1 + 2 + 5 => 8.

// 1 + 7 => 8.

// 2 + 6 => 8.

// Example 2
// Input : candidates = [2, 5, 2, 1, 2] , target = 5

// Output : [ [1, 2, 2] , [5] ]

// Explanation : The combinations sum up to target are

// 1 + 2 + 2 => 5.

// 5 => 5.

// Example 3
// Input : candidates = [2, 1, 2] , target = 5

// Output:
// [ [1, 2, 2] ]

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void func(int ind,vector<vector<int>>&ans,vector<int>&temp,vector<int>&candidates,int sum){
        if(sum==0){
            ans.push_back(temp);
            return;
        }
        if(sum<0) return;
        if(ind==candidates.size()) return;
        temp.push_back(candidates[ind]);
        func(ind+1,ans,temp,candidates,sum-candidates[ind]);
        temp.pop_back();

        for(int i=ind+1;i<candidates.size();i++){
            if(candidates[i]!=candidates[ind]){
                func(i,ans,temp,candidates,sum);
                break;
            }
        }

    }
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        //your code goes here
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        func(0,ans,temp,candidates,target);
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>candidates(n);
    for(int i=0;i<n;i++){
        cin>>candidates[i];
    }
    int target;
    cin>>target;
    Solution obj;
    vector<vector<int>>ans=obj.combinationSum2(candidates,target);
    for(int i=0;i<ans.size();i++){
        cout<<"[ ";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"] ";
    }
    return 0;
}

// Time Complexity: O(2^N*N) - due to sorting
// Space Complexity: O(N) - due to recursion stack