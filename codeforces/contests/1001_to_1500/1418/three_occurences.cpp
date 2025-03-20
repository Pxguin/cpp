#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
ll rng() {return uniform_int_distribution<ll>(0,INT64_MAX)(gen);}

ll hsh1[500001], hsh2[500001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	F0R(i,5e5+1) {hsh1[i]=rng(); hsh2[i]=rng();}
	
	int n; cin >> n;
	v<int> pos[n+1];
	v<int> mx(n+1,n+1), a(n);
	v<ll> ps(n+1,0);
	F0R(i,n) {
		cin >> a[i];
		pos[a[i]].pb(i+1);
		int sz = pos[a[i]].size();
		if (sz>3) {mx[pos[a[i]][sz-4]] = i+1;} // keep track of last 3 occurences of each num
		ps[i+1] = ps[i];

		if (sz%3!=1) {ps[i+1]^=hsh2[a[i]];} // the hash
		if (sz%3!=2) {ps[i+1]^=hsh1[a[i]];}
	}

	for (int i=n-1;i>=0;i--) {chmin(mx[i],mx[i+1]);} // for every start point, the max end point before there's > 3 occurences of any num

	unordered_map<ll,int> the_map;
	v<v<ll>> hsh;
	F0R(i,n+1) { // split by hash
		if (!the_map.count(ps[i])) {the_map[ps[i]]=hsh.size(); hsh.pb({});}
		hsh[the_map[ps[i]]].pb(i);
	}
	ll ans = 0;
	F0R(i,hsh.size()) { // 2p to calculate answer (although ordered set works too)
		int ptr = hsh[i].size()-1;
		for (int j=hsh[i].size()-2;j>=0;j--) {
			while (hsh[i][ptr]>=mx[hsh[i][j]+1]) {ptr--;}
			ans += ptr-j;
		}
	} cout << ans << '\n';
}