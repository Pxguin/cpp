#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 50000, l2d = 16;
v<int> adj[MAX_N];
bool vis[MAX_N] = {false};
pii edges[MAX_N];
int par[l2d][MAX_N], mn[l2d][MAX_N], depth[MAX_N];

void dfs(int cur, int p, int d) {
    depth[cur] = d;
    par[0][cur] = p;
    for (int x : adj[cur]) {
        if (x!=p) {
            dfs(x,cur,d+1);
        }
    }
}

int lift(int a, int d) {
    for (int i=l2d-1;i>=0;i--) {
        if ((1<<i)&d) {a = par[i][a];}
    } return a;
}

void path(int a, int b, int c) { // basically lazy propagation on trees
    int x = a, d = depth[a]-depth[b];
    for (int i=l2d-1;i>=0;i--) {
        if (d&(1<<i)) {
            chmin(mn[i][x],c);
            x = par[i][x];
        }
    }
}

void add(int a, int b, int c) {
    int a1 = a, b1 = b;
    if (depth[a1]>depth[b1]) {swap(a1,b1);}

    if (depth[a]>depth[b]) {a = lift(a,depth[a]-depth[b]);}
    else {b = lift(b,depth[b]-depth[a]);}

    int lca;
    if (a==b) {
        lca = a;
    } else {
        for (int i=l2d-1;i>=0;i--) {
            if (par[i][a]!=par[i][b]) {
                a = par[i][a];
                b = par[i][b];
            }
        } lca = par[0][a];
    }
    path(a1,lca,c); // make path from (a,lca)
    if (lca!=b1) {
        path(b1,lca,c); // make path from (b,lca)
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("disrupt.in","r",stdin);
    freopen("disrupt.out","w",stdout);

    memset(par,-1,sizeof(par));
    int n, m; cin >> n >> m;
    F0R(i,n-1) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
        edges[i] = {a,b};
    }
    F0R(i,MAX_N) {F0R(j,l2d) {mn[j][i] = INT_MAX;}}
    dfs(0,0,0);
    FOR(p,1,l2d) { // calc binary lifting & lca arrays
        F0R(i,n) {
            if (par[p-1][i]!=-1) {
                par[p][i] = par[p-1][par[p-1][i]];
            }
        }
    }
    while (m--) {
        int p, q, r; cin >> p >> q >> r;
        add(--p,--q,r);
    }
    for (int p=l2d-1;p>=1;p--) { // propagate the lazy propagation
        F0R(i,n) {
            chmin(mn[p-1][i],mn[p][i]);
            if (par[p-1][i]!=-1) {
                chmin(mn[p-1][par[p-1][i]],mn[p][i]);
            }
        }
    }
    F0R(i,n-1) { // answer queries
        if (depth[edges[i].f]<depth[edges[i].s]) {swap(edges[i].f,edges[i].s);}
        cout << (mn[0][edges[i].f]==INT_MAX ? -1 : mn[0][edges[i].f]) << '\n';
    }
}