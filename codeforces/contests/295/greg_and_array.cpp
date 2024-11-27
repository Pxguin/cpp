#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m, k; cin >> n >> m >> k;
	v<ll> a(n+1,0);
	F0R(i,n) {cin >> a[i];}
	for (int i=n-1;i>=0;i--) {a[i+1] -= a[i];}

	v<pii> q(m); v<ll> d(m);
	F0R(i,m) {cin >> q[i].f >> q[i].s >> d[i];}

	v<int> ps(m+1,0);
	F0R(i,k) {
		int l, r; cin >> l >> r;
		ps[l-1]++; ps[r]--;
	}
	F0R(i,m) {
		ps[i+1] += ps[i];
		a[q[i].f-1] += ps[i]*d[i];
		a[q[i].s] -= ps[i]*d[i];
	} 
	F0R(i,n) {
		a[i+1] += a[i];
		cout << a[i] << ' ';
	}
}