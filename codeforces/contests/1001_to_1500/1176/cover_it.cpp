#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int n, m; cin >> n >> m;
    v<v<int>> adj(n);
    F0R(i,m) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    v<int> color;
    v<bool> vis(n,false);
    auto dfs = [&](auto& dfs, int cur, int depth, int goal)->void {
        vis[cur] = true;
        if (depth==goal) {color.pb(cur);} // color nodes only at odd/even depths
        for (int x : adj[cur]) {
            if (!vis[x]) {dfs(dfs,x,depth^1,goal);}
        }
    };
    dfs(dfs,0,0,0); // color nodes at odd depths
    if (color.size()>n/2) { // if color nodes at odd depths doesn't work, then even depths works
        color.clear();
        vis.assign(n,false);
        dfs(dfs,0,0,1); // color at even depths
    }
    cout << color.size() << '\n';
    for (int x : color) {cout << x+1 << ' ';}
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}