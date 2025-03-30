#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll n, k; cin >> n >> k;
    ll last = -1e10, ans = 0;
    for (int i=0;i<n;i++) {
        ll a; cin >> a;
        ans += min(a-last,k+1); // a-last: extend last subscription; k+1: start new subscription
        last = a;
    } cout << ans << '\n';
}