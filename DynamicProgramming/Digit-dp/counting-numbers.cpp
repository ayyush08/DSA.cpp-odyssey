// CSES - Counting Numbers

// Time limit: 1.00 s
// Memory limit: 512 MB

// Your task is to count the number of integers between a and b where no two adjacent digits are the same.
// Input
// The only input line has two integers a and b.
// Output
// Print one integer: the answer to the problem.
// Constraints

// 0 \le a \le b \le 10^{18}

// Example
// Input:
// 123 321

// Output:
// 171

//States: idx, tight, prev_digit, leading_zero (4th state optional but required here to handle leading zeros properly. Ex: 00123 but 0030045 is not valid so leading zeros matter)
//Transitions: 0-9 digits
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[2][11][20][2]; //tight, prev_digit, idx, leading_zero

ll func(string &s,ll tight,ll prev_digit, ll idx,bool leading_zero){
    if(idx==s.size()) return 1;

    if(dp[tight][prev_digit][idx][leading_zero] != -1) return dp[tight][prev_digit][idx][leading_zero];

    ll lb = 0;
    ll ub = tight ? (s[idx]-'0') : 9;
    ll res = 0;

    for(ll digit = lb;digit <= ub; digit++){
        if(digit==prev_digit && !leading_zero) continue; // invalid case
         // once we place a non zero digit leading zero becomes false
        res += func(s,(tight && digit==ub),digit,idx+1,(leading_zero && digit==0)); // update leading zero state
    }
    return dp[tight][prev_digit][idx][leading_zero] = res;
}


ll solve(ll a,ll b){
    string left = to_string(a-1);
    string right = to_string(b);
    //-1 previous number to handle inclusive range can also take other digit not in 0-9 range
    //leading zeroes true initially because we have not placed any digit yet
    memset(dp,-1,sizeof(dp));
    ll leftAns = func(left,1,10,0,true);
    memset(dp,-1,sizeof(dp));
    ll rightAns = func(right,1,10,0,true);
    return rightAns - leftAns;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a,b;
    cin>>a>>b;

    cout<<solve(a,b)<<"\n";

    return 0;
}