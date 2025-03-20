#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    v<int> c(n);
    v<v<int>> dp(n,v<int>(n,1e9));
    F0R(i,n) {cin >> c[i];}
    F0R(i,n) { // base cases
        F0R(j,i+1) {dp[i][j]=1;}
        if (i) {dp[i-1][i]=(c[i-1]!=c[i])+1;}
    }
    FOR(sz,2,n) {
        F0R(i,n-sz) {
            int j = i+sz;
            FOR(k,i,j) {chmin(dp[i][j],dp[i][k]+dp[k+1][j]);} // don't pair up any letters (independent ranges)
            if (c[i]==c[j]) {chmin(dp[i][j],dp[i+1][j-1]);} // pair up first and last letters
        }
    } cout << dp[0][n-1] << '\n';
}