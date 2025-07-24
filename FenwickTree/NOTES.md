# Fenwick Tree

- 1-indexed array
- Fenwick Tree is a data structure that allows efficient updates and queries on prefix sums.
- stores prefix sums in 2^k intervals, allowing for efficient range queries. Take prefix sum of 2^k elements, skip to next 2^k element, and repeat.

Example:
```cpp
vector<int>a = {5,6,9,10,12,15,24,3,5,4,2,12,11,5,8};

//Fenwick Tree array - [5,11,9,30,12,27,16,97,3,8,4,14,12,23,5,147] 
```

Building the Fenwick Tree:
```cpp
int prefSum(int ind, vector<int>& fenwickTree) {
    int sum = 0;
    while(ind>0){
        sum+=fenwickTree[ind];
        ind-=(ind & (-ind)); // Move to the parent index (subtracting the last set bit)
    }
    return sum;
}

void update(int ind, int val, vector<int>& fenwickTree) {3
    while(ind <= fenwickTree.size()) {
        fenwickTree[ind] += val;
        ind += (ind & (-ind)); // Move to the next index (adding the last set bit)
    }
}

void buildFenwickTree(vector<int>& a, vector<int>& fenwickTree) {
    for(int i = 0; i < a.size(); i++) {
        update(i + 1, a[i], fenwickTree); // 1-indexed
    }
}
```