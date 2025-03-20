#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int n, m; cin >> n >> m;
    v<v<int>> adj(n);
    v<int> par(n), sz(n,1), a(n);
    v<priority_queue<pii,v<pii>,greater<pii>>> comp(n);
    
    F0R(i,n) {par[i]=i;}
    F0R(i,n) {cin >> a[i];}

    F0R(i,m) {
        int u, v; cin >> u >> v;
        adj[--u].pb(--v); adj[v].pb(u);
    }

    auto get1 = [&](auto& get1, int x)->int {return (x==par[x] ? x : (par[x]=get1(get1,par[x])));};
    auto get = [&](int x) {return get1(get1,x);};
    auto unite = [&](int u, int v) { // join priority queues
        int c1 = get(u), c2 = get(v);
        if (comp[c1].size()<comp[c2].size()) {swap(c1,c2);}
        while (comp[c2].size()) {comp[c1].push(comp[c2].top()); comp[c2].pop();}
        par[c2] = c1;
        sz[c1] += sz[c2];
    };

    F0R(i,n) {
        for (int x : adj[i]) { // initialize pqs
            comp[i].push({a[x],x});
        }
    }

    F0R(i,n) {
        if (a[i]) {continue;} // only process valid start points
        int idx = get(i);
        while (comp[idx].size()) { // process pq while possible
            pii x = comp[idx].top();
            if (x.f>sz[idx]) {break;}
            comp[idx].pop();
            if (get(x.s)==idx) {continue;}
            unite(x.s,i); // unite if possible
            idx = get(i);
        }
    }
    cout << (sz[get(0)]==n ? "YES" : "NO") << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t; cin >> t;
    while (t--) {solve();}
}