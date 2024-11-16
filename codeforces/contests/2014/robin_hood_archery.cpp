#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
ll rng() {return uniform_int_distribution<ll>(0,INT64_MAX)(gen);}

v<ll> hsh(1e6+1);

void solve() {
	int n, q, a; cin >> n >> q;
	v<ll> ps(n+1,0);
	F0R(i,n) {
		cin >> a;
		ps[i+1]=ps[i]^hsh[a];
	}
	int l, r;
	while (q--) {
		cin >> l >> r;
		cout << (ps[l-1]==ps[r] ? "YES" : "NO") << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	F0R(i,1e6+1) {hsh[i]=rng();}
	int t; cin >> t;
	while (t--) {solve();}
}