#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, k; cin >> n >> k;
    v<int> val(n), b(n);
    F0R(i,n) {cin >> val[i];}
    F0R(i,n) {cin >> b[i];}

    v<v<ll>> dp(n,v<ll>(n,0));
    FOR(sz,1,n) {
        F0R(i,n-sz) {
            int j = i+sz;
            FOR(k,i,j) {chmax(dp[i][j],dp[i][k]+dp[k+1][j]);}
            if (b[i]+k==b[j]) {chmax(dp[i][j],dp[i+1][j-1]+val[i]+val[j]);}
        }
    } cout << dp[0][n-1] << '\n';
}