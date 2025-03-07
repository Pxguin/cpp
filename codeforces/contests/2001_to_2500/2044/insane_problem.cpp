#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;

    ll ans = 0;
    for (ll i=1;i<=1e9;i*=k) { // all powers
        ll mn = (l2+i-1)/i, mx = r2/i; // mn mx possible for x such that there's a valid y
        ans += max(0LL,min(mx,r1)-max(mn,l1)+1); // intersection of that range with what we're given
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}