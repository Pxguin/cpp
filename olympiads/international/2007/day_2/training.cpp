#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmax(a, b) a = max(a,b)
#define vec vector

const int N = 1000, K = 10, MX = (1<<K)-1;
vec<int> adj[N];
vec<array<int,3>> todo[N];
int par[N], dep[N], ind[N];
int dp[N][1<<K];

void dfs(int cur=0) { // preliminary
    for (int i=0;i<adj[cur].size();i++) {
        int x = adj[cur][i];
        ind[x] = i; par[x] = cur; dep[x] = dep[cur]+1;
        adj[x].erase(find(adj[x].begin(),adj[x].end(),cur));
        dfs(x);
    }
}
int cost(const int cur, int targ, int& mask) { // (given that there's a path from cur to targ) computes max possible dp sum
    int res = dp[targ][MX];
    while (par[targ]!=cur) {
        res += dp[par[targ]][MX^(1<<ind[targ])];
        targ = par[targ];
    }
    mask |= (1<<ind[targ]);

    return res;
}
void upd(const int cur, const int mask, const int c) { // update bitmask dp
    for (int i=MX;i>=0;i--) {
        if (i&mask) {continue;} // only add if mask and i have no intersection
        chmax(dp[cur][mask|i],dp[cur][i]+c);
    }
}
void dfs2(int cur=0) {
    for (int x : adj[cur]) {
        dfs2(x);
    }
    for (int x : adj[cur]) { // base case: no paths used
        upd(cur,1<<ind[x],dp[x][MX]);
    }

    for (int i=0;i<todo[cur].size();i++) { // using paths
        int a = todo[cur][i][0], b = todo[cur][i][1], c = todo[cur][i][2];
        int mask = 0;
        c += cost(cur,a,mask);
        if (b!=-1) {c += cost(cur,b,mask);} // compute the bitmask of the path and the maximum cost with it
        upd(cur,mask,c); // dp
    }
    for (int mask=0;mask<(1<<K);mask++) { // push bitmask
        for (int b=0;b<K;b++) {
            chmax(dp[cur][mask|(1<<b)],dp[cur][mask]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    par[0] = -1; dep[0] = 0;
    int n, m; cin >> n >> m;
    vec<array<int,3>> non;
    for (int i=0;i<m;i++) {
        int a, b, c; cin >> a >> b >> c;
        if (c!=0) {non.pb({--a,--b,c});} // split edges into two group
        else {
            adj[--a].pb(--b); adj[b].pb(a);
        }
    } dfs();

    int ans = 0;
    for (int i=0;i<m-(n-1);i++) {
        int a = non[i][0], b = non[i][1], c = non[i][2];
        ans += c;
        if (dep[a]<dep[b]) {swap(a,b);}
        int dist = (dep[a]-dep[b])%2;
        int a2 = a, b2 = b;

        while (dep[a]!=dep[b]) {a = par[a];}
        
        while (par[a]!=par[b]) { // finding lca
            a = par[a]; b = par[b];
        }
        if (dist==0) { // ignore edge with dist issue
            if (a==b) {todo[b].pb({a2,-1,c});} // split path (a,b) into (lca,a),(lca,b)
            else {todo[par[a]].pb({a2,b2,c});}
        }
    }

    dfs2();

    ans -= dp[0][MX];
    cout << ans << '\n';
}