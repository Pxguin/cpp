#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define vec vector

class DSU {
    public:
    vec<int> par, sz;
    vec<pair<int&,int>> hist;

    DSU(int n) : par(n), sz(n,1) {iota(all(par),0);}
    int get(int x) {return par[x]==x ? x : get(par[x]);}
    void unite(int a, int b, bool c) {
        a = get(a); b = get(b);
        if (a==b) {return;}
        if (sz[a]<sz[b]) {swap(a,b);}
        if (c) {
            hist.pb({sz[a],sz[a]});
            hist.pb({par[b],par[b]});
        }
        par[b] = a; sz[a] += sz[b];
    }
    void rb() {
        while (hist.size()) {
            for (int i=0;i<2;i++) {
                hist.back().f = hist.back().s;
                hist.pop_back();
            }
        }
    }
    void reset() {
        hist.clear();
        fill(all(sz),1);
        iota(all(par),0);
    }
};

const int B = 1000;
struct Edge {
    int u, v, w, id;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    vec<Edge> ed(m);
    for (int i=0;i<m;i++) {
        cin >> ed[i].u >> ed[i].v >> ed[i].w;
        ed[i].u--; ed[i].v--;
        ed[i].id = i;
    }

    int q; cin >> q;
    vec<Edge> qry(q); 
    vec<int> ans(q,-1);
    
    vec<bool> bad(m,false);
    vec<vec<int>> weights(q);

    vec<int> bad_idx, good_ed, good_qry;

    DSU dsu(n);

    for (int b=0;b<(q+B-1)/B;b++) {
        dsu.reset();
        bad_idx.clear(); good_ed.clear(); good_qry.clear();

        int l = b*B, r = min(q,b*B+B);
        for (int i=l;i<r;i++) {
            cin >> qry[i].u >> qry[i].v >> qry[i].w; qry[i].v--;
            qry[i].id = i;
            if (qry[i].u==1) { // isolate all edges that are updated
                if (!bad[qry[i].v]) {bad_idx.pb(i);}
                bad[qry[i].v] = true;
            } else {good_qry.pb(i);}
        }
        for (int i=m-1;i>=0;i--) { // find all edges that aren't updated
            if (!bad[i]) {good_ed.pb(i);}
        }
        sort(all(good_ed),[&](int a, int c) {return ed[a].w>ed[c].w;}); // sort edges by dec weight
        sort(all(good_qry),[&](int a, int c) {return qry[a].w>qry[c].w;}); // sort queries by dec weight

        for (int i : bad_idx) {weights[l].pb(i==l ? qry[i].w : ed[qry[i].v].w);}
        for (int i=l+1;i<r;i++) { // compute weights of all updated edges at each point
            for (int j=0;j<bad_idx.size();j++) {
                weights[i].pb((qry[i].u==1 && qry[i].v==qry[bad_idx[j]].v) ? qry[i].w : weights[i-1][j]);
            }
        }
        
        int ed_ptr = 0;
        for (int i : good_qry) {
            while (ed_ptr<good_ed.size() && ed[good_ed[ed_ptr]].w>=qry[i].w) { // 2p to find the set of not-updated edges for each query
                int e = good_ed[ed_ptr];
                dsu.unite(ed[e].u,ed[e].v,false);
                ed_ptr++; 
            }
            for (int j=0;j<weights[i].size();j++) { // brute force the set of updated edges
                if (weights[i][j]>=qry[i].w) {
                    int k = qry[bad_idx[j]].v;
                    dsu.unite(ed[k].u,ed[k].v,true);
                }
            }
            ans[i] = dsu.sz[dsu.get(qry[i].v)]; // get answer
            dsu.rb(); // remove the set of updated edges
        }
        for (int j=0;j<bad_idx.size();j++) { // update weights of edges, and reset variables
            ed[qry[bad_idx[j]].v].w = weights[r-1][j];
            bad[qry[bad_idx[j]].v] = false;
        }
    }
    for (int i=0;i<q;i++) {if (ans[i]!=-1) {cout << ans[i] << '\n';}}
}