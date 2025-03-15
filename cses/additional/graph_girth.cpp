#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmin(a, b) a = min(a,b)
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    vec<vec<int>> adj(n);
    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    
    int ans = INT_MAX;
    vec<int> dist(n), par(n);
    queue<int> q;
    for (int src=0;src<n;src++) { // fix some node in the cycle
        for (int i=0;i<n;i++) {dist[i] = par[i] = INT_MAX;}
        dist[src] = 0;
        par[src] = -1;
        q.push(src);

        while (q.size()) { // do bfs
            int cur = q.front(); q.pop();
            for (int x : adj[cur]) {
                if (dist[x]==INT_MAX) {
                    dist[x] = dist[cur]+1;
                    q.push(x);
                    par[x] = cur;
                } else {
                    if (par[cur]!=x) { // only if they originated from different paths, then if this a valid cycle candidate
                        chmin(ans,dist[x]+dist[cur]+1);
                    }
                }
            }
        }
    }
    cout << (ans==INT_MAX ? -1 : ans) << '\n';
}