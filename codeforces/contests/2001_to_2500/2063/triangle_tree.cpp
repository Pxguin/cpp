#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 3e5;
int depth[MAX_N], sz[MAX_N];
v<v<int>> adj;
ll ans = 0;

void dfs(int cur, int par, int d) {
    depth[d]++;
    sz[cur] = 1;
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs(x,cur,d+1);
            ans -= (ll)2*d*sz[cur]*sz[x]; // subtract depth of lca for all pairs
            ans -= (ll)(sz[cur]-1)*sz[x]; // subtract 1 (only for all good pairs)
            sz[cur] += sz[x];
        }
    }
}

void solve() {
    int n; cin >> n;
    ans = 0;
    adj.clear(); adj.resize(n); fill(depth,depth+n,0);
    F0R(i,n-1) {
        int u, v1; cin >> u >> v1;
        adj[--u].pb(--v1);
        adj[v1].pb(u);
    } dfs(0,0,0);
    
    ll c = 0;
    for (int i=n-1;i>=0;i--) { // add back min(a,b) for all pairs
        F0R(j,depth[i]) {
            ans += c*i*2;
            c++;
        }
    } cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
 
    int t; cin >> t;
    while (t--) {solve();}
}