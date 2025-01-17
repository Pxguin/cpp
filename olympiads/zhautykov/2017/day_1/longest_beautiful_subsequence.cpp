#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

pii dp[1<<10][1<<10][21];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<int> a(n), k(n);
    v<pii> ans(n);
    F0R(i,n) {cin >> a[i];}
    F0R(i,n) {cin >> k[i];}

    F0R(i,n) {
        int l = 0, r = 0;
        F0R(j,10) { // calc right half
            if (a[i]&(1<<j)) {r |= (1<<j);}
        }

        F0R(j,10) { // calc left half
            if (a[i]&(1<<(j+10))) {l |= (1<<j);}
        }

        pii best = {0,-1};
        F0R(j,1<<10) { // get answer for i
            pii cmp = dp[j][r][k[i]-__builtin_popcount(j&l)];
            if (cmp.f>best.f) {best = cmp;}
        }

        best.f++;
        ans[i] = best;
        best.s = i;

        F0R(j,1<<10) { // update dp
            pii& to = dp[l][j][__builtin_popcount(j&r)];
            if (best.f>to.f) {to = best;}
        }
    }
    v<int> idx;
    int mx = 0;
    F0R(i,n) { // restore sequence
        if (ans[i].f>ans[mx].f) {mx = i;}
    }
    while (mx!=-1) {
        idx.pb(mx+1);
        mx = ans[mx].s;
    }
    cout << idx.size() << '\n';
    for (int i=idx.size()-1;i>=0;i--) {cout << idx[i] << ' ';}
}