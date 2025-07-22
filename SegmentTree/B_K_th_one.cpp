#include <bits/stdc++.h>
using namespace std;
//TODO: Incomplete code, needs to be completed
struct SegmentTree
{
    vector<int> value; 
    int ne = 0;
    void init(int size)
    {
        int n = 1;
        while (n < size)
            n <<= 1;
        value.assign(2 * n, ne);
    }
    void build(vector<int> &a, int lx, int rx, int x)
    {
        if (lx == rx)
        {
            if (lx < a.size())
            {
                value[x] = a[lx]; 
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
            value[x] = v;
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
    int merge(int left, int right)
    {
        return left + right; 
    }
};
