#include <bits/stdc++.h>
int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= mid;
        if (ans > m) //avoid overflow for large values(automatically handles negative values as well as square root beyond range)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}
int NthRoot(int n, int m)
{
    // Code here.
    if(n==1) return m;
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int res = func(mid, n, m);
        if (res == 1)
            return mid;
        else if (res == 0)
            return low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
using namespace std;
int main()
{
    int n, m;
    // Take input for n and m
    cin >> n >> m;

    int result = NthRoot(n, m);

    // Print the result
    cout << n << "th root of " << m << " is: " << result << endl;

    return 0;
}