#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("pieaters.in","r",stdin);
    freopen("pieaters.out","w",stdout);

    int n, m; cin >> n >> m;
    int w, a, b;
    v<v<pii>> l(n), r(n);
    v<v<ll>> dp(n,v<ll>(n,0));
    v<v<v<int>>> mx(n,v<v<int>>(n,v<int>(n,0)));

    F0R(i,m) {
        cin >> w >> a >> b;
        l[--a].pb({--b,w});
        r[b].pb({a,w});
        dp[a][b] = w;
        FOR(k,a,b+1) {chmax(mx[a][b][k],w);}
    }

    FOR(sz,1,n) {
        F0R(i,n-sz) {
            int j = i+sz;
            FOR(k,i,j) {chmax(dp[i][j],dp[i][k]+dp[k+1][j]);} // transition 1
            F0R(k,n) {chmax(mx[i][j][k],max(mx[i+1][j][k],mx[i][j-1][k]));} // update mx array

            for (pii x : l[i]) { // extend on left side (much easier by using mx array, but I had already written this code so whatever)
                if (x.f<=j) {chmax(dp[i][j],dp[i+1][j]+x.s);}
            }

            for (pii x : r[j]) { // extend on right side
                if (x.f>=i) {chmax(dp[i][j],dp[i][j-1]+x.s);}
            }

            FOR(k,i+1,j) {chmax(dp[i][j],dp[i][k-1]+mx[i][j][k]+dp[k+1][j]);} // extend one unit in middle somewhere
        }
    }
    cout << dp[0][n-1] << '\n';
}