#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define f first
#define s second

struct Edge {
	int to, from, cow;
	Edge(int to, int from, int cow) : to(to), from(from), cow(cow) {};
};

vector<vector<Edge>> adj;
vector<bool> vis, vis2;
vector<pair<int,Edge>> edges;
int cow, start;
queue<int> ans;
vector<int> gets_cereal; 

void dfs(int cur, int par) {
	vis[cur] = true;
	for (Edge x : adj[cur]) {
		if (!vis[x.to]) {
			edges.pb(mp(cur, x));
			dfs(x.to, cur);
		} else {
			if (x.to != par && start == -1) {
				cow = x.cow; 
				start = (x.to == x.from) ? x.to : cur;
				ans.push(cow);
				gets_cereal[cow-1] = true;
			}
		}
	}
}

void dfs2(int cur) {
	vis2[cur] = true;
	for (Edge x : adj[cur]) {
		if (x.cow != cow && !vis2[x.to]) {
			gets_cereal[x.cow-1] = true;
			ans.push(x.cow);
			dfs2(x.to);
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	adj.resize(m); 
	vis.assign(m, false); vis2.assign(m, false);
	gets_cereal.assign(n, false);
	int a, b;
	for (int i=0;i<n;i++) {
		cin >> a >> b; a--; b--;
		adj[a].pb(Edge(b, a, i+1));
		adj[b].pb(Edge(a, a, i+1));
	}

	for (int i=0;i<m;i++) {
		if (!vis[i]) {
			start = -1; cow = -1;
			edges.clear();
			dfs(i, -1);

			if (start == -1) {start = i;}
			dfs2(start);
		}
	}

	int hungry = 0;
	for (int i=0;i<n;i++) {
		if (!gets_cereal[i]) {hungry++; ans.push(i+1);}
	}
	cout << hungry << '\n';
	while (ans.size()) {cout << ans.front() << '\n'; ans.pop();}
}