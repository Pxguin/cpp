#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n; ll mod; 
vector<int> a; vector<bool> vis; vector<ll> dist;
ll ans = 0;

ll exp(ll a1, ll b1) {
	ll res = 1;
	while (b1 > 0) {
		if (b1&1) {res = (res*a1)%mod;}
		a1 = (a1*a1)%mod;
		b1 /= 2;
	} return res;
}

ll calc(ll a1, ll b1) {
	return (exp(a1,b1)+exp(b1,a1))%mod;
}

void prim() {
	dist[0] = 0;
	// repeat to find n nodes
	for (int i=0;i<n;i++) {
		int cur = -1;
		// find mn dist
		for (int j=0;j<n;j++) {
			if (!vis[j] && (cur == -1 || dist[j] > dist[cur])) {cur = j;}
		}
		// upd dist
		vis[cur] = true;
		ans += dist[cur];
		for (int j=0;j<n;j++) {
			if (!vis[j]) {dist[j] = max(dist[j],calc(a[j],a[cur]));}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> mod;
	a.resize(n); vis.assign(n, false); dist.assign(n,-1);
	for (int i=0;i<n;i++) {cin >> a[i];}
	prim();

	cout << ans << '\n';
}
