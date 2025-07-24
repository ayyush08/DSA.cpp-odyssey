#include<bits/stdc++.h>
using namespace std;

#define int long long

struct FenwickTree
{
    vector<int> fenwick;
    void init(int n){
        fenwick.assign(n+1,0);
    }
    int prefSum(int ind)
    {
        int sum = 0;
        while (ind > 0)
        {
            sum += fenwick[ind];
            ind -= (ind & (-ind)); // Move to the parent index (subtracting the last set bit)
        }
        return sum;
    }

    void update(int ind, int val)
    {
        while (ind < fenwick.size())
        {
            fenwick[ind] += val;
            ind += (ind & (-ind)); // Move to the next index (adding the last set bit)
        }
        
    }

    void buildFenwickTree(vector<int> &a)
    {
        for (int i = 0; i < a.size(); i++)
        {
            update(i + 1, a[i]); // 1-indexed
        }
    }
};


signed main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,q; cin >> n >> q;

vector<int> a(n);
for(int i=0;i<n;i++) cin >> a[i];
FenwickTree ft;
ft.init(a.size());
ft.buildFenwickTree(a);

while(q--){
    int type,k,u;
    cin >> type >> k >> u;
    if(type==1){
        //Since here replacing k to u
        int diff = u-a[k-1]; // Calculate the difference for the update
        a[k-1]=u; // Update the original array
        ft.update(k,diff); // Update the Fenwick Tree
    }
    if(type==2){
        cout << ft.prefSum(u)-ft.prefSum(k-1)<< '\n';
    }
}
return 0;
}