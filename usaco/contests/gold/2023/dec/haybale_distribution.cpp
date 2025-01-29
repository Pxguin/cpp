#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    v<ll> x(n), ps(1e6+2,0), ss(1e6+2,0), num(1e6+2,0);
    F0R(i,n) {cin >> x[i];}
    for (int i : x) {ps[i]+=i; ss[i]+=i; num[i]++;} // prefix sums and suffix sums
    F0R(i,1e6+1) {ps[i+1] += ps[i]; num[i+1] += num[i];}
    for (int i=1e6;i>=0;i--) {ss[i] += ss[i+1];}

    auto get = [&](ll a, ll b, ll y) { // how many wasted haybales if we place at pos y
        return a*(y*num[y]-ps[y]) + b*(ss[y+1]-y*(n-num[y]));
    };

    int q; cin >> q;
    while (q--) {
        ll a, b; cin >> a >> b;
        int l = 0, h = 1e6, m1 = l+(h-l)/3, m2 = h-(h-l)/3; // ternary search on minimum
        while (l<h-2) {
            ll v1 = get(a,b,m1), v2 = get(a,b,m2);

            if (v1 == v2) {l = m1; h = m2;}
            else if (v1 < v2) {h = m2;}
            else {l = m1;}
            m1 = l+(h-l)/3; m2 = h-(h-l)/3;
        }
        cout << min(get(a,b,l),min(get(a,b,l+1),get(a,b,h))) << '\n';
    }
}