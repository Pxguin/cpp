#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	ll mod = 1e9+7;
	char grid[n][n];
	ll dp[n+1][n+1];
	F0R(i,n) {
		F0R(j,n) {
			cin >> grid[i][j];
			dp[i][j] = 0;
		}
	} dp[0][0] = (grid[0][0]=='.');
	F0R(i,n) {
		F0R(j,n) {
			if (grid[i+1][j] != '*') {dp[i+1][j] = (dp[i+1][j]%mod)+dp[i][j];}
			if (grid[i][j+1] != '*') {dp[i][j+1] = (dp[i][j+1]%mod)+dp[i][j];}
		}
	}
	cout << dp[n-1][n-1]%mod << '\n';
} 	