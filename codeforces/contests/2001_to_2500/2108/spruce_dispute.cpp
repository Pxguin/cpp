#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define all(x) x.begin(),x.end()
#define vec vector

void solve() {
    int n; cin >> n;
    vec<vec<int>> adj(n);
    vec<int> indeg(n,0), sz(n,0);

    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
        indeg[a]++; indeg[b]++;
    }

    int start = 0, remove = 0, remove2 = 0;
    for (int i=0;i<n;i++) {if (indeg[i]!=1) {start = i;}} // root the tree at a non-leaf

    vec<vec<pii>> dp(n,vec<pii>(2,{0,0}));

    function<void(int)> dfs = [&](int cur) {
        sz[cur] = 1;
        pii mx = {0,cur};
        if (adj[cur].size()!=0) {mx.f = -1e7;} 
        for (int x : adj[cur]) {
            adj[x].erase(find(all(adj[x]),cur));
            dfs(x);
            sz[cur] += sz[x];
        }
        for (int x : adj[cur]) {
            chmax(mx,make_pair(dp[x][1].f-dp[x][0].f +min(n-sz[cur],sz[cur]-1),dp[x][1].s));
            dp[cur][1].f += dp[x][0].f;
            dp[cur][0].f += dp[x][0].f;
        }
        dp[cur][1].f += mx.f; dp[cur][1].s = mx.s; // dp[cur][1]: have removed edge
        dp[cur][0].f += min(n-1-sz[cur],sz[cur]); // dp[cur][0]: have not removed edge
    };
    dfs(start);
    remove = dp[start][1].s; // find which leaf to remove
    for (int i=0;i<n;i++) {if (find(all(adj[i]),remove)!=adj[i].end()) {remove2 = i;}} // find its parent

    vec<int> ans(n); // answer vector
    int cnt = 0;
    function<void(int)> color = [&](int cur) {
        ans[cur] = cnt+1; // assign next unused color in dfs traversal
        cnt = (cnt+1)%(n/2);
        for (int x : adj[cur]) {
            if (x!=remove) {
                color(x);
            }
        }
    };
    color(start);
    
    if (remove<remove2) {swap(ans[remove],ans[remove2]);} // make sure color[max(u,v)]=0

    cout << remove+1 << ' ' << remove2+1 << '\n';
    for (int i=0;i<n;i++) {cout << ans[i] << ' ';}
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}