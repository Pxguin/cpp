#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int n, m;
v<v<int>> adj;
v<int> vis, deg;
int edges = 0;
v<pii> ans;

void dfs(int cur) {
    for (int x : adj[cur]) {
        edges++;
        if (!vis[x]) {
            vis[x] = vis[cur]+1;
            dfs(x);
            if (deg[x]) { // greedy strategy (if child is odd, make it even)
                ans.pb({x,cur}); deg[x] = 0;
            } else { // else, direct from the parent node
                deg[cur]^=1; ans.pb({cur,x});
            }
        } else {
            if (vis[cur]<vis[x]) { // edge not part of spanning tree (direct it arbitrarily)
                deg[cur]^=1; ans.pb({cur,x});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> m;
    adj.resize(n); 
    vis.assign(n,0); deg.assign(n,0);
    F0R(i,m) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }

    F0R(i,n) {
        if (!vis[i]) {
            vis[i] = 1;
            edges = 0;
            dfs(i);
            if ((edges/2)&1) {cout << "IMPOSSIBLE"; return 0;}
        }
    }
    for (pii x : ans) {cout << x.f+1 << ' ' << x.s+1 << '\n';}
}