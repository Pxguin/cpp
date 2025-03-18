#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector

void solve() {
    int n; cin >> n;
    vec<vec<ll>> dp(n,vec<ll>(n,0));
    vec<vec<int>> nxt(2,vec<int>(n));
    vec<ll> a(n);
    F0R(i,n) {cin >> a[i];}
    F0R(i,n) {nxt[0][i] = (i-1+n)%n; nxt[1][i] = (i+1)%n;}

    ll ans = 0;

    for (int len=2;len<=n-1;len++) {
        for (int i=0;i<n;i++) {
            int j = (i+len)%n; // fix first two points of triangle
            
            for (int k=nxt[1][i];k!=j;k=nxt[1][k]) { // fix third point of triangle

                chmax(dp[i][j],dp[i][k]+dp[nxt[1][k]][j]); // case 1: don't draw triangle i-j-k
                chmax(dp[i][j],dp[i][nxt[0][k]]+dp[k][j]);

                ll area = a[i]*a[j]*a[k], add = 0; // case 2: draw triangle i-j-k

                if (k!=nxt[1][i]) {
                    add += dp[nxt[1][i]][nxt[0][k]];
                }
                if (k!=nxt[0][j]) {
                    add += dp[nxt[1][k]][nxt[0][j]];
                }
                chmax(dp[i][j],add+area);
            }

            chmax(ans,dp[i][j]);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}