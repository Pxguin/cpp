#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() { // unreadable code
    int n, q; cin >> n >> q;
    v<int> par(n+1,0), sz(n+1,1);
    v<int> p(n+1), idx(n+1,0);
    v<set<int>> adj(n+1);

    F0R(i,n-1) {cin >> par[i+2];}
    F0R(i,n) {
        cin >> p[i+1]; 
        idx[p[i+1]] = i+1;
    }
    F0R(i,n) {
        adj[par[i+1]].insert(idx[i+1]);
    }

    auto dfs = [&](auto& dfs, int cur)->void {
        for (int x : adj[cur]) {
            dfs(dfs,p[x]); 
            sz[cur] += sz[p[x]];
        }
    }; dfs(dfs,0);

    int tot_ok = 0;
    v<int> ok(n+1,0);
    auto works = [&](auto it, auto it2) { // does sz(u)+pos(u) = pos(v)
        int cur = p[*it];
        return (idx[cur]+sz[cur]==*it2);
    };
    auto check = [&](int cur) { // do all children of u follow a valid dfs order from u
        return (adj[cur].empty() || (ok[cur]==adj[cur].size()-1 && idx[cur]+1==*adj[cur].begin()));
    };

    auto upd = [&](int cur, int m, int m2, int m3) {
        auto it = adj[par[cur]].find(idx[cur]);

        if (it!=adj[par[cur]].begin() && works(prev(it),it)) { // update w/ child on left
            ok[par[cur]] += m;
        }
        if (it!=prev(adj[par[cur]].end()) && works(it,next(it))) { // update w/ child on right
            ok[par[cur]] += m2;
        }
        if (it!=adj[par[cur]].begin() && it!=prev(adj[par[cur]].end()) && works(prev(it),next(it))) { // connect left & right
            ok[par[cur]] += m3;
        }
    };
    
    F0R(i,n) { // base updates
        upd(i+1,0,1,0);
    }
    F0R(i,n+1) {tot_ok += check(i);}

    F0R(i,q) {
        int x, y; cin >> x >> y;
        if (x>y) {swap(x,y);}
        int a = p[x], b = p[y];

        int sc = (par[a]==par[b] && *next(adj[par[a]].find(x))==y); // side case: they're next to each other in adjacency list
        set<int> to_check = {par[a],par[b],a,b};
        for (int c : to_check) {tot_ok -= check(c);}
        
        upd(a,-1,-1,1-sc); upd(b,-1+sc,-1,1-sc); // remove them from the adjacency list (methodically)
        
        // side case is when they are next to each other :(

        adj[par[a]].erase(idx[a]); adj[par[b]].erase(idx[b]);
        swap(p[x],p[y]);
        swap(idx[a],idx[b]);
        adj[par[a]].insert(idx[a]); adj[par[b]].insert(idx[b]);
        
        upd(b,1,1,-1+sc); upd(a,1-sc,1,-1+sc); // add them back to the adjacency list
        for (int c : to_check) {tot_ok += check(c);}

        cout << (tot_ok==n+1 ? "YES" : "NO") << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}