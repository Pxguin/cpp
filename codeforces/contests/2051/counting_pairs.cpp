#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

void solve() {
    int n; ll x, y; cin >> n >> x >> y;
    v<ll> a(n);
    F0R(i,n) {cin >> a[i];}
    
    ll tot = 0;
    F0R(i,n) {tot += a[i];}
    sort(all(a));
    ll ans = 0;

    while (a.size()>1) {
        int v = a.back(); a.pop_back();
        int rb = upper_bound(all(a),tot-v-x)-a.begin()-1; // upper bound
        int lb = lower_bound(all(a),tot-v-y)-a.begin(); // lower bound
        if (lb<=rb && lb!=a.size()) {ans += rb-lb+1;}
    } cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}