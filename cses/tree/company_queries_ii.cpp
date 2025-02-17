#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 2e5, l2d = 18;
int par[l2d][MAX_N], depth[MAX_N];
v<int> adj[MAX_N];

void dfs(int cur, int d) {
    depth[cur] = d;
    for (int x : adj[cur]) {
        dfs(x,d+1);
    }
}

int kth_par(int a, int d) {
    for (int i=l2d-1;i>=0;i--) {
        if ((1<<i)&d) {a = par[i][a];}
    } return a;
}

int lca(int a, int b) {
    if (depth[a]>depth[b]) {a = kth_par(a,depth[a]-depth[b]);} // lift one to same depth as other
    else {b = kth_par(b,depth[b]-depth[a]);}

    if (a==b) {return a;} // side case: one is ancestor of other
    for (int i=l2d-1;i>=0;i--) {
        if (par[i][a]!=par[i][b]) { // lift both up while they don't meet
            a = par[i][a];
            b = par[i][b];
        }
    } return par[0][a]; // parent = lca
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    memset(par,-1,sizeof(par));
    int n, q; cin >> n >> q;
    F0R(i,n-1) {
        int a; cin >> a;
        par[0][i+1] = --a;
        adj[a].pb(i+1);
    }
    dfs(0,0);

    FOR(p,1,l2d) {
        F0R(i,n) {
            if (par[p-1][i]!=-1) {
                par[p][i] = par[p-1][par[p-1][i]];
            }
        }
    }

    while (q--) {
        int a, b; cin >> a >> b;
        cout << lca(--a,--b)+1 << '\n';
    }

}