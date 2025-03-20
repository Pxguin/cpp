#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n; cin >> n;
    ll b[n];
    for (int i=0;i<n;i++) {cin >> b[i];}
    vector<vector<ll>> dp(n+1,vector<ll>(4,0));
    for (int i=0;i<n;i++) {
        for (int j=0;j<=3;j++) {dp[i+1][j] = max(dp[i][j]-(j<3),dp[i+1][j]);}
        for (int j=0;j<=2;j++) {dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+b[i]-1);}
    } cout << dp[n][3]+1 << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {solve();}
}