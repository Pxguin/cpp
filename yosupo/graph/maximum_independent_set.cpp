#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

void chmax(int& a, int b) {
	if (__builtin_popcount(b)>__builtin_popcount(a)) {a=b;}
}
void chmax(ll& a, ll b) {
	if (__builtin_popcountll(b)>__builtin_popcountll(a)) {a=b;}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m, a, b; cin >> n >> m;
	vector<vector<bool>> adj(n,vector<bool>(n,false));
	F0R(i,m) {
		cin >> a >> b;
		adj[a][b] = adj[b][a] = true;
	}
	int m1 = n/2, m2 = n-m1;

	vector<bool> ok1(1<<m1,true), ok2(1<<m2,true);
	vector<int> mx(1<<m2,0);
	
	auto calc = [&](int& m_, vector<bool>& arr, int delta)->void {
		F0R(mask,(1<<m_)) {
			F0R(b1,m_) {
				FOR(b2,b1+1,m_) {
					if ((mask&(1<<b1)) && (mask&(1<<b2)) && (adj[b1+delta][b2+delta])) {arr[mask] = false;}
				}
			}
		}
	};
	calc(m1,ok1,0);
	calc(m2,ok2,m1);
	F0R(mask,1<<m2) {
		if (ok2[mask]) {mx[mask]=mask;}
		F0R(b1,m2) {
			if (!(mask&(1<<b1))) {chmax(mx[mask|(1<<b1)],mx[mask]);}
		}
	}
	ll ans = 0;
	F0R(mask,1<<m1) {
		if (!ok1[mask]) {continue;}
		ll c = 0;
		FOR(j,m1,n) {
			bool flag = false;
			F0R(k,m1) {
				if ((mask&(1<<k)) && adj[j][k]) {flag = true;}
			} if (!flag) {c |= (1<<(j-m1));}
		} c = mx[c];
		chmax(ans,(ll)mask+(c<<m1));
	} 
	cout << __builtin_popcountll(ans) << '\n';
	F0R(i,n) {if (ans&(1LL<<i)) {cout << i << ' ';}}
}