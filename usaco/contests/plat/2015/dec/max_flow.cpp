#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 50000, l2d = 16;
int par[l2d][MAX_N], depth[MAX_N];
v<int> adj[MAX_N];
int inc[MAX_N] = {0}, dec1[MAX_N] = {0};
int ans = 0;

void dfs(int cur, int p, int d) {
    depth[cur] = d;
    par[0][cur] = p;
    for (int x : adj[cur]) {
        if (x!=p) {
            dfs(x,cur,d+1);
        }
    }
}

void ans_dfs(int cur, int p) {
    int s = inc[cur];
    for (int x : adj[cur]) {
        if (x!=p) {
            ans_dfs(x,cur);
            inc[cur] += inc[x];
            dec1[cur] += dec1[x];
        }
    }

    chmax(ans,dec1[cur]-(inc[cur]-s)); // # paths going through = # ending in subtree - # starting in subtree + # paths starting at cur
}

int lift(int a, int d) {
    for (int i=l2d-1;i>=0;i--) {
        if ((1<<i)&d) {a = par[i][a];}
    } return a;
}

void add(int a, int b) {
    int a1 = a, b1 = b;
    if (depth[a1]>depth[b1]) {swap(a1,b1);}

    if (depth[a]>depth[b]) {a = lift(a,depth[a]-depth[b]);}
    else {b = lift(b,depth[b]-depth[a]);}

    if (a==b) { // one is an ancestor of other, so it's already fine
        inc[a1]++; dec1[b1]++;
    } else { // split into three paths, such that one node is an ancestor of the other for each path
        for (int i=l2d-1;i>=0;i--) {
            if (par[i][a]!=par[i][b]) {
                a = par[i][a];
                b = par[i][b];
            }
        }
        int lca = par[0][a];
        inc[lca]++; dec1[lca]++; // first path: [lca,lca]
        inc[lift(a1,depth[a1]-depth[lca]-1)]++; dec1[a1]++; // second path [one node deeper than lca, a]
        inc[lift(b1,depth[b1]-depth[lca]-1)]++; dec1[b1]++; // third path [one node deeper than lca, b]
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("maxflow.in","r",stdin);
    freopen("maxflow.out","w",stdout);
    
    memset(par,-1,sizeof(par));
    int n, k; cin >> n >> k;
    F0R(i,n-1) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs(0,-1,0);

    FOR(p,1,l2d) {
        F0R(i,n) {
            if (par[p-1][i]!=-1) {
                par[p][i] = par[p-1][par[p-1][i]];
            }
        }
    }

    F0R(i,k) {
        int a, b; cin >> a >> b;
        add(--a,--b);
    }
    ans_dfs(0,0);
    cout << ans << '\n';
}