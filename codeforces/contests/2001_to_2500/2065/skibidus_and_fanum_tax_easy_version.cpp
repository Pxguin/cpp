#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int n, m; cin >> n >> m;
    v<int> a(n), b(m);
    F0R(i,n) {cin >> a[i];}
    F0R(i,m) {cin >> b[i];}

    if (b[0]-a[0]<a[0]) {a[0] = b[0]-a[0];} // reduce a[0] as much as possible
    F0R(i,n-1) {
        if (a[i+1]>a[i] && b[0]-a[i+1]>=a[i] && b[0]-a[i+1]<a[i+1]) { // does performing the op on a_i reduce it while still keeping a_i>=a_{i-1}
            a[i+1] = b[0]-a[i+1];
        }
        if (a[i+1]<a[i] && b[0]-a[i+1]>=a[i]) { // same thing, does performing the op reduce it while still maintaining non-dec order
            a[i+1] = b[0]-a[i+1];
        }
    }
    bool flag = false;
    F0R(i,n-1) {if (a[i]>a[i+1]) {flag = true;}} // check non decreasing order
    cout << (flag ? "NO" : "YES") << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t; cin >> t;
    while (t--) {solve();}
}