#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmin(a, b) a = min(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    v<int> a(n), c;
    F0R(i,n) { // find groups
        cin >> a[i];
        if (i==0 || a[i]!=a[i-1]) {c.pb(a[i]);}
    }

    n = c.size();
    v<v<int>> dp(n,v<int>(n,INT_MAX));
    F0R(i,n) {dp[i][i] = 0;}
    FOR(sz,1,n) {
        F0R(i,n-sz) {
            int j = i+sz;
            dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1; // if both are same
            if (c[i]==c[j]) {chmin(dp[i][j],dp[i+1][j-1]+1);} // other case
        }
    } cout << dp[0][n-1] << '\n';
}