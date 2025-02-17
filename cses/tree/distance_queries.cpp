#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 2e5, l2d = 18;
int par[l2d][MAX_N], depth[MAX_N];
v<int> adj[MAX_N];

void dfs(int cur, int p, int d) {
    depth[cur] = d;
    par[0][cur] = p;
    for (int x : adj[cur]) {
        if (x!=p) {
            dfs(x,cur,d+1);
        }
    }
}

int kth_par(int a, int d) {
    for (int i=l2d-1;i>=0;i--) {
        if ((1<<i)&d) {a = par[i][a];}
    } return a;
}

int lca(int a, int b) {
    if (depth[a]>depth[b]) {a = kth_par(a,depth[a]-depth[b]);}
    else {b = kth_par(b,depth[b]-depth[a]);}

    if (a==b) {return a;}
    for (int i=l2d-1;i>=0;i--) {
        if (par[i][a]!=par[i][b]) {
            a = par[i][a];
            b = par[i][b];
        }
    } return par[0][a];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    memset(par,-1,sizeof(par));
    int n, q; cin >> n >> q;
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

    while (q--) {
        int a, b; cin >> a >> b;
        cout << depth[--a]+depth[--b]-2*depth[lca(a,b)] << '\n'; // calc distance
    }

}