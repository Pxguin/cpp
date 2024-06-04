#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<vector<int>> g(n,vector<int>(n));
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			cin >> g[i][j];
			g[i][j] = (g[i][j]==100 ? 1 : (g[i][j] > 100 ? 2 : 0));
		}
	}
	ll ans = 0;
	// iterate over one x
	for (int i=0;i<n;i++) {
		vector<bool> union_(n,1);
		vector<bool> green(n,0);
		// iterate over two x
		for (int j=i;j<n;j++) {
			// iterate over y
			for (int k=0;k<n;k++) {
				union_[k] = union_[k] && g[j][k];
				if (union_[k] && g[j][k]==1) {green[k]=true;}
			}
			// parse into ranges
			vector<ll> r(n,0);
			r[n-1]=union_[n-1];
			for (int k=n-2;k>=0;k--) {r[k]=(union_[k] ? r[k+1]+1 : 0);}
			// calculate subgrids
			ll prev = -1;
			for (int k=0;k<n;k++) {
				if (union_[k] && prev == -1) {prev = k;}
				if (union_[k] && green[k]) {ans += r[k]*(k-prev+1); prev = k+1;}
				if (!union_[k]) {prev = -1;}
			}
		}
	}
	cout << ans << '\n';
}