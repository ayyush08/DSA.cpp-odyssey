#include <bits/stdc++.h>
using namespace std;

struct SegmentTree{
    vector<int> tree;

    void init(int size){
        int n = 1;
        while(n < size) n <<= 1;
        tree.assign(2*n, 0);
    }
    void build(vector<int>& arr, int left, int right,int idx){
        if(left==right) {
            if(left < arr.size()){
                tree[idx] = arr[left];
            }
            return;
        }
        int mid = (left + right) >> 1;
        build(arr, left, mid, 2*idx + 1);
        build(arr, mid + 1, right, 2*idx + 2);
        tree[idx] = tree[2*idx + 1] + tree[2*idx + 2];
    }
    void update(int left, int right, int idx, int pos, int val){
        if(left==right){
            tree[idx] = val;
            return;
        }
        int mid = (left + right) >> 1;
        if(pos <= mid){
            update(left, mid, 2*idx + 1, pos, val);
        } else {
            update(mid + 1, right, 2*idx + 2, pos, val);
        }
        tree[idx] = tree[2*idx + 1] + tree[2*idx + 2];
    }
    int range_query(int left, int right, int idx, int l, int r){
        if(right < l || left > r) return 0;
        if(left >= l && right <= r) return tree[idx];
        int mid = (left + right) >> 1;
        int left_sum = range_query(left, mid, 2*idx + 1, l, r);
        int right_sum = range_query(mid + 1, right, 2*idx + 2, l, r);
        return left_sum + right_sum;
    }


};

int main(){
    cout << "Segment Tree Example" << endl;
    SegmentTree segTree;
    vector<int> a = {2,3,4,5,1,3};
    segTree.init(a.size());
    segTree.build(a, 0, a.size() - 1, 0);
    cout << "Segment tree built successfully." << endl;
    for(int val : segTree.tree){
        cout << val << " ";
    }
    return 0;
}