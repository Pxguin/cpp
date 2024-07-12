#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	ll n, q, a; cin >> n >> q;
	vector<ll> vis(n,-1), sum(n,0), ps(q+1,0);
	ll sz = 0;
	F0R(i,q) {
		cin >> a; a--;
		if (vis[a]==-1) {vis[a]=i; sz++;}
		else {
			sum[a] += ps[i]-ps[vis[a]];
			vis[a] = -1;
			sz--;
		}
		ps[i+1] = ps[i]+sz;
	} F0R(i,n) {if (vis[i]!=-1) {sum[i] += ps[q]-ps[vis[i]];}}
	F0R(i,n) {cout << sum[i] << ' ';}
} 	