#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pii pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	int h[3][n];
	vector<vector<int>> dp(n+1,vector<int>(3,0));
	F0R(i,n) {cin >> h[0][i] >> h[1][i] >> h[2][i];}
	F0R(i,n) {
		F0R(j,2) {
			dp[i+1][0] = max(dp[i+1][0],dp[i][j+1]+h[0][i]);
			dp[i+1][1] = max(dp[i+1][1],dp[i][(j+2)%3]+h[1][i]);
			dp[i+1][2] = max(dp[i+1][2],dp[i][1-j]+h[2][i]);
		}
	}
	cout << max(dp[n][0],max(dp[n][1],dp[n][2])) << '\n';
}