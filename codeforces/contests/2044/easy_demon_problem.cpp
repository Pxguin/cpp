#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, q; cin >> n >> m >> q;
    v<int> a(n), b(m);
    ll sa = 0, sb = 0;
    F0R(i,n) {cin >> a[i]; sa += a[i];}
    F0R(i,m) {cin >> b[i]; sb += b[i];}

    set<ll> a_cand, b_cand;
    F0R(i,n) {a_cand.insert(sa-a[i]);} // all possible sums
    F0R(i,m) {b_cand.insert(sb-b[i]);}

    v<int> ok(2e5+2e5+1,0);
    v<v<int>> div(2e5+1);
    FOR(i,1,2e5+1) { // precalc queries
        for (int j=i;j<=2e5;j+=i) {div[j].pb(i);}

        for (int d : div[i]) { // go through all divisors
            int d2 = i/d;
            bool a1 = a_cand.count(d), a2 = a_cand.count(-d); // check if valid pair exists
            bool b1 = b_cand.count(d2), b2 = b_cand.count(-d2);
            ok[i+2e5] |= (a1 && b1); // positive X
            ok[i+2e5] |= (a2 && b2);
            ok[-i+2e5] |= (a1 && b2); // negative X
            ok[-i+2e5] |= (a2 && b1);
        }
    }
    while (q--) {
        int x; cin >> x;
        cout << (ok[x+2e5] ? "YES" : "NO") << '\n';
    }
}