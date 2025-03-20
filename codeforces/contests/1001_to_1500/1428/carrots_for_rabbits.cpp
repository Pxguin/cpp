#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, k; cin >> n >> k;
	priority_queue<pii,vector<pii>> pq; 
	vector<pii> a(n);
	F0R(i,n) {cin >> a[i].f; a[i].s = 1;}
	int cnt = n;

	auto split = [&](ll val, ll piece)->ll {
		ll small = val/piece, freq = piece-(val-piece*small);
		return (small*small*freq)+((small+1)*(small+1)*(piece-freq));
	};
	auto diff = [&](ll val, ll piece)->ll {
		if (val==piece) {return -1;}
		else {return split(val,piece)-split(val,piece+1);}
	};
	
	F0R(i,n) {pq.push({diff(a[i].f,a[i].s),i});}
	while (cnt!=k) {
		pii cur = pq.top(); pq.pop();
		a[cur.s].s++; cnt++;
		pq.push({diff(a[cur.s].f,a[cur.s].s),cur.s});
	} ll ans = 0;
	F0R(i,n) {ans += split(a[i].f,a[i].s);}
	cout << ans << '\n';
}