#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	vector<vector<int>> f(n,vector<int>(1,0));
	F0R(i,n) {cin >> a[i]; f[--a[i]].pb(i+1);}
	vector<vector<int>> add(n+1),query(n+1);

	vector<int> bit(n+2);
	auto upd = [&](int idx) {
		for (;idx<=n+1;idx+=(idx&-idx)) {bit[idx]++;}
	};
	auto sum = [&](int idx) {
		ll ret = 0;
		for (;idx>0;idx-=(idx&-idx)) {ret += bit[idx];}
		return ret;
	};
	
	F0R(i,n) {
		f[i].pb(n+1);
		for (int j=1;j<f[i].size()-1;j++) {
			if (f[i][j]!=1) {add[f[i][j-1]+1].pb(f[i][j]-1);}
			query[f[i][j]].pb(f[i][j+1]-1);
		}
	}
	ll ans = 0;
	F0R(i,n+1) {
		for (int x : add[i]) {upd(x);}
		for (int x : query[i]) {ans += sum(x)-sum(i-1);}
	} cout << ans << '\n';
}