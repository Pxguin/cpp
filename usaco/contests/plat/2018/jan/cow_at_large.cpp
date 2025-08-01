#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define vec vector

const int N = 7e4;
vec<int> adj[N];
int leaf[N], ans[N] = {0};
int n;

namespace centroid {
    int sz[N];
    bool del[N] = {false};
    int get_sizes(int cur, int par=-1) { // for finding centroid
        sz[cur] = 1;
        for (int x : adj[cur]) {
            if (!del[x] && x!=par) {
                sz[cur] += get_sizes(x,cur);
            }
        } return sz[cur];
    }
    int get_cent(int cur, int n, int par=-1) { // for finding centroid
        for (int x : adj[cur]) {
            if (!del[x] && x!=par) {
                if (sz[x]*2>n) {return get_cent(x,n,cur);}
            }
        } return cur;
    }

    int ps[N], ps2[N];
    vec<int> comp;
    int mxdep[N], dep[N], mn_up[N], mn_down[N];
    void calc(int cur, int par=-1, int d=0) {
        dep[cur] = mxdep[cur] = d; // mxdep[x]: max(dep[u]) for all u in subtree of x

        for (int x : adj[cur]) {
            if (!del[x] && x!=par) {
                mn_up[x] = min(mn_up[cur],d+1+leaf[x]);  // mn_up[x]: min(dep[u]+leaf[u]) for all u on path from x to cent (not including cent)
                mn_down[x] = min(mn_down[cur],leaf[cur]-d); // mn_down[x]: min(leaf[u]-dep[u]) for all u on path from cent to x (not including x)

                calc(x,cur,d+1);
                chmax(mxdep[cur],mxdep[x]);
            }
        }
    }
    void add_qry(int cur, int rt, int cent, int par=-1) { // add queries
        comp.pb(cur);
        int a = max(0,leaf[cur]-dep[cur]), b = mn_down[cur]-1;
        if (a<=b) { // this node is ok for any x such that dep[x] in [a,b] (use prefix sums)
            if (a<=mxdep[cent]) {ps[a]++;} // limit to mxdep
            if (b+1<=mxdep[cent]) {ps[b+1]--;}

            if (a<=mxdep[rt]) {ps2[a]++;}
            if (b+1<=mxdep[rt]) {ps2[b+1]--;}
        }

        for (int x : adj[cur]) {
            if (!del[x] && x!=par) {
                add_qry(x,rt,cent,cur);
            }
        }
    }

    void decomp(int cur=0) {
        int cent = get_cent(cur,get_sizes(cur)); // get centroid
        del[cent] = true;

        mn_up[cent] = mn_down[cent] = 1e9;
        calc(cent); // compute dep, mxdep, mn_up, mn_down,

        fill(ps,ps+mxdep[cent]+1,0);
        comp.clear();

        comp.pb(cent);
        if (leaf[cent]<=mxdep[cent]) {ps[leaf[cent]]++;}

        for (int x : adj[cent]) {
            if (!del[x]) {
                int z = comp.size();
                fill(ps2,ps2+mxdep[x]+1,0);
                add_qry(x,x,cent);

                
                for (int i=1;i<=mxdep[x];i++) {ps2[i] += ps2[i-1];}
                for (int i=z;i<comp.size();i++) { // subtraction queries to avoid overcount
                    int u = comp[i];
                    if (dep[u]<mn_up[u]) { // must be valid
                        ans[u] -= ps2[dep[u]];
                    }
                }
            }
        }

        for (int i=1;i<=mxdep[cent];i++) {ps[i] += ps[i-1];}
        for (int u : comp) { // add amount of good nodes for each node
            if (dep[u]<mn_up[u]) {
                ans[u] += ps[dep[u]];
            }
        }

        for (int x : adj[cent]) {
            if (!del[x]) {decomp(x);}
        }
    }
}

void dfs_down(int cur=0, int par=-1) { // propagate up
    leaf[cur] = 1e9;
    if (adj[cur].size()==1) {leaf[cur] = 0;}
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs_down(x,cur);
            chmin(leaf[cur],leaf[x]+1);
        }
    }
}
void dfs_up(int cur=0, int par=-1) { // propagate down
    for (int x : adj[cur]) {
        if (x!=par) {
            chmin(leaf[x],leaf[cur]+1);
            dfs_up(x,cur);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("atlarge.in","r",stdin);
    freopen("atlarge.out","w",stdout);

    cin >> n;
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b); adj[b].pb(a);
    }
    dfs_down(); dfs_up(); // min dist to a leaf
    centroid::decomp();
    for (int i=0;i<n;i++) {cout << ans[i] << '\n';}
}