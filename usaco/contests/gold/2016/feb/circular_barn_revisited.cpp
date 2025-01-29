#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	freopen("cbarn2.in","r",stdin);
	freopen("cbarn2.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, x; cin >> n >> x; x = min(x,n);
	int a[n];

	for (int i=0;i<n;i++) {cin >> a[i];}
	vector<vector<ll>> forward(n,vector<ll>(n,0));
	//vector<vector<ll>> backward(n,vector<ll>(n,0));

	// precalculate prefix sums
	for (int i=0;i<n;i++) {
		for (int j=1;j<n;j++) {forward[i][j] = forward[i][j-1]+j*a[(j+i)%n];}
		//for (int j=1;j<n;j++) {backward[i][j] = backward[i][j-1]+j*a[(i+n-j)%n];}
	}
	ll ans = LLONG_MAX;

	for (int i=0;i<n;i++) {
		vector<vector<ll>> dp(n+1, vector<ll>(x+2,1e15));
		dp[0][0] = 0;
		for (int j=0;j<n;j++) {
			for (int k=0;k<=x;k++) {
				for (int l=0;l<n;l++) {
					if (j+l+1<=n) {
						dp[j+l+1][k+1] = min(dp[j+l+1][k+1], dp[j][k]+(forward[(i+j)%n][l]));
					}
				}
			}
		}
		ans = min(ans, dp[n][x]);
	}
	cout << ans << '\n';
}