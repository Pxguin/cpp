#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

const int MAX_N = 2e5;
v<int> adj[MAX_N], depth[MAX_N];
int tin[MAX_N], sz[MAX_N], timer = 0;

void dfs(int cur, int par, int d) {
    tin[cur] = timer++;
    sz[cur] = 1;
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs(x,cur,d+1);
            sz[cur] += sz[x];
        }
    }
    depth[d].pb(tin[cur]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    F0R(i,n-1) {
        int p; cin >> p;
        adj[--p].pb(i+1);
    }
    dfs(0,0,0);
    
    int q; cin >> q;
    while (q--) {
        int a, d; cin >> a >> d; a--;
        cout << lower_bound(all(depth[d]),tin[a]+sz[a])-lower_bound(all(depth[d]),tin[a]) << '\n';
    }
}