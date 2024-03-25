#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX_N 100001

ll dp[MAX_N];

void solution2() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	int x[n]; 
	vector<vector<bool>> dp(MAX_N+1, vector<bool>(n+1,false));
	dp[0][0] = true;
	for (int i=0;i<n;i++) {cin >> x[i];}

	int ans = 0;

	for (int i=1;i<=n;i++) {
		int c = x[i-1];
		for (int j=0;j<=MAX_N;j++) {
			if (j-c >= 0) {dp[j][i] = dp[j-c][i-1];}
			dp[j][i] = dp[j][i-1] || dp[j][i];
		}
	}
	vector<int> z;
	for (int i=1;i<=MAX_N;i++) {if (dp[i][n]) {ans++; z.pb(i);}}
	cout << ans << '\n';
	for (int i : z) {cout << i << ' ';}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int x[n]; 
	dp[0] = 1;
	for (int i=0;i<n;i++) {cin >> x[i];}

	int ans = 0;

	for (int i=0;i<n;i++) {
		int c = x[i];
		for (int j=MAX_N-c-1;j>=0;j--) {
			if (dp[j]) {
				ans += !(bool)dp[j+c];
				dp[j+c] = 1;
			}
		}
	}
	cout << ans << '\n';
	for (int i=1;i<=MAX_N-1;i++) {if (dp[i]) {cout << i << ' ';}}
}
