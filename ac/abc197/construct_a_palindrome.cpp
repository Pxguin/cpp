#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	int a, b; char c;
	vector<pii> e[26];
	for (int i=0;i<m;i++) {
		cin >> a >> b >> c;
		e[c-'a'].pb(mp(--a,--b));
	}
	vector<vector<vector<pii>>> adj(n,vector<vector<pii>>(n));

	auto make_edges = [&](const pii& x1, const pii& y1) {
		vector<int> x = {x1.f,x1.s}, y = {y1.f,y1.s};
		for (int i=0;i<2;i++) {
			for (int j=0;j<2;j++) {
				adj[x[i]][y[j]].pb(mp(x[!i],y[!j]));
				adj[y[j]][x[i]].pb(mp(y[!j],x[!i]));
			}
		}
	};
	for (int i=0;i<26;i++) {
		for (int j=0;j<e[i].size();j++) {
			for (int k=j;k<e[i].size();k++) {
				make_edges(e[i][j],e[i][k]);
			}
		}
	}
	
	vector<vector<int>> dist(n,vector<int>(n,INT_MAX-1)); dist[0][n-1]=0;
	queue<pii> q; q.push(mp(0,n-1));
	while (q.size()) {
		pii cur = q.front(); q.pop();
		for (pii x : adj[cur.f][cur.s]) {
			if (dist[x.f][x.s] == INT_MAX-1) {
				dist[x.f][x.s] = dist[cur.f][cur.s]+2;
				q.push(x);
			}
		}
	}
	int ans = INT_MAX-1;
	for (int i=0;i<26;i++) {
		for (pii x : e[i]) {ans = min(ans,min(dist[x.f][x.s],dist[x.s][x.f])+1);}
	}
	for (int i=0;i<n;i++) {ans = min(ans,dist[i][i]);}
	cout << (ans==INT_MAX-1 ? -1 : ans) << '\n';
}
