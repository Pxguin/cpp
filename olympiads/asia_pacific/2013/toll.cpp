#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define all(x) x.begin(),x.end()
#define vec vector

const int MAX_N = 1e5, MAX_M = 3e5, MAX_K = 21;

struct DSU {
    vec<int> par, sz;
    int n;
    DSU(int n1) {
        n = n1;
        sz = vec<int>(n,1);
        par = vec<int>(n);
        iota(all(par),0);
    }
    int get(int x) {return (par[x]==x ? x : par[x]=get(par[x]));} 
    bool merge(int a, int b) {
        a = get(a); b = get(b);
        if (a==b) {return false;}
        if (sz[a]<sz[b]) {swap(a,b);}
        par[b] = a; sz[a] += sz[b];
        return true;
    }
};
struct Edge {
    int u, v; ll w;
    Edge() {};
    Edge(int u1, int v1, ll w1) : u(u1), v(v1), w(w1) {};
    bool operator<(const Edge& o) {return w<o.w;}
};

ll new_p[MAX_K] = {0}; // population of node in compressed graph

// for compressed graph
vec<Edge> adj[MAX_K];
DSU mst3(MAX_K);
int pa[MAX_K], dep[MAX_K];
ll psum[MAX_K] = {0}, val[MAX_K] = {0};
ll ans = 0;

void reset() { // clear mst, adj, etc
    for (int i=0;i<MAX_K;i++) {adj[i].clear();}
    mst3.sz.assign(MAX_K,1);
    iota(all(mst3.par),0);
}
bool trymerge(int a, int b, ll c) { // maintain dsu + adjacency list
    if (mst3.merge(a,b)) {
        adj[a].pb(Edge(a,b,c)); adj[b].pb(Edge(b,a,c));
        return true;
    } return false;
}

void precalc(int cur, int p, int d) {
    pa[cur] = p; psum[cur] = new_p[cur]; dep[cur] = d;
    for (Edge& x : adj[cur]) {
        if (x.v!=p) {
            precalc(x.v,cur,d+1);
            psum[cur] += psum[x.v];
            val[x.v] = x.w;
        }
    }
}
void updweight(int a, int b, ll c) { // updates weights of all nodes on path from a to b
    if (dep[a]<dep[b]) {swap(a,b);}
    while (dep[a]!=dep[b]) {
        chmin(val[a],c);
        a = pa[a];
    }
    while (a!=b) {
        chmin(val[a],c); chmin(val[b],c);
        a = pa[a]; b = pa[b];
    }
}
ll dfsans(int cur, int p) { // get answer
    ll ret = 0;
    for (Edge& x : adj[cur]) {
        if (x.v!=p) {ret += dfsans(x.v,cur);}
    } return ret+val[cur]*psum[cur];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, k; cin >> n >> m >> k;
    Edge old_e[MAX_M]; // old edges
    Edge new_e[MAX_M]; // new edges
    ll p[MAX_N]; // population

    for (int i=0;i<m;i++) { // read in old edges
        cin >> old_e[i].u >> old_e[i].v >> old_e[i].w;
        old_e[i].u--; old_e[i].v--;
    }
    for (int i=0;i<k;i++) { // read in new edges
        cin >> new_e[i].u >> new_e[i].v; new_e[i].w = LLONG_MAX;
        new_e[i].u--; new_e[i].v--;
    }
    sort(old_e,old_e+m); // sort for kruskals

    for (int i=0;i<n;i++) {cin >> p[i];}

    vec<Edge> extra, add; // add: edges in mst, extra: edges in mst that are replaced by new edges
    DSU mst1(n), mst2(n);
    for (int i=0;i<k;i++) {mst2.merge(new_e[i].u,new_e[i].v);} // mst2: initially has all k new edges
    for (int i=0;i<m;i++) {
        bool s1 = mst1.merge(old_e[i].u,old_e[i].v); // mst1: does not have any k edges
        if (s1!=mst2.merge(old_e[i].u,old_e[i].v)) { // if it merges in first mst but not in second mst, then it belongs to "extra"
            extra.pb(old_e[i]);
        } else if (s1) { // if it merged in both msts then whatever
            add.pb(old_e[i]);
        }
    }

    mst1 = DSU(n);
    for (Edge e : add) {mst1.merge(e.u,e.v);} // compress all trees in the forest into nodes
    int comp[MAX_N]; memset(comp,-1,sizeof(comp));
    for (int i=0;i<n;i++) {comp[mst1.get(i)] = 1;}
    int c = 0;
    for (int i=0;i<n;i++) {
        if (comp[i]!=-1) {comp[i] = c++;}
    }
    for (int i=0;i<n;i++) {new_p[comp[i]=comp[mst1.get(i)]] += p[i];} // population of a compressed tree = sum of populations of nodes in tree
    for (Edge& e : extra) {e.u = comp[e.u]; e.v = comp[e.v];} // update all edges
    for (int i=0;i<k;i++) {new_e[i].u = comp[new_e[i].u]; new_e[i].v = comp[new_e[i].v];}

    for (int mask=0;mask<(1<<k);mask++) { // fix which set of new edges to use
        reset();
        for (int i=0;i<k;i++) {
            if ((1<<i)&mask) { // add these edges to mst
                trymerge(new_e[i].u,new_e[i].v,new_e[i].w);
            }
        }
        vec<Edge> cyc;
        for (int i=0;i<k;i++) { // add the "extra" edges and store which ones don't merge
            if (!trymerge(extra[i].u,extra[i].v,0)) {cyc.pb(extra[i]);}
        }
        
        precalc(comp[0],-1,0);
        for (Edge& e : cyc) {updweight(e.u,e.v,e.w);} // they are used to find max weight of new edges
        chmax(ans,dfsans(comp[0],-1)); // calculate answer with dfs
        
    } cout << ans << '\n';
}