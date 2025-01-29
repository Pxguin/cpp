#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmin(a, b) a = min(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

void solve() {
	vector<int> ans;
	int n; cin >> n;
	int h;
	vector<vector<int>> t(n);
	F0R(i,n) {cin >> h; t[h-1].pb(i);}
	F0R(i,n) {
		if (t[i].empty()) {continue;}
		int mn = -t[i][0];
		FOR(j,1,t[i].size()) {
			if (2*j-t[i][j]+1>mn) {ans.pb(i+1); break;}
			chmin(mn,2*j-t[i][j]);
		}
	}
	if (ans.empty()) {cout << "-1\n";}
	else {
		F0R(i,ans.size()-1) {cout << ans[i] << ' ';}
		cout << ans.back() << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}