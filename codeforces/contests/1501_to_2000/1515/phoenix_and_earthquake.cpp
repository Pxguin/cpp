#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define vec vector

const int MAX_N = 3e5;
vec<pii> adj[MAX_N];
ll a[MAX_N], x, sum = 0;
bool vis[MAX_N] = {false};

vec<int> todo;

void dfs(int cur) {
    vis[cur] = true;
    for (auto[nxt,i] : adj[cur]) {
        if (!vis[nxt]) {
            dfs(nxt);
            if (a[nxt]>=x) {
                cout << i << '\n';
                a[cur] += a[nxt]-x;
            } else {
                todo.pb(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m; cin >> n >> m >> x;
    for (int i=0;i<n;i++) {cin >> a[i]; sum += a[i];}
    for (int i=0;i<m;i++) {
        int u, v; cin >> u >> v;
        adj[--u].pb({--v,i+1});
        adj[v].pb({u,i+1});
    }
    if (sum<(n-1)*x) {cout << "NO\n";}
    else {
        cout << "YES\n";
        dfs(0);
        while (todo.size()) {cout << todo.back() << '\n'; todo.pop_back();}
    }
}