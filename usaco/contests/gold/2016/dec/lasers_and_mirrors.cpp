#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair

int main() {
	freopen("lasers.in","r",stdin);
	freopen("lasers.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	// store x and y lines as nodes 
	int n, xl, yl, xb, yb; cin >> n >> xl >> yl >> xb >> yb;
	int a, b;
	map<int,vector<int>> x_inf, y_inf;
	map<int,int> x_dist, y_dist;
	x_inf[yl]={xl}; y_inf[xl]={yl}; x_inf[yb]={xb}; y_inf[xb]={yb};
	for (int i=0;i<n;i++) {
		cin >> a >> b;
		x_inf[b].pb(a); y_inf[a].pb(b); 
		x_dist[b] = y_dist[a] = INT_MAX;
	} queue<pii> q; 
	int ans = INT_MAX; x_dist[yb] = INT_MAX; y_dist[xb] = INT_MAX;
	
	q.push(mp(xl,1)); q.push(mp(yl,0)); 
	y_dist[xl] = 0; x_dist[yl] = 0;
	while (q.size()) {
		pii cur = q.front(); q.pop();
		if (!cur.s) {
			for (int x : x_inf[cur.f]) {
				if (y_dist[x] == INT_MAX) {y_dist[x] = x_dist[cur.f]+1; q.push({x,1});}
			}
		} else {
			for (int y : y_inf[cur.f]) {
				if (x_dist[y] == INT_MAX) {x_dist[y] = y_dist[cur.f]+1; q.push({y,0});}
			}
		}
	}
	ans = min(ans,min(x_dist[yb],y_dist[xb]));
	cout << (ans == INT_MAX ? -1 : ans) << '\n';
}
