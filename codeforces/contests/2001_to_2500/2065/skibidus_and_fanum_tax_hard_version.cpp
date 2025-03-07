#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

void solve() {
    int n, m; cin >> n >> m;
    v<int> a(n), b(m);
    F0R(i,n) {cin >> a[i];}
    F0R(i,m) {cin >> b[i];}
    sort(all(b));

    if (b[0]-a[0]<a[0]) {a[0] = b[0]-a[0];}
    F0R(i,n-1) {
        int idx = lower_bound(all(b),a[i]+a[i+1])-b.begin(); // binary search on best candidate for b
        if (idx!=b.size()) { // repeat the casework from the easy version
            if (a[i+1]>a[i] && b[idx]-a[i+1]<a[i+1]) {
                a[i+1] = b[idx]-a[i+1];
            }
            if (a[i+1]<a[i]) {
                a[i+1] = b[idx]-a[i+1];
            }
        }
    }
    bool flag = false;
    F0R(i,n-1) {if (a[i]>a[i+1]) {flag = true;}}
    cout << (flag ? "NO" : "YES") << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t; cin >> t;
    while (t--) {solve();}
}