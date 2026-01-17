#include<bits/stdc++.h>
using namespace std;



struct SegmentTree {
    vector<int> value; // stores the segment tree values
    int ne = 0; // neutral element for merge operation
    void init(int size){
        int n = 1;
        while (n < size) n <<= 1;  // next power of 2 for size
        value.assign(2 * n, ne); //0 for neutral element
    }
    void build(vector<int>& a, int lx, int rx, int x){
        if(lx==rx){
            if(lx< a.size()) {
                value[x] = a[lx]; // leaf node
            }
            return;
        }
        int mid = (lx + rx) >> 1;
        build(a, lx, mid, 2 * x + 1); // left child
        build(a, mid + 1, rx, 2 * x + 2);
        value[x] = merge(value[2 * x + 1], value[2 * x + 2]); 
    }
    int merge(int left, int right) {
        return left + right; // for sum
        
    }
    void update(int lx,int rx, int x, int i, int v){
        if(lx==rx){
            value[x]=v;
            return;
        }
        int mid = (lx + rx) >> 1;
        if(i <= mid) {
            update(lx, mid, 2 * x + 1, i, v); // left child
        } else {
            update(mid + 1, rx, 2 * x + 2, i, v); // right child
        }
        value[x] = merge(value[2 * x + 1], value[2 * x + 2]); // update current node
    }
    int range_query(int lx, int rx, int x,int l,int r){ //this function returns the sum in the range [l, r]
        if(rx<l || lx>r) return ne; // out of range
        if(lx >= l && rx <= r) return value[x]; // current segment is completely within range
        int mid = (lx + rx) >> 1;
        int left = range_query(lx, mid, 2 * x + 1, l, r); // query left child
        int right = range_query(mid + 1, rx, 2 * x + 2, l, r); // query right child
        return merge(left, right);
    }
};


int main(){
    cout << "Segment Tree Example" << endl;
    SegmentTree segTree;
    vector<int> a = {2,3,4,5,1,3};
    segTree.init(a.size());
    segTree.build(a, 0, a.size() - 1, 0);
    cout << "Segment tree built successfully." << endl;
    cout << "Root value: " << segTree.value[0] << endl; // should print the sum of the array
    segTree.update(0, a.size() - 1, 0, 2, 10); // update index 2 to value 10
    cout << "Updated root value: " << segTree.value[0] << endl;

    int l = 1, r = 4; // range query from index 1 to 4
    int result = segTree.range_query(0, a.size() - 1, 0, l, r);
    cout << "Range query result from index " << l << " to " << r << " is: " << result << endl; // should print the sum of elements from index 1 to 4
    return 0;
}

//Time Complexity: O(log n) as we build the tree in a single pass and the function gets called recursively for each node.
//Space Complexity: O(log n) for storing the segment tree values.




