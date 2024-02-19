#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("maxcross.in","r",stdin); freopen("maxcross.out","w",stdout);
	int n, k, b; cin >> n >> k >> b;
	int a;
	int ps[n+1] = {0};
	while (b--) {
		cin >> a;
		ps[a]++;
	}
	for (int i=0;i<n;i++) {ps[i+1] += ps[i];}
	int ans = k;
	for (int i=k;i<=n;i++) {
		ans = min(ans, ps[i]-ps[i-k]);
	}
	cout << ans << "\n";
}
