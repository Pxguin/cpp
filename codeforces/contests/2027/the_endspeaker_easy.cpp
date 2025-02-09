#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

void solve() {
    int n, m; cin >> n >> m;
    v<int> a(n+1), b(m);
    F0R(i,n) {cin >> a[i];}
    F0R(i,m) {cin >> b[i];}

    v<v<ll>> dp(n+1,v<ll>(m+1,LLONG_MAX));
    dp[0][0] = 0;
    v<ll> ps(n+1,0);
    F0R(i,n) {ps[i+1] += ps[i]+a[i];}
    F0R(i,n) {
        F0R(j,m) {
            if (dp[i][j]==LLONG_MAX) {continue;}
            chmin(dp[i][j+1],dp[i][j]); // increase k

            int idx = upper_bound(all(ps),b[j]+ps[i])-ps.begin()-1; // get max prefix sum transition
            chmin(dp[idx][j],dp[i][j]+m-j-1);
        }
    }

    ll ans = LLONG_MAX;
    F0R(i,m) {chmin(ans,dp[n][i]);}
    cout << (ans==LLONG_MAX ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}