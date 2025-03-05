#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 2e5, l2d = 18;
v<int> adj[MAX_N];
int depth[MAX_N], lift[l2d][MAX_N];

int dist[2][MAX_N];
int dfs_dist(int cur, int par, int d, int i) { // farthest distance from root
    dist[i][cur] = d;
    int mx = cur;
    for (int x : adj[cur]) {
        if (x!=par) {
            int d2 = dfs_dist(x,cur,d+1,i);
            if (dist[i][d2]>dist[i][mx]) {mx = d2;}
        }
    } return mx;
}

void dfs_init(int cur, int par, int d) {
    depth[cur] = d; lift[0][cur] = par;
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs_init(x,cur,d+1);
        }
    }
}

int jump(int a, int d) {
    F0R(i,l2d) {
        if ((1<<i)&d) {a = lift[i][a];}
    } return a;
}

int lca(int a, int b) {
    if (depth[a]<depth[b]) {swap(a,b);}
    a = jump(a,depth[a]-depth[b]);
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

    memset(lift,-1,sizeof(lift));
    int n; cin >> n;
    F0R(i,n-1) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs_init(0,-1,0);
    FOR(b,1,l2d) {
        F0R(i,n) {
            if (lift[b-1][i]!=-1) {lift[b][i] = lift[b-1][lift[b-1][i]];}
        }
    }

    int a = dfs_dist(0,0,0,0); // get diameter
    int b = dfs_dist(a,a,0,0);
    dfs_dist(b,b,0,1);
    
    int q; cin >> q;
    while (q--) {
        int x, k; cin >> x >> k; x--;
        
        int far = (dist[0][x]>dist[1][x] ? a : b); // which one is farther
        int l = lca(x,far);
        int ans = -2, d = depth[x]-depth[l], d2 = depth[far]-depth[l];
        if (d>=k) {ans = jump(x,k);} // casework to find the node K away from X
        else if (d2>=k-d) {ans = jump(far,d2-(k-d));}
        cout << ans+1 << '\n';
    }
}