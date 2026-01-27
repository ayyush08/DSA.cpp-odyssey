#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int x; cin >> x;
        int mini = *min_element(a.begin(), a.end());
        int maxi = *max_element(a.begin(), a.end());
        if(x >= mini && x <= maxi) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}