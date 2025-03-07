#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(),x.end()
#define v vector

void solve() {
    int n, m; cin >> n >> m;
    v<ll> sums(n,0);
    ll ans = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            ll a; cin >> a;
            ans += a*(m-j);
            sums[i] += a;
        }
    } sort(all(sums),greater<>());
    for (int i=0;i<n;i++) { // greedily assign larger sum arrays first
        ans += sums[i]*(n-i-1)*m;
    } cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t; cin >> t;
    while (t--) {solve();}
}