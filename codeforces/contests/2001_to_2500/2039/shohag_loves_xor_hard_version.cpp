#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll x, m; cin >> x >> m;
    ll ans = 0;
    for (int i=1;i<=min(m,x);i++) { // brute force
        ans += ((x^i)%i==0);
    }
    if (m>x) {
        m++; // this calculates number of y such that x^y<m, so increment m by 1
        ll cur = 0;
        for (int bit=60;bit>=0;bit--) {
            if ((1LL<<bit)&m) {
                bool b = (1LL<<bit)&x;
                ll lb = max(x+1,cur^((ll)b<<bit)), ub = cur|((1LL<<(bit+b))-1);
                lb = (lb+x-1)/x, ub = ub/x;
                ans += max(0LL,ub-lb+1);
                if (!b) {cur ^= (1LL<<bit);}
            } else {
                if ((1LL<<bit)&x) {cur ^= (1LL<<bit);}
            }
        }
    } cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}