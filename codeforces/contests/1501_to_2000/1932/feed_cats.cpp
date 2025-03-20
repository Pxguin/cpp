#include <bits/stdc++.h>
using namespace std;
 
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define pb push_back
 
void solve() {
	int n, m; cin >> n >> m;
	int l, r;
	vector<vector<pii>> e(n+2);
	vector<int> cats(m);
	for (int i=0;i<m;i++) {
		cin >> l >> r; r++;
		e[l].pb(mp(i,1));
		e[r].pb(mp(i,0));
		cats[i] = l;
	}
	vector<int> dp(n+1, 0);
	multiset<int> cur;
	for (int i=1;i<=n;i++) {
		for (pii x : e[i]) {
			if (x.s) {cur.insert(cats[x.f]);}
			else {cur.erase(cur.find(cats[x.f]));}
		}
		int mn = (cur.size() ? *cur.begin() : 1)-1;
		// feed cats
		dp[i] = cur.size()+dp[mn];
		// dont feed
		dp[i] = max(dp[i], dp[i-1]);
	}
	cout << dp[n] << '\n';
}
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {solve();}
}