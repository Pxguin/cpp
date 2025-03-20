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
	int n; cin >> n;
	int a[n]; set<pii> nxt;
	F0R(i,n) {cin >> a[i]; nxt.insert(mp(a[i],i));}
	nxt.insert(mp(1e9,0));

	vector<int> dp(n+1,0), last(n+1,-1);
	F0R(i,n) {
		if (dp[i+1]<=dp[i]) {dp[i+1]=dp[i]; last[i+1]=-1;}
		pii j = *nxt.upper_bound(mp(a[i],i));
		if (j.f==a[i]) {
			if (dp[j.s]<dp[i]+j.s-i+(last[i]!=a[i])) {
				dp[j.s]=dp[i]+j.s-i+(last[i]!=a[i]);
				last[j.s]=a[i];
			}
		}
	} cout << dp[n] << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {solve();}
}