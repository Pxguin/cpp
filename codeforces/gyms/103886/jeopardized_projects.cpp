#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)

int MAX_N = 100001;
ll mod = 1e9+7;
vector<ll> cnt(MAX_N,0);
vector<ll> ps(MAX_N,0);

void calc() {
	ps[1] = cnt[2] = 1;
	FOR(i,2,MAX_N,1) {
		ps[i] = (ps[i-1]*2)%mod;
		if (2*i<MAX_N) {cnt[2*i] = (cnt[2*i]+ps[i])%mod;}
	} ll cur = 0;
	FOR(i,1,MAX_N,1) {
		cur = (cur+cnt[i])%mod;
		ps[i] = (ps[i]+mod-cur-1+ps[i-1])%mod;
	}
}

void solve() {
	int l, r; cin >> l >> r;
	cout << (ps[r]+mod-ps[l-1])%mod << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	calc();
	int t; cin >> t;
	while (t--) {solve();}
}