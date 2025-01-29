#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    v<int> a(n);
    F0R(i,n) {cin >> a[i];}

    v<v<int>> dp(n,v<int>(n,INT_MAX));
    F0R(i,n) {dp[i][i] = 1;}
    F0R(i,n-1) {dp[i][i+1] = (a[i]!=a[i+1])+1;}

    FOR(sz,2,n) {
        F0R(i,n-sz) {
            int j = i+sz;
            FOR(k,i,j) {chmin(dp[i][j],dp[i][k]+dp[k+1][j]);} // combine ranges
            chmin(dp[i][j],dp[i+1][j]+(a[i]!=a[i+1]&&a[i]!=a[j])); // extend on left side
            chmin(dp[i][j],dp[i][j-1]+(a[j]!=a[j-1]&&a[j]!=a[i])); // only on right side
        }
    }
    cout << dp[0][n-1] << '\n';
}