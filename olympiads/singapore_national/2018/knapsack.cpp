#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int s, n; cin >> s >> n;
	int v, w, k;
	vector<vector<pii>> in_(s+1);
	F0R(i,n) {
	    cin >> v >> w >> k;
	    in_[w].pb({v,k});
	}
	vector<vector<int>> items(s+1);
	FOR(i,1,s+1) {
	    sort(in_[i].begin(),in_[i].end(),greater<>());
	    ll ctr = 0;
	    for (pii cur : in_[i]) {
	        F0R(j,min((s/i)-ctr,(ll)cur.s)) {items[i].pb(cur.f);}
	        ctr += cur.s;
	    }
	}
	vector<ll> dp(s+1,-1);
	dp[0] = 0;
	FOR(i,1,s+1) { // weight
		for (int val : items[i]) {
			for (int j=s-i;j>=0;j--) {
				if (dp[j]!=-1) {chmax(dp[j+i],dp[j]+val);}
			}
		}
	}
	ll ans = 0;
	F0R(i,s+1) {chmax(ans,dp[i]);}
	cout << ans << '\n';
}