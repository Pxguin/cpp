#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll n, m; cin >> n >> m;
    v<ll> dp;
    F0R(i,n) {
        ll a; cin >> a;
        ll val = m*(i+1)-a;
        if (val>=0) {
            int pos = upper_bound(all(dp),val)-dp.begin();
            if (pos==dp.size()) {dp.pb(val);}
            else {dp[pos] = val;}
        }
    } cout << n-dp.size() << '\n';
}