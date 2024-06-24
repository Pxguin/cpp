#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define mp make_pair
#define pb push_back
#define f first
#define s second

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll ans, n; cin >> ans >> n;
	ll a;
	vector<vector<ll>> lists(n);
	vector<ll> ptr(n,-1);
	
	for (int i=0;i<n;i++) {
		int l; cin >> l;
		while (l--) {
			cin >> a; lists[i].pb(a);
		}
	}
	priority_queue<pii,vector<pii>> pq;
	for (int i=0;i<n;i++) {pq.push(mp(0,i));}

	while (pq.size()) {
		pii x = pq.top(); pq.pop();
		bool flag = true;
		while (x.f+ans >= 0) {
			flag = false;
			ptr[x.s]++; 
			if (ptr[x.s]<lists[x.s].size()) {
				x.f += lists[x.s][ptr[x.s]];
				if (x.f >= 0) {ans += x.f; x.f = 0;}
			}
			else {flag = true; break;}
		}
		if (!flag) {pq.push(x);}
	}
	cout << ans << '\n';
}
