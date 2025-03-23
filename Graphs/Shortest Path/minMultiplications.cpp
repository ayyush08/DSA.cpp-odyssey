// Minimum multiplications to reach end
// Given start, end, and an array arr of n numbers. At each step, the start is multiplied by any number in the array and then a mod operation with 100000 is done to get the new start.
// Find the minimum steps in which the end can be achieved starting from the start. If it is not possible to reach the end, then return -1.

// Examples:
// Input: arr = [2, 5, 7], start = 3, end = 30
// Output: 2
// Explanation:
// Step 1: 3*2 = 6 % 100000 = 6
// Step 2: 6*5 = 30 % 100000 = 30
// Therefore, in minimum 2 multiplications, we reach the end number which is treated as a destination node of a graph here.

// Input: arr = [3, 4, 65], start = 7, end = 66175
// Output: 4
// Explanation:
// Step 1: 7*3 = 21 % 100000 = 21
// Step 2: 21*3 = 6 % 100000 = 63
// Step 3: 63*65 = 4095 % 100000 = 4095
// Step 4: 4095*65 = 266175 % 100000 = 66175
// Therefore, in minimum 4 multiplications we reach the end number which is treated as a destination node of a graph here.

// Approach: Treat each multiplication result as a node and each multiplication as an edge. We will use Dijkstra's algorithm but with queue instead of priority queue as we need to keep track of the number of steps taken and queue will store in increasing order. We will keep track of the number of steps taken to reach the end number. If the end number is reached, we will return the number of steps taken. If the end number is not reached, we will return -1. The total size of distance array will be 100000 .


#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int minimumMultiplications(vector<int> &arr,
                                   int start, int end) {
            if(start==end) return 0;
            int mod =100000;
            vector<int>dist(mod,1e9);
    
            queue<pair<int,int>>q;
            q.push({0,start});
            dist[start]=0;
    
            while(!q.empty()){
                int node = q.front().second;
                int dis = q.front().first;
                q.pop();
                for(auto it:arr){
                    int num = (it*node)%mod;
                    if(num==end) return dis+1;
                    if(dis+1<dist[num]){
                    dist[num]=dis+1;
                    q.push({dis+1,num});
                    }
                }
            }
            return -1;              
        }
    };

int main(){
    vector<int> arr = {2, 5, 7};
    int start = 3, end = 30;
    Solution obj;
    cout << obj.minimumMultiplications(arr, start, end) << endl;
    return 0;
}