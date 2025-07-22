#include<bits/stdc++.h>
using namespace std;


struct SegmentTree {
    vector<pair<int,int>> value; // stores the segment tree values and count of minimums
    pair<int,int> ne = {INT_MAX, 0}; 
    void init(int size){
        int n = 1;
        while (n < size) n <<= 1; 
        value.assign(2 * n, ne); 
    }
    void build(vector<int>& a, int lx, int rx, int x){
        if(lx==rx){
            if(lx< a.size()) {
                value[x] = {a[lx], 1}; 
            }
            return;
        }
        int mid = (lx + rx) >> 1;
        build(a, lx, mid, 2 * x + 1); // left child
        build(a, mid + 1, rx, 2 * x + 2);
        value[x] = merge(value[2 * x + 1], value[2 * x + 2]); 
    }
    pair<int,int> merge(pair<int,int> left, pair<int,int> right) {
        auto [m1,c1] = left;
        auto [m2,c2] = right;
        if(m1<m2) return left; // return left if its minimum is smaller
        if(m1>m2) return right; // return right if its minimum is smaller
        return {m1, c1 + c2}; // if both minimums are equal, sum their counts
    }
    void update(int lx,int rx, int x, int i, int v){
        if(lx==rx){
            value[x]={v, 1};
            return;
        }
        int mid = (lx + rx) >> 1;
        if(i <= mid) {
            update(lx, mid, 2 * x + 1, i, v);
        } else {
            update(mid + 1, rx, 2 * x + 2, i, v); 
        }
        value[x] = merge(value[2 * x + 1], value[2 * x + 2]); 
    }
    pair<int,int> range_query(int lx, int rx, int x,int l,int r){
        if(rx<l || lx>r) return ne; // out of range
        if(lx >= l && rx <= r) return value[x]; // current segment is completely within range
        int mid = (lx + rx) >> 1;
        auto left = range_query(lx, mid, 2 * x + 1, l, r); // query left child
        auto right = range_query(mid + 1, rx, 2 * x + 2, l, r); // query right child
        return merge(left, right);
    }
};


int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,m; cin >> n >> m;
vector<int> a(n);
for(int i = 0; i < n; i++) {
    cin >> a[i];
}
SegmentTree segTree;
segTree.init(n);
segTree.build(a, 0, n - 1, 0);
while(m--){
    int type, l, r; cin >> type >> l >> r;
    if(type ==1){
        segTree.update(0,n-1, 0, l , r); 
    }
    if(type ==2){
        cout << segTree.range_query(0, n - 1, 0, l, r-1).first << " " << segTree.range_query(0, n - 1, 0, l, r-1).second << endl; 
    }
}
return 0;
}