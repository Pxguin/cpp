#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

vector<int> a;
vector<vector<int>> p;
int n;
ll ans;

vector<ll> dfs(int cur) {
	vector<ll> ret(n,0);
	ll sum = 0;
	for (int x : p[cur]) {
		vector<ll> add = dfs(x);
		F0R(i,n) {
			if (add[i]==-1 || ret[i]==-1) {ret[i]=-1;}
			else {ret[i] += add[i];}
		}
		sum += a[x];
	} for (int i=n-2;i>=0;i--) {ret[i+1] = ret[i];} ret[0] = 0;
	
	// change current vertex
	if (a[cur] <= sum) {ret[0] = sum-a[cur];}
	else {
		for (ll i=0;i<n;i++) {
			if (ret[i] == -1) {
				ans += i*(a[cur]-sum); sum = a[cur];
			} else {
				ll delta = min(a[cur]-sum,ret[i]);
				sum += delta; ret[i] -= delta;
				ans += i*delta;
			}
			if (a[cur] == sum) {break;}
		}
	}

	if (p[cur].empty()) {ret[0]=-1;}
	return ret;
}

void solve() {
	int p1; cin >> n;
	a.clear(); a.resize(n); p.clear(); p.resize(n);
	F0R(i,n) {cin >> a[i];}
	F0R(i,n-1) {cin >> p1; p[--p1].pb(i+1);}
	ans = 0;
	dfs(0);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
} 	