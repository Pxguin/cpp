#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define f first
#define s second
#define mp make_pair

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	pll a[n];
	ll x;
	ll fives, twos;
	for (int i=0;i<n;i++) {
		cin >> x;
		fives = twos = 0;
		while (x%5==0) {x/=5;fives++;}
		while (x%2==0) {x/=2;twos++;}
		a[i] = mp(fives, twos);
	}
	vector<vector<ll>> dp(6000, vector<ll>(k+1,-1));
	dp[0][0] = 0;
	for (int i=0;i<n;i++) {
		for (int j=5999;j>=0;j--) {
			for (int l=k-1;l>=0;l--) {
				if (j+a[i].f < 5152 && dp[j][l] != -1) {
					dp[j+a[i].f][l+1] = max(dp[j+a[i].f][l+1],dp[j][l]+a[i].s);
				}
			} 
		}
	}
	ll ans = 0;
	for (int i=0;i<5999;i++) {
		for (int j=0;j<=k;j++) {
			if (dp[i][j] != -1) {ans = max(ans, min((ll)i,dp[i][j]));}
		}
	} cout << ans << '\n';
}
