#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
ll rng() {return uniform_int_distribution<ll>(0,INT64_MAX)(gen);}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	v<ll> a(n+1,0), b(n+1,0);
	map<int,ll> hashes;

	auto doit = [&](v<ll>& c) {
		set<int> cur; int x;
		F0R(i,n) {
			c[i+1]=c[i];
			cin >> x;
			if (!hashes.count(x)) {hashes[x]=rng();}
			if (!cur.count(x)) {c[i+1]^=hashes[x];}
			cur.insert(x);
		} cur.clear();
	};
	doit(a); doit(b);
	int q, x, y; cin >> q;
	while (q--) {
		cin >> x >> y;
		cout << (a[x]==b[y] ? "Yes" : "No") << '\n';
	}
}