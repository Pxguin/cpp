#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll l, r, g; cin >> l >> r >> g;
    l = (l+g-1)/g; r = r/g;
    tuple<ll,ll,ll> ans = {-1,1,-1};

    ll k = min(r-l+1,20LL);
    for (ll i=l;i<l+k;i++) {
        for (ll j=r;j>r-k;j--) {
            if (gcd(i,j)==1) {
                ans = max(ans,make_tuple(j-i,-i*g,j*g));
            }
        }
    }

    cout << -get<1>(ans) << ' ' << get<2>(ans) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}