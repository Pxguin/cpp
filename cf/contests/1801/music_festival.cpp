#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define MAX_N 200003
#define s second
#define mp make_pair

vector<vector<pii>> rules(MAX_N);
vector<int> dp(MAX_N, 0);

void solve() {
	int n; cin >> n;

	set<int> events;
	for (int i=0;i<n;i++) {
		int k; cin >> k;
		int mx = 0, cur, sz = 0;
		vector<int> album;
		while (k--) {
			cin >> cur;
			if (cur > mx) {
				album.pb(cur); sz++;
				mx = cur;
			}
		}
		for (int j=0;j<sz;j++) {
			rules[album[j]].pb(mp(sz-j, album.back()));
			events.insert(album[j]);
		} events.insert(album.back()+1);
	}
	
	int ans = 0;
	events.insert(MAX_N-1);
	while (events.size() > 1) {
		int i = *events.begin(); events.erase(i);
		for (pii x : rules[i]) {
			dp[x.s+1] = max(dp[x.s+1], dp[i]+x.f);
		}
		dp[*events.begin()] = max(dp[*events.begin()], dp[i]);
		ans = max(ans, dp[i]);
		dp[i] = 0;
		rules[i].clear();
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {solve();}
}
