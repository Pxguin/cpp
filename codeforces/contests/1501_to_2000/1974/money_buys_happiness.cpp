#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int m, x; cin >> m >> x;
    v<pii> month(m);
    F0R(i,m) {cin >> month[i].f >> month[i].s;}
    
    int tot = 0;
    F0R(i,m) {tot += month[i].s;}
    v<v<ll>> dp(m+1,v<ll>(tot+1,-1));
    
    dp[0][0] = 0;
    F0R(i,m) {
        F0R(j,tot+1) {
            if (dp[i][j]==-1) {continue;}
            chmax(dp[i+1][j],dp[i][j]+x); // do not buy
            if (dp[i][j]>=month[i].f) {chmax(dp[i+1][j+month[i].s],dp[i][j]-month[i].f+x);} // buy
        }
    }
    int ans;
    F0R(i,tot+1) {if (dp[m][i]!=-1) {ans = i;}} // max happiness possible
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}