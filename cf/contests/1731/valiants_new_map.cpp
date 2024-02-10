#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
 
int n, m;
vector<vector<int>> a;
 
bool check(int s) {
	ll t = (ll)(s*s);

	ll ps[n+1][m+1];
	for (int i=0;i<=n;i++) {
		for (int j=0;j<=m;j++) {ps[i][j] = 0;}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			ps[i][j] = (a[i-1][j-1] >= s) + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
		}
	}
 
	for (int i=s;i<=n;i++) {
		for (int j=s;j<=m;j++) {
			ll sum = ps[i][j] + ps[i-s][j-s] - ps[i][j-s] - ps[i-s][j];
			if (sum == t) {return true;}
		}
	}
	return false;
}
 
void solve() {
	cin >> n >> m;
	a.clear(); a.resize(n);
	
	int x;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			cin >> x;
			a[i].pb(x);
		}
	}
 
	int l = 1, h = min(n, m), s;
	int ans = 1;
 
	while (l <= h) {
		s = (l+h)/2;
		if (check(s)) {
			l = s+1;
			ans = s;
		} else {h = s-1;}
	}
	cout << ans << "\n";
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {solve();}
}