#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m; cin >> n >> m;

    v<pair<int,pii>> edges;
    F0R(i,m) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        edges.pb({w,{u,v}});
    } sort(all(edges));
    edges.pb({2e9,{0,0}});

    v<int> par(n), sz(n,1);
    iota(all(par),0);
    auto get = [&](auto& get, int x)->int {return par[x]==x ? x : par[x]=get(get,par[x]);};
    auto unite = [&](int x, int y) {
        int a = get(get,x), b = get(get,y);
        if (a==b) {return false;}
        if (sz[a]<sz[b]) {swap(a,b);}
        sz[a] += sz[b]; par[b] = a;
        return true;
    };
    int mst = 0, tot = 0;
    int ptr = 0;
    F0R(i,m+1) {
        if (edges[i].f!=edges[ptr].f) {
            FOR(j,ptr,i) { // test new batch of edges
                if (get(get,edges[j].s.f)!=get(get,edges[j].s.s)) {tot++;}
            }
            FOR(j,ptr,i) { // actually build the mst
                if (unite(edges[j].s.f,edges[j].s.s)) {mst++;}
            }

            ptr = i; i--;
        }
    } cout << tot-mst << '\n';
}