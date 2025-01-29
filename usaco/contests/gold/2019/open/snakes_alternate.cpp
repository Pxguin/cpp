#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	ll a[n+1];
	for (int i=0;i<n;i++) {cin >> a[i+1];}
	ll mx2;

	vector<vector<ll>> dp(n+1,vector<ll>(k+1,INT_MAX));
	ll mx = 0, total = 0;
	for (int i=1;i<=n;i++) {
		mx = max(mx, a[i]);
		total += a[i];
		dp[i][0] = mx*i;
		
		// try switching from this to all others (push dp)
		mx2 = 0;
		for (int j=i+1;j<=n;j++) {
			mx2 = max(mx2, a[j]);
			for (int x=0;x<k;x++) {
				dp[j][x+1] = min(dp[j][x+1], dp[i][x]+mx2*(j-i));
			}
		}

		// try switching to this from all others (pull dp)
		mx2 = a[i];
		for (int j=i-1;j>0;j--) {
			for (int x=0;x<k;x++) {
				dp[i][x+1] = min(dp[i][x+1], dp[j][x]+mx2*(i-j));
			}
			mx2 = max(mx2, a[j]);
		}

	}
	cout << dp[n][k]-total << '\n';
}
