// Combination Sum
// Provided with a goal integer target and an array of unique integer candidates, provide a list of all possible combinations of candidates in which the selected numbers add up to the target. The combinations can be returned in any order.
// A candidate may be selected from the pool an infinite number of times. There are two distinct combinations if the frequency if at least one of the selected figures differs.
// The test cases are created so that, for the given input, there are fewer than 150 possible combinations that add up to the target.
// If there is no possible subsequences then return empty vector.

// Example 1
// Input : candidates = [2, 3, 5, 4] , target = 7

// Output : [ [2, 2, 3] , [3, 4] , [5, 2] ]

// Explanation :

// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.

// 5 and 2 are candidates, and 5 + 2 = 7.

// 3 and 4 are candidates, and 3 + 4 = 7.

// There are total three combinations.

// Example 2
// Input : candidates = [2], target = 1

// Output : []

// Explanation : There is no way we can choose the candidates to sum up to target.

// Example 3
// Input : candidates = [1], target = 1

// Output:
// [ [1] ]

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
        func(ind+1,ans,temp,candidates,sum);
        temp.push_back(candidates[ind]);
        func(ind,ans,temp,candidates,sum-candidates[ind]);
        temp.pop_back();

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //your code goes here
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
    vector<vector<int>>ans=obj.combinationSum(candidates,target);
    for(int i=0;i<ans.size();i++){
        cout<<"[ ";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}

// Time Complexity: O(k*2^N) - K is max possible subset length
// Space Complexity: O(k*N) 