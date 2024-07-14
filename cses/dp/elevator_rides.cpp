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

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, x; cin >> n >> x;
	int w[n];
	F0R(i,n) {cin >> w[i];}

	vector<pii> dp((1<<n),{100,100}); dp[0] = {1,x};
	FOR(mask,1,(1<<n),1) {
		F0R(i,n) {
			if (mask&(1<<i)) {
				pii prev = dp[mask^(1<<i)];
				if (prev.s < w[i]) {prev = {prev.f+1,x-w[i]};}
				else {prev.s -= w[i];}
				if ((prev.f < dp[mask].f) || (prev.f==dp[mask].f&&prev.s>dp[mask].s)) {dp[mask]=prev;}
			}
		}
	} cout << dp[(1<<n)-1].f << '\n';
}