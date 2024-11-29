#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int mod = 1e9+7;
void add(int& a, int b) {a = (a+b)%mod;}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    v<int> x(n);
    v<v<int>> dp(n+1,v<int>(m+2,0));
    F0R(i,n) {cin >> x[i];}

    FOR(j,1,m+1) {
        if (x[0]==0 || x[0]==j) {dp[1][j]=1;}
    }
    
    FOR(i,2,n+1) {
        FOR(j,1,m+1) {
            if (x[i-1]==0 || x[i-1]==j) {
                add(dp[i][j],dp[i-1][j-1]);
                add(dp[i][j],dp[i-1][j]);
                add(dp[i][j],dp[i-1][j+1]);
            }
        }
    }
    int ans = 0;
    F0R(i,m) {add(ans,dp[n][i+1]);}
    cout << ans << '\n';
}