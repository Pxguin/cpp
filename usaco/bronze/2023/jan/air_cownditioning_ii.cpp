#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m; cin >> n >> m;
    v<int> cool(100,0), s(n), t(n), c(n);
    F0R(i,n) {cin >> s[i] >> t[i] >> c[i];}
    F0R(i,n) { // find how much each cell needs to be cooled by
        F0R(u,100) {
            if (s[i]-1<=u && u<=t[i]-1) {cool[u] = c[i];}
        }
    }

    int ans = INT_MAX;
    v<int> a(m), b(m), p(m), m1(m);
    F0R(i,m) {cin >> a[i] >> b[i] >> p[i] >> m1[i];}
    F0R(mask,(1<<m)) {
        v<int> sub(100,0);
        int cost = 0, ok = 1;
        F0R(i,m) {
            if ((1<<i)&mask) {
                FOR(u,a[i]-1,b[i]) {sub[u] += p[i];} // find out how much each cell is cooled
                cost += m1[i];
            }
        }

        F0R(u,100) {ok &= (sub[u]>=cool[u]);} // check if each cell cooling is enough
        if (ok) {chmin(ans,cost);}
    } cout << ans << '\n';
}