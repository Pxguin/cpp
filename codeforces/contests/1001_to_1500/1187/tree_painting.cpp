#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define chmax(a, b) a = max(a,b)
#define vec vector

const int MAX_N = 2e5;
vec<int> adj[MAX_N];
ll dp_in[MAX_N] = {0}, dp_out[MAX_N] = {0}, sz[MAX_N];
ll ans = 0;
int n;

void dfs(int cur, int par) { // calc answer in subtree
    sz[cur] = 1;
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs(x,cur);
            dp_in[cur] += dp_in[x]+sz[x];
            sz[cur] += sz[x];
        }
    }
}
void dfs2(int cur, int par) { // calc answer out subtree
    chmax(ans,dp_in[cur]+dp_out[cur]);
    for (int x : adj[cur]) {
        if (x!=par) {
            dp_out[x] = (n-sz[x])+(dp_in[cur]-sz[x]-dp_in[x])+dp_out[cur];
            dfs2(x,cur);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }

    dfs(0,0);
    dfs2(0,-1);
    
    cout << ans+n << '\n';
}