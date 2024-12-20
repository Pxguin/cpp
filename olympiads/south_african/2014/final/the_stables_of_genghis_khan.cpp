#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmin(a, b) a = min(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, k; cin >> n >> k;
    v<int> a(k+2); a[k] = 0; a[k+1] = n+1;
    F0R(i,k) {cin >> a[i];}
    sort(all(a));

    k += 2;
    v<v<ll>> dp(k,v<ll>(k,INT_MAX));
    F0R(i,k-1) { // base cases
        dp[i][i+1] = 0;
    }
    FOR(sz,2,k) {
        F0R(i,k-sz) {
            int j = i+sz;
            FOR(k1,i+1,j) {chmin(dp[i][j],dp[i][k1]+dp[k1][j]);} // root at k1
            dp[i][j] += a[j]-a[i]-1;
        }
    } cout << dp[0][k-1] << '\n';
}