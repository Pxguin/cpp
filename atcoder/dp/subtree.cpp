#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define vec vector

const int MAX_N = 1e5;
vec<int> adj[MAX_N];
vec<ll> ps[MAX_N], ss[MAX_N];
ll in[MAX_N], out[MAX_N];

ll n, m;

void dfs(int cur) {
    in[cur] = 1;
    ps[cur] = ss[cur] = {1};
    for (int x : adj[cur]) {
        adj[x].erase(find(all(adj[x]),cur));
        dfs(x);
        in[cur] = (in[cur]*(in[x]+1))%m; // compute ways to color inside the subtree of i
    }
    for (int i=0;i<adj[cur].size();i++) { // prefix sum & suffix sum products on adjacency list
        ps[cur].pb(ps[cur].back()*(in[adj[cur][i]]+1)%m);
        ss[cur].pb(ss[cur].back()*(in[adj[cur][adj[cur].size()-i-1]]+1)%m);
    }
}

void dfs2(int cur) {
    for (int i=0;i<adj[cur].size();i++) { // math (compute ways to color outside subtree of i)
        out[adj[cur][i]] = (out[cur]*(ps[cur][i]*ss[cur][adj[cur].size()-i-1]%m)+1)%m;
        dfs2(adj[cur][i]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs(0);
    out[0] = 1;
    dfs2(0);
    for (int i=0;i<n;i++) {cout << in[i]*out[i]%m << '\n';} // out*in is answer for i
}