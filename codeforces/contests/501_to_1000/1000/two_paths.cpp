#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define vec vector

const int MAX_N = 3e5, l2d = 19;
int dep[MAX_N], lift[l2d][MAX_N];
ll dist[MAX_N], out[MAX_N], path[MAX_N], val[MAX_N], in[MAX_N];

vec<pii> adj[MAX_N];
ll ar[MAX_N];

void dfs(int cur, int par) {
    lift[0][cur] = par;
    for (int i=1;i<l2d;i++) { // calc bin lift
        if (lift[i-1][cur]!=-1) {lift[i][cur] = lift[i-1][lift[i-1][cur]];}
    }
    in[cur] = ar[cur]; // best twopath inside the subtree of cur
    for (auto[x,w] : adj[cur]) {
        if (x!=par) {
            dep[x] = dep[cur]+1; // depth of node
            dist[x] = dist[cur]+w; // distance from root
            dfs(x,cur);
            val[x] = max(0LL,in[x]-2*w); // contribution of child to parent in[] value
            in[cur] += val[x]; // as seen
        }
    }
}

void dfs2(int cur, int par) {
    for (auto[x,w] : adj[cur]) {
        if (x!=par) {
            ll d = in[cur]-val[x];
            path[x] = path[cur]+d; // as to query sum of best two paths along any path
            out[x] = max(0LL,out[cur]+d-2*w); // best two path outside subtree
            dfs2(x,cur);
        }
    }
}

int jump(int a, int d) {
    for (int i=0;i<l2d;i++) {
        if ((1<<i)&d) {a = lift[i][a];}
    } return a;
}

int lca(int a, int b) {
    b = jump(b,dep[b]-dep[a]);
    if (a==b) {return a;}
    for (int i=l2d-1;i>=0;i--) {
        if (lift[i][a]!=lift[i][b]) {
            a = lift[i][a];
            b = lift[i][b];
        }
    } return lift[0][a];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    memset(lift,-1,sizeof(lift));
    
    int n, q; cin >> n >> q;
    for (int i=0;i<n;i++) {cin >> ar[i];}
    for (int i=0;i<n-1;i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[--a].pb({--b,w});
        adj[b].pb({a,w});
    }
    dfs(0,-1); dfs2(0,-1);
    while (q--) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (dep[a]>dep[b]) {swap(a,b);}
        int c = lca(a,b);
        int b1 = jump(b,dep[b]-dep[c]-1), a1 = jump(a,dep[a]-dep[c]-1);
        
        ll ans = -(dist[a]+dist[b]-2*dist[c]); // subtract length of simple path from a to b
        if (c==a) { // if a is an ancestor of b then side case
            ans += in[b]+(path[b]-path[c])+out[a];
        } else {
            ans += in[b]+in[a]+(path[b]-path[b1])+(path[a]-path[a1]); // in[a], in[b]: best twopaths for a, b;
            ans += out[c]+(in[c]-val[a1]-val[b1]); // path[b]-path[b1]: sum of best twopaths for nodes on path from b to c (exclusive);
        } cout << ans << '\n'; // out[c]+(in[c]-val[a1]-val[b1]): best twopath for c
    }
}