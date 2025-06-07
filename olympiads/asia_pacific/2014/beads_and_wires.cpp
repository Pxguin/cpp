#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define vec vector

const int MAX_N = 2e5;
vec<pii> adj[MAX_N];
ll dp_down[MAX_N][2], dp_up[MAX_N][2];
ll mx[MAX_N][2];
ll ans = 0;

void dfs_down(int cur) {
    dp_down[cur][0] = 0;
    mx[cur][0] = mx[cur][1] = -1e16;

    for (auto[x,w] : adj[cur]) {
        adj[x].erase(find(all(adj[x]),make_pair(cur,w)));
        dfs_down(x);

        ll push = max(dp_down[x][1]+w,dp_down[x][0]);
        dp_down[cur][0] += push;
        
        ll ex = dp_down[x][0]+w-push;
        if (ex>=mx[cur][0]) {mx[cur][1] = mx[cur][0]; mx[cur][0] = ex;}
        else if (ex>mx[cur][1]) {mx[cur][1] = ex;}
    }
    
    chmax(dp_down[cur][1],dp_down[cur][0]+mx[cur][0]);
}

void dfs_up(int cur) {
    chmax(ans,dp_down[cur][0]+dp_up[cur][0]);
    chmax(ans,dp_down[cur][1]+dp_up[cur][1]);
    
    for (auto[x,w] : adj[cur]) {
        ll push = max(dp_down[x][1]+w,dp_down[x][0]);
        
        ll down0 = dp_down[cur][0]-push;
        ll ex = dp_down[x][0]+w-push;
        ll down1 = down0+mx[cur][ex==mx[cur][0]];

        dp_up[x][0] = dp_up[cur][0]+down0;
        chmax(dp_up[x][0],dp_up[cur][1]+down0+w);
        chmax(dp_up[x][0],dp_up[cur][0]+down1+w);
        
        dp_up[x][1] = dp_up[cur][0]+down0+w;

        dfs_up(x);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    for (int i=0;i<MAX_N;i++) {
        dp_down[i][1] = dp_up[i][1] = -1e10; 
        dp_down[i][0] = dp_up[i][0] = 0;
    }

    int n; cin >> n;
    for (int i=0;i<n-1;i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[--u].pb({--v,w});
        adj[v].pb({u,w});
    }
    dfs_down(0); dfs_up(0);
    cout << ans << '\n';
}