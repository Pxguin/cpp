#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

void solve() {
	int n, k; cin >> n >> k;
	vector<vector<int>> a(n+1,vector<int>(n+1,0));
	FOR(i,1,n+1,1) {
		FOR(j,i,n+1,1) {cin >> a[i][j];}
	}

	vector<multiset<int,greater<int>>> dp(n+3); // k max with last element (i-1) blank
	dp[0].insert(0);
	FOR(i,1,n+3,1) {
		for (int j : dp[i-1]) {
			dp[i].insert(j);
			if (dp[i].size()>k) {dp[i].erase(--dp[i].end());}
		} 
		if (i<=n) {
			vector<multiset<int,greater<int>>::iterator> ptr(n+1);
			set<pii,greater<pii>> cur;
			FOR(j,1,i+1,1) {
				ptr[j]=dp[j].begin();
				cur.insert({*dp[j].begin()+a[j][i],j});
			}
			
			while (cur.size()) {
				pii mx = *cur.begin();
				dp[i+2].insert(mx.f);
				cur.erase(cur.begin());
				if (++ptr[mx.s]!=dp[mx.s].end()) {cur.insert({*ptr[mx.s]+a[mx.s][i],mx.s});}
				if (dp[i+2].size() == k) {break;}
			}
		}
	}
	for (int i : dp[n+2]) {cout << i << ' ';} cout << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}