#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define v vector

const int MAX_N = 1e5+1, l2d = 17;
int bit[MAX_N+1] = {0};
void add(int i, int a) { // fenwick tree
    for (;i<=MAX_N;i+=(i&-i)) {bit[i] ^= a;}
}
int sum(int i) { // return sum of xor from root to some node
    int res = 0;
    for(;i;i-=(i&-i)) {res ^= bit[i];}
    return res;
}

int tin[MAX_N], tout[MAX_N], depth[MAX_N], e[MAX_N];
v<int> adj[MAX_N];
int timer = 1;

int lift[l2d][MAX_N];

void dfs(int cur, int par, int d) { // set up lca and euler tour
    lift[0][cur] = par;
    depth[cur] = d;
    tin[cur] = timer++;
    for (int x : adj[cur]) {
        if (x!=par) {dfs(x,cur,d+1);}
    }
    tout[cur] = timer;

    add(tin[cur],e[cur]);
    add(tout[cur],e[cur]);
}

int kthpar(int a, int d) { // set up lca
    for (int i=0;i<l2d;i++) {
        if ((1<<i)&d) {a = lift[i][a];}
    } return a;
}

int lca(int a, int b) {
    if (depth[a]<depth[b]) {swap(a,b);}
    a = kthpar(a,depth[a]-depth[b]);
    if (a==b) {return a;}
    for (int i=l2d-1;i>=0;i--) {
        if (lift[i][a]!=lift[i][b]) {
            a = lift[i][a];
            b = lift[i][b];
        }
    }
    
    return lift[0][a];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("cowland.in","r",stdin);
    freopen("cowland.out","w",stdout);

    memset(lift,-1,sizeof(lift));
    int n, q; cin >> n >> q;
    for (int i=0;i<n;i++) {cin >> e[i];}
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs(0,-1,0); // set up euler tour
    
    for (int b=1;b<l2d;b++) { // set up lca
        for (int i=0;i<n;i++) {
            if (lift[b-1][i]!=-1) {lift[b][i] = lift[b-1][lift[b-1][i]];}
        }
    }
    
    while (q--) {
        int t, a, b; cin >> t >> a >> b;
        if (t==1) {
            a--;
            add(tin[a],b^e[a]); // update fenwick tree
            add(tout[a],b^e[a]);
            e[a] = b;
        } else {
            a--; b--;
            cout << (sum(tin[a])^sum(tin[b])^e[lca(a,b)]) << '\n'; // xor sum
        }
    }
}