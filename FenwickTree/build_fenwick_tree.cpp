#include <bits/stdc++.h>
using namespace std;

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


int main(){
    vector<int>a = {5,6,9,10,12,15,16,24,3,5,4,2,12,11,5,8};

    FenwickTree ft;
    ft.init(a.size());
    ft.buildFenwickTree(a);

    for (int i = 0; i < ft.fenwick.size(); i++) {
    cout << "fenwick[" << i << "] = " << ft.fenwick[i] << endl;
}

}