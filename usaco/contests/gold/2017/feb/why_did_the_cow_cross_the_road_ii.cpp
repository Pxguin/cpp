#include <bits/stdc++.h>
using namespace std;

#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("nocross.in","r",stdin);
	freopen("nocross.out","w",stdout);
	
	int n; cin >> n;
	vector<int> a(n),b(n);
	F0R(i,n) {cin >> a[i];}
	F0R(i,n) {cin >> b[i];}

	vector<vector<int>> dp(n+2,vector<int>(n+2,0));
	F0R(i,n+1) {
		F0R(j,n+1) {
			chmax(dp[i+1][j],dp[i][j]);
			chmax(dp[i][j+1],dp[i][j]);
			if (abs(a[i]-b[j])<=4) {chmax(dp[i+1][j+1],dp[i][j]+1);}
		}
	} cout << dp[n][n] << '\n';
}