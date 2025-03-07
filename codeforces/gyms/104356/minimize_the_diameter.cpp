#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmin(a, b) a = min(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vec<vec<int>> adj(n);
    F0R(i,n-1) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    int m; cin >> m;
    vec<vec<int>> adj2(m);
    F0R(i,m-1) {
        int a, b; cin >> a >> b;
        adj2[--a].pb(--b);
        adj2[b].pb(a);
    }

    vec<vec<int>> dist(2,vec<int>(n)), dist2(2,vec<int>(m));
    auto dfs = [&](auto& dfs, int cur, int par, vec<vec<int>>& d, vec<vec<int>>& ad, int i, int dep)->int {
        d[i][cur] = dep;
        int ret = cur;
        for (int x : ad[cur]) {
            if (x!=par) {
                int y = dfs(dfs,x,cur,d,ad,i,dep+1);
                if (d[i][y]>d[i][ret]) {ret = y;}
            }
        } return ret;
    };

    int a1 = dfs(dfs,0,0,dist,adj,0,0); // find diameters of tree
    int b1 = dfs(dfs,a1,a1,dist,adj,0,0);
    dfs(dfs,b1,b1,dist,adj,1,0);
    int a2 = dfs(dfs,0,0,dist2,adj2,0,0);
    int b2 = dfs(dfs,a2,a2,dist2,adj2,0,0);
    dfs(dfs,b2,b2,dist2,adj2,1,0);

    int d1 = dist[0][b1], d2 = dist2[0][b2];
    int mn1 = d1, mn2 = d2;
    F0R(i,n) {chmin(mn1,max(dist[0][i],dist[1][i]));} // find node with shortest longest path in tree
    F0R(i,m) {chmin(mn2,max(dist2[0][i],dist2[1][i]));} // which alternatively = midpoint of diameter
    cout << max(mn1+mn2+1,max(d1,d2)) << '\n';
}