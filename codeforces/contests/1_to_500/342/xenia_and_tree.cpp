#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmin(a, b) a = min(a,b)
#define vec vector

const int MAX_N = 2e5;
vec<int> adj[MAX_N]; // for original tree
int sz[MAX_N];
bool removed[MAX_N] = {false};
int n;

vec<pair<int,int>> anc[MAX_N];

namespace centroid_decomp {
    int dfs1(int cur, int par=-1) {
        sz[cur] = 1;
        for (int x : adj[cur]) {
            if (x!=par && !removed[x]) {
                sz[cur] += dfs1(x,cur);
            }
        } return sz[cur];
    }
    int dfs2(int cur, int n2, int par=-1) {
        for (int x : adj[cur]) {
            if (x!=par && !removed[x]) {
                if (sz[x]>n2/2) {return dfs2(x,n2,cur);}
            }
        } return cur;
    }
    void dfs3(int cur, int rt, int par=-1, int d=0) {
        anc[cur].pb({rt,d});
        for (int x : adj[cur]) {
            if (x!=par && !removed[x]) {dfs3(x,rt,cur,d+1);}
        }
    }
    void decomp(int cur=0) {
        int cent = dfs2(cur,dfs1(cur));
        dfs3(cent,cent);

        removed[cent] = true;
        for (int x : adj[cent]) {
            if (!removed[x]) {
                decomp(x);
            }
        }
    }
};

namespace queries {
    int mn[MAX_N];
    
    void paint(int x) {
        for (auto[a,d] : anc[x]) {
            chmin(mn[a],d);
        }
    }
    int query(int x) {
        int ret = 1e9;
        for (auto[a,d] : anc[x]) {
            chmin(ret,mn[a]+d);
        } return ret;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int q; cin >> n >> q;
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b); adj[b].pb(a);
    }
    centroid_decomp::decomp();
    for (int i=0;i<n;i++) {queries::mn[i] = 1e9;}
    queries::paint(0);

    while (q--) {
        int t, v; cin >> t >> v; v--;
        if (t==1) {queries::paint(v);}
        else {cout << queries::query(v) << '\n';}
    }
}