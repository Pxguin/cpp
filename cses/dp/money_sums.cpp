#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX_N 100001

ll dp[MAX_N];

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
