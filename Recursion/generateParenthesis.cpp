// Given an integer n.Generate all possible combinations of well-formed parentheses of length 2 x N.


// Example 1
// Input : n = 3
// Output : [ "((()))" , "(()())" , "(())()" , "()(())" , "()()()" ]

// Example 2
// Input : 2
// Output : [ "(())" , "()()" ]

// Example 3
// Input : 1
// Output:
// ()

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void generate(int index,string st,int open,int close,vector<string> &ans,int n){
        if(open>n) return;
        if((open+close)==2*n&&open==close){
            ans.push_back(st);
            return;
        }
        generate(index+1,st+'(',open+1,close,ans,n);
        if(open>close)
        generate(index+1,st+')',open,close+1,ans,n);


    }
    vector<string> generateParenthesis(int n) {
        //your code goes here
        vector<string>ans;
        generate(0,"",0,0,ans,n);
        return ans;

    }
};

int main(){
    int n;
    cout << "Enter the value of n: ";
    cin>>n;
    Solution obj;
    vector<string>ans=obj.generateParenthesis(n);
    for(auto x:ans){
        cout<<x<<endl;
    }
    return 0;
}