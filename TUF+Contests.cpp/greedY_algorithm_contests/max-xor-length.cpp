// Maximum XOR Length

// Viper has mastered full stack web development and he wants to master the CP (competitive programming). So he commenced solving CP questions. Viper hates the questions which include bitwise operations as he thinks they're a headache for solving.
// While solving he encountered a query totally based on bitwise operation. He isn't inquisitive about solving, so he asks his pal (that is you) to clear up the hassle for him.
// You're given a binary string ( consisting of 0's and 1's.) of length n. You need to return the maximum length of the substring such that the XOR of the characters of that substring is maximum.
// Substring : A substring s[l, r] (1 ≤ l ≤ r ≤ n) of string s = s1s2....sn is string slsl+1....sr.




// Examples:
// Input : s = "11111"
// Output : 5
// Explanation : The maximum XOR that can be obtained from given string is 1.
// If we choose the complete string of length 5, then we get the maximum XOR as well.
// Input : s = "111111"
// Output : 5
// Explanation : The maximum XOR that can be obtained from given string is 1.
// If we choose the complete string of length 6, then we get the XOR as 0 which is not maximum.
// But if we choose the substring of length 5 (consisting of first 5 characters), then we get the XOR as 1 which is maximum.
// So maximum length with maximum XOR is 5.

// Constraints:
// 1 <= n <= 105
// s = {0, 1}


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int maxLenXOR(string s){
            int n = s.size();
            int l=-1,r=-1;
            int ones=0;
            for (char c : s) if (c == '1') ones++;
            if (ones == 0) return n;     
            if (ones & 1) return n;
            for(int i=0;i<n;i++){
                if(s[i]=='1') {
                    if(l==-1) l=i;
                    r=i;
                };
            }
            
            return n-min(l+1,n-r);
        }
};