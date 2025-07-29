#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmin(a, b) a = min(a,b)
#define vec vector

const int N = 3e5, l2 = 19;
int sz[N];
bool del[N] = {false};
vec<int> adj[N];
int d[N], ans[N] = {0};
int n;

namespace centroid_decomp { 
    int dist[N] = {0}, dist2[N] = {0}, mxdep[N], dep[N];
    vec<int> comp;
    int ex, ex2;

    int upd_sizes(int cur, int par=-1) {
        sz[cur] = 1;
        for (int x : adj[cur]) {
            if (x!=par && !del[x]) {
                sz[cur] += upd_sizes(x,cur);
                mxdep[cur] = max(mxdep[cur],mxdep[x]);
            }
        }
        return sz[cur];
    }
    int find_cent(int cur, int n2, int par=-1) {
        for (int x : adj[cur]) {
            if (x!=par && !del[x]) {
                if (sz[x]*2>n2) {return find_cent(x,n2,cur);}
            }
        } return cur;
    }
    void dfs(int cur, int par=-1, int d2=0) {
        mxdep[cur] = dep[cur] = d2;
        for (int x : adj[cur]) {
            if (x!=par && !del[x]) {
                dfs(x,cur,d2+1);
                mxdep[cur] = max(mxdep[cur],mxdep[x]);
            }
        }
    }
    void add_comp(int cur, const int rt, const int cent, int par=-1) {
        int a = d[cur]-dep[cur];
        if (a>=0) {
            if (a<=rt) {dist2[a]++;}
            else {
                ex++;
                if (a<=cent) {dist[a]++;}
                else {ex2++;}
            }
        }
        comp.pb(cur);

        for (int x : adj[cur]) {
            if (x!=par && !del[x]) {
                add_comp(x,rt,cent,cur);
            }
        }
    }
    
    void decomp(int cur=0) {
        int cent = find_cent(cur,upd_sizes(cur));
        del[cent] = true;
        
        dfs(cent);
        fill(dist,dist+mxdep[cent]+1,0);
        comp.clear(); comp.pb(cent);

        ex2 = 0;
        if (d[cent]>=0) { // store suffix sums on d[i]-dep[i]
            if (d[cent]<=mxdep[cent]) {dist[d[cent]]++;}
            else {ex2++;} // query range is [0,max(dep)] so don't store any d[i]-dep[i]>max(dep)
        }

        int sz = 1;
        for (int x : adj[cent]) {
            if (!del[x]) {
                fill(dist2,dist2+mxdep[x]+1,0);
                ex = 0;
                
                add_comp(x,mxdep[x],mxdep[cent]);
                for (int i=mxdep[x];i>=0;i--) {
                    dist[i] += dist2[i]; // add to global array
                    if (i<mxdep[x]) {dist2[i] += dist2[i+1];} // suffix sums
                }
                for (int i=sz;i<comp.size();i++) { // subtraction queries
                    ans[comp[i]] -= dist2[dep[comp[i]]]+ex;
                }
                sz = comp.size();
            }
        }
        for (int i=mxdep[cent]-1;i>=0;i--) {
            dist[i] += dist[i+1];
        }
        for (int x : comp) { // addition queries
            ans[x] += dist[dep[x]]+ex2;
        }

        for (int x : adj[cent]) {
            if (!del[x]) {
                decomp(x);
            }
        }
    }
}
namespace LCA {
    int dep[N], lift[l2][N];
    void dfs(int cur, int par=-1, int d=0) {
        dep[cur] = d; lift[0][cur] = par;
        for (int x : adj[cur]) {
            if (x!=par) {dfs(x,cur,d+1);}
        }
    }
    void init() {
        memset(lift,-1,sizeof(lift));
        dfs(0);
        for (int b=1;b<l2;b++) {
            for (int i=0;i<n;i++) {
                if (lift[b-1][i]!=-1) {lift[b][i] = lift[b-1][lift[b-1][i]];}
            }
        }
    }
    int jump(int a, int d) {
        for (int i=0;i<l2;i++) {
            if ((1<<i)&d) {a = lift[i][a];}
        } return a;
    }
    int lca(int a, int b) {
        a = jump(a,dep[a]-dep[b]);
        if (a==b) {return a;}
        for (int i=l2-1;i>=0;i--) {
            if (lift[i][a]!=lift[i][b]) {
                a = lift[i][a]; b = lift[i][b];
            }
        } return lift[0][a];
    }
    int dist(int a, int b) {
        if (dep[a]<dep[b]) {swap(a,b);}
        return dep[a]+dep[b]-2*dep[lca(a,b)];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int k; cin >> n >> k;
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b); adj[b].pb(a);
    }
    LCA::init();
    queue<int> q;
    fill(d,d+n,INT_MAX);
    for (int i=0;i<k;i++) {
        int a; cin >> a;
        q.push(--a); d[a] = 0;
    }
    while (q.size()) { // closest shop to each person
        int cur = q.front(); q.pop();
        for (int x : adj[cur]) {
            if (d[x]==INT_MAX) {
                d[x] = d[cur]+1;
                q.push(x);
            }
        }
    }
    for (int i=0;i<n;i++) {
        int f, p; cin >> f >> p;
        chmin(d[i],LCA::dist(i,--f)-p-1); // compute d[i]
    }
    centroid_decomp::decomp(); // process all d[i] with centroid decomp

    for (int i=0;i<n;i++) {cout << ans[i] << ' ';}
}