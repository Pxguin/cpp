#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int n, m;
v<v<int>> adj;
v<int> vis, deg;
v<v<int>> ans;

void dfs(int cur) {
    for (int x : adj[cur]) {
        if (!vis[x]) {
            vis[x] = vis[cur]+1;
            dfs(x);
            if (deg[x]) { // in spanning tree
                ans[x].pb(cur); deg[x] = 0;
            } else {
                deg[cur]^=1; ans[cur].pb(x);
            }
        } else { // not in spanning tree
            if (vis[cur]<vis[x]) {
                deg[cur]^=1; ans[cur].pb(x);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> m;
    adj.resize(n); ans.resize(n);
    vis.assign(n,0); deg.assign(n,0);
    F0R(i,m) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }

    F0R(i,n) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(i);
        }
    }
    int w = 0;
    F0R(i,n) {w += (int)ans[i].size()/2;}
    cout << w << '\n';
    F0R(i,n) { // pair up the edges
        for (int j=0;j<(int)ans[i].size()-1;j+=2) {
            cout << ans[i][j]+1 << ' ' << i+1 << ' ' << ans[i][j+1]+1 << '\n';
        }
    }
}