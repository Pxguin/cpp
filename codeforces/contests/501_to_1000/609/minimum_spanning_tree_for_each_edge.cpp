#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define vec vector

const int MAX_N = 2e5, l2d = 19;
vec<pii> adj[MAX_N];
int lift[l2d][MAX_N], mx[l2d][MAX_N], dep[MAX_N];

void dfs(int cur, int par) {
    for (pii x : adj[cur]) {
        if (x.f!=par) {
            dep[x.f] = dep[cur]+1;
            lift[0][x.f] = cur;
            mx[0][x.f] = x.s;
            dfs(x.f,cur);
        }
    }
}

int lca(int a, int b) {
    if (dep[a]<dep[b]) {swap(a,b);}
    int d = dep[a]-dep[b];
    F0R(i,l2d) {
        if ((1<<i)&d) {a = lift[i][a];}
    }
    if (a==b) {return a;}
    for (int i=l2d-1;i>=0;i--) {
        if (lift[i][a]!=lift[i][b]) {
            a = lift[i][a];
            b = lift[i][b];
        }
    } return lift[0][a];
}

int get_mx(int a, int b) {
    int l = lca(a,b);
    int d1 = dep[a]-dep[l], d2 = dep[b]-dep[l];
    int ret = 0;
    F0R(i,l2d) {
        if ((1<<i)&d1) {chmax(ret,mx[i][a]); a = lift[i][a];}
        if ((1<<i)&d2) {chmax(ret,mx[i][b]); b = lift[i][b];}
    } return ret;
}

struct DSU {
    int par[MAX_N], sz[MAX_N];
    DSU() {
        F0R(i,MAX_N) {par[i] = i; sz[i] = 1;}
    }
    int get(int x) {return par[x]==x ? x : par[x]=get(par[x]);}
    bool join(int x, int y) {
        int a = get(x), b = get(y);
        if (a==b) {return false;}
        if (sz[a]<sz[b]) {swap(a,b);}
        sz[a] += sz[b]; par[b] = a;
        return true;
    }
};

struct Edge {
    int u, v, w, id;
    Edge(int u, int v, int w, int id) : u(u), v(v), w(w), id(id) {};
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    DSU dsu;
    int n, m; cin >> n >> m;
    vec<Edge> edges;
    F0R(i,m) {
        int a, b, w; cin >> a >> b >> w;
        edges.pb(Edge(--a,--b,w,i));
    }
    sort(all(edges),[&](const Edge& x, const Edge& y) {return x.w<y.w;});
    vec<bool> in(m,false);
    ll tot = 0;
    F0R(i,m) { // kruskal's
        if (dsu.join(edges[i].u,edges[i].v)) {
            in[edges[i].id] = true; // mark off which edges are in mst
            adj[edges[i].u].pb({edges[i].v,edges[i].w});
            adj[edges[i].v].pb({edges[i].u,edges[i].w});
            tot += edges[i].w;
        }
    }
    dep[0] = 0;
    memset(lift,-1,sizeof(lift));
    dfs(0,0); // dfs to precalculate bin lift, to get max weight of edge on any path in tree
    FOR(b,1,l2d) {
        F0R(i,n) {
            int to = lift[b-1][i];
            if (to!=-1 && lift[b-1][to]!=-1) {
                lift[b][i] = lift[b-1][to];
                mx[b][i] = max(mx[b-1][i],mx[b-1][to]);
            }
        }
    }
    sort(all(edges),[&](const Edge& x, const Edge& y) {return x.id<y.id;});

    F0R(i,m) {
        if (in[i]) {cout << tot << '\n';} // if it's in the mst, ignore it
        else {
            cout << tot+edges[i].w-get_mx(edges[i].u,edges[i].v) << '\n'; // remove the heaviest edge on the path between the endpoints of this edge
        }
    }
}