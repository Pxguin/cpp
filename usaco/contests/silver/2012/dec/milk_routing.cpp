#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define T pair<ll,int>
#define f first
#define s second

struct Edge {
	int b, l, c;
	Edge(int b, int l, int c) : b(b), l(l), c(c) {};
	bool operator<(const Edge& y) {return l < y.l;}
};

vector<vector<Edge>> adj;
vector<ll> dist;

int main() {
	freopen("mroute.in","r",stdin);
	freopen("mroute.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, m, x; cin >> n >> m >> x;
	int a, b1, l1, c1;
	adj.resize(n);

	unordered_set<int> val;

	for (int i=0;i<m;i++) {
		cin >> a >> b1 >> l1 >> c1; a--; b1--;
		adj[a].pb(Edge(b1, l1, c1));
		adj[b1].pb(Edge(a, l1, c1));
		val.insert(c1);
	}

	ld ans = 1e10;
	
	while (val.size()) {
		c1 = *val.begin();
		val.erase(c1);

		dist = vector<ll>(n, LLONG_MAX);

		priority_queue<T, vector<T>, greater<T>> pq;
		dist[0] = 0;
		pq.push({0,0});

		while (pq.size()) {
			T t = pq.top(); pq.pop();
			if (t.f != dist[t.s]) {continue;}
			for (Edge i : adj[t.s]) {
				if (i.c < c1) {continue;}
				if (t.f + i.l < dist[i.b]) {
					pq.push({dist[i.b] = t.f+i.l, i.b});
				}
			}
		}
		ans = min(ans, dist[n-1]+(ld)(x/c1));
	}
	cout << (ll)(ans);
}
