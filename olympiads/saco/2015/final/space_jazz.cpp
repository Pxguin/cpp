#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	string s; cin >> s;
	int n = s.size();
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));

	FOR(i,1,n+1) {
		F0R(j,n-i+1) {
			dp[j][j+i-1]=dp[j+1][j+i-1]+1; // don't pair up
			FOR(k,1,i) {
				if (s[j]==s[k+j]) { // try pairing up
					dp[j][j+i-1]=min(dp[j][j+i-1],dp[j+1][k+j-1]+dp[k+j+1][j+i-1]);
				}
			}
		}
	} cout << dp[0][n-1] << '\n';
}