#include <bits/stdc++.h>
using namespace std;
#define int long long

struct SegmentTree
{
    vector<array<int,4>> value; //{value, prefixSum, suffixSum, maxSum}
    int ne = 0;
    void init(int size)
    {
        int n = 1;
        while (n < size)
            n <<= 1;
        value.assign(2 * n, {ne, ne, ne, ne});
    }
    void build(vector<int> &a, int lx, int rx, int x)
    {
        if (lx == rx)
        {
            if (lx < a.size())
            {
                value[x] = {a[lx], a[lx], a[lx], a[lx]}; 
            }
            return;
        }
        int mid = (lx + rx) >> 1;
        build(a, lx, mid, 2 * x + 1);
        build(a, mid + 1, rx, 2 * x + 2);
        value[x] = merge(value[2 * x + 1], value[2 * x + 2]);
    }
    void update(int lx, int rx, int x, int i, int v)
    {
        if (lx == rx)
        {
            value[x] = {v, v, v, v}; 
            return;
        }
        int mid = (lx + rx) >> 1;
        if (i <= mid)
        {
            update(lx, mid, 2 * x + 1, i, v);
        }
        else
        {
            update(mid + 1, rx, 2 * x + 2, i, v);
        }
        value[x] = merge(value[2 * x + 1], value[2 * x + 2]);
    }
    array<int, 4> merge(array<int, 4> left, array<int, 4> right)
    {
        array<int, 4> result;
        result[0] = left[0] + right[0]; // total sum
        result[1] = max(left[1], left[0] + right[1]); // max prefix sum(either could be current left or entire previous left + current right)
        result[2] = max(right[2], right[0] + left[2]); // max suffix sum (either could be current right or entire previous right + current left)
        result[3] = max({left[3], right[3], left[2] + right[1]}); // max subarray sum 
        return result;
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    SegmentTree segTree;
    segTree.init(n);
    segTree.build(a, 0, n - 1, 0);
    cout << max(0LL, segTree.value[0][3]) << '\n';
    while(m--){
        int i,v;
        cin >> i >> v;
        segTree.update(0, n - 1, 0, i, v);
        cout << max(0LL, segTree.value[0][3]) << '\n';
    }
}