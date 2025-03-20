#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 5e5;
v<int> divs[MAX_N+1];

void solve() {
    int n; cin >> n;
    v<int> p(n), q(n);

    F0R(i,n) {
        cin >> p[i];
        int g = gcd(p[i],i+1);
        q[i] = (i+1)/g; p[i] /= g;

    }

    v<v<int>> grp_q(n+1), grp_p(n+1); // group by p and q
    F0R(i,n) {
        grp_q[q[i]].pb(p[i]);
        grp_p[p[i]].pb(q[i]);
    }

    ll ans = 0;
    ans -= grp_q[1].size(); // will double count if p = 1, q = 1

    v<int> freq(n+1,0);
    FOR(q1,1,n+1) { // fix q
        for (int p1=q1;p1<=n;p1+=q1) { // for all p_j that divide q, update q_j freq array
            for (int q2 : grp_p[p1]) {freq[q2]++;}
        }
        for (int p1 : grp_q[q1]) { // go through all divs of all p_i with q_i=q
            for (int d : divs[p1]) {ans += freq[d];}
        }
        for (int p1=q1;p1<=n;p1+=q1) { // reset q_j freq array
            for (int q2 : grp_p[p1]) {freq[q2] = 0;}
        }
    } cout << ans/2 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    FOR(i,1,MAX_N+1) {
        for (int j=i;j<=MAX_N;j+=i) {divs[j].pb(i);}
    }
    int t; cin >> t;
    while (t--) {solve();}
}