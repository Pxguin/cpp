#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    v<int> x(n);
    F0R(i,n) {cin >> x[i];}

    bool flag = true;
    F0R(i,n) { // add drop at position 0 (if it doesn't exist already)
        if (x[i]==0) {flag = false;}
    } if (flag) {x.pb(0); n++;}
    sort(all(x));

    int idx = -1;
    F0R(i,n) {if (x[i]==0) {idx = i;}}

    v<v<v<int>>> l(n,v<v<int>>(n,v<int>(n+1,1e9))), r=l; // dp (start on left/right of range)
    F0R(i,n) { // base cases
        FOR(j,i,n) {l[i][j][1] = r[i][j][1] = 0;}
    }
    for (int sz=n-2;sz>=0;sz--) {
        F0R(i,n-sz) {
            int j = i+sz;
            FOR(k,2,n+1) {
                if (i) { // extend on left side
                    chmin(l[i][j][k],l[i-1][j][k-1]+(k-1)*(x[i]-x[i-1]));
                    chmin(r[i][j][k],l[i-1][j][k-1]+(k-1)*(x[j]-x[i-1]));
                }
                if (j<n-1) { // extend on right side
                    chmin(l[i][j][k],r[i][j+1][k-1]+(k-1)*(x[j+1]-x[i]));
                    chmin(r[i][j][k],r[i][j+1][k-1]+(k-1)*(x[j+1]-x[j]));
                }
                
            }
        }
    }
    int ans = (!flag)*m;
    F0R(i,n+1) { // calc ans
        chmax(ans,(i-flag)*m-l[idx][idx][i]);
    } cout << ans << '\n';
}