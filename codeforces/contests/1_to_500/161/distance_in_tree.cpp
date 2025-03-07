#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int MAX_N = 50000, MAX_K = 500;
v<v<int>> adj(MAX_N+1);
v<v<int>> d(MAX_N+1,v<int>(MAX_K+1,0));
int n, k;
ll ans = 0;

void dfs(int cur, int par) {
	d[cur][0] = 1;
	for (int x : adj[cur]) {
		if (x != par) {
			dfs(x,cur);
			F0R(i,k) {
				ans += d[cur][k-(i+1)]*d[x][i];
			}
			F0R(i,k) {
				d[cur][i+1] += d[x][i];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	F0R(i,n-1) {
		int a, b; cin >> a >> b;
		adj[--a].pb(--b); adj[b].pb(a);
	} dfs(0,0);
	cout << ans << '\n';
}