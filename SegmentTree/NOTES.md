# Segment Tree
A segment tree is a  complete binary tree used for storing intervals or segments. It allows querying which segments overlap with a given point or interval efficiently.

Total Nodes: ```2n - 1``` (when size of array is power of 2)
If not in power of 2, then the last level will not be completely filled, so we add neutral elements to fill it up (say 0 for sum, infinity for min, -infinity for max).

Size of Segment Tree(may or may not be power of 2): ```2*(power of 2 greater than or equal to n)```

## Operations

1. Query(l,r): Find the value of the segment from index l to r.
2. Update(index, value): Update the value at a specific index and propagate the change up the tree.

## How to Build
1. Start with an array of size `2*(power of 2 greater than or equal to n)`.
2. And build the tree with  2i+1 and 2i+2 as left and right children respectively.

- Each node has a value that represents the segment it covers in the original array and its 2 children nodes.
- The root node represents the entire array.

- [l,r] has a midpoint `m = (l + r) / 2`.
 the left child will cover the segment `[l, m]` and the right child will cover `[m+1, r]`.


Pseudo Code recursion for building the segment tree for sum:

```cpp
void build(vector<int>& a,int lx,int rx,int x){
    if(lx==rx){ //base case: leaf node
        if(lx < a.size()) {
            value[x] = a[lx];
        }
        return;
    }
    int mid = (lx + rx) >> 1;
    build(a, lx, mid, 2*x + 1); // left child
    build(a, mid + 1, rx, 2*x + 2); // right child
    value[x] = value[2*x + 1] + value[2*x + 2]; // combine results
    //or call merge function
    // value[x] = merge(value[2*x + 1], value[2*x + 2]); // for min/max
}
```

Build in struct, there will be an init function to compute the size of the segment tree based on the input array size and then call the build function.

```cpp

struct SegmentTree {
    vector<int> value; // stores the segment tree values

    void init(int size);
    void build(vector<int>& a, int lx, int rx, int x);
    int merge(int left, int right) {
        return left + right; // for sum
        return min(left, right); // for min
        return max(left, right); // for max
    }
    
};
void init(int size){
    int n = 1;
    while(n<size) n <<= 1; // find next power of 2
    value.assign(2*n, 0);
}