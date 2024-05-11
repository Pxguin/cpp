#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define pll pair<ll,ll>
#define T pair<ll,int>
#define f first
#define s second
#define mp make_pair

vector<vector<pll>> adj;
vector<ll> dist;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	int a, b, d;
	adj.resize(n);

	for (int i=0;i<m;i++) {
		cin >> a >> b >> d; a--; b--;
		adj[a].pb(mp(b,d));
	}
	dist = vector<ll>(n, LLONG_MAX);

	priority_queue<T, vector<T>, greater<T>> pq;
	dist[0] = 0;
	pq.push({0,0});

	while (pq.size()) {
		T t = pq.top(); pq.pop();
		if (t.f != dist[t.s]) {continue;}
		for (pll i : adj[t.s]) {
			if (t.f + i.s < dist[i.f]) {
				pq.push({dist[i.f] = t.f+i.s, i.f});
			}
		}
	}
	for (ll i : dist) {cout << i << ' ';}
}
