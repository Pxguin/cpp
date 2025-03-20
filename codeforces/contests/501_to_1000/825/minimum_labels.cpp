#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	int a, b;
	vector<vector<int>> adj(n);
	vector<int> deg(n,0);
	for (int i=0;i<m;i++) {
		cin >> a >> b;
		adj[--b].pb(--a);
		deg[a]++;
	}

	priority_queue<int> nodes;
	for (int i=0;i<n;i++) {if (!deg[i]) {nodes.push(i);}}
	int idx = 1; vector<int> ans(n,0);

	while (nodes.size()) {
		while (nodes.size()) {
			ll cur = nodes.top(); nodes.pop();
			
			ans[cur] = idx++;
			for (int x : adj[cur]) {
				if (--deg[x]==0) {nodes.push(x);}
			}
		}
	}
	for (int i : ans) {cout << n-i+1 << ' ';}
}