#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define vec vector

vec<set<int>> adj; // ok

void solve() {
    int n, m; cin >> n >> m;
    adj.clear(); adj.resize(n);
    vec<array<int,3>> ans;
    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        adj[--a].insert(--b);
        adj[b].insert(a);
    }
    set<pii,greater<pii>> indeg;
    for (int i=0;i<n;i++) {indeg.insert({adj[i].size(),i});}

    while (indeg.begin()->f>1) { // find vertex with degree >= 2
        int a = indeg.begin()->s, b = *adj[a].begin(), c = *next(adj[a].begin()); // select two arbitrary adjacent
        indeg.erase({adj[a].size(),a}); indeg.erase({adj[b].size(),b}); indeg.erase({adj[c].size(),c});
        ans.pb({a,b,c});
        adj[a].erase(b); adj[a].erase(c); // simulate operation (a,b,c)
        adj[b].erase(a); adj[c].erase(a);
        if (adj[b].count(c)) {adj[b].erase(c); adj[c].erase(b);}
        else {adj[b].insert(c); adj[c].insert(b);}
        indeg.insert({adj[a].size(),a}); indeg.insert({adj[b].size(),b}); indeg.insert({adj[c].size(),c});
    }

    if (indeg.begin()->f!=0) { // if the graph is not empty, then turn it into a tree
        int src = indeg.begin()->s, src2 = *adj[src].begin(); // start with this component
        for (int i=0;i<n;i++) { // and join all other components into it
            if (i==src || adj[src].count(i)) {continue;}
            ans.pb({src,src2,i});

            for (int x : adj[i]) {adj[src].insert(x);}
            adj[src].insert(i);
            src2 = i;
        }
    }
    cout << ans.size() << '\n';
    for (auto x : ans) {cout << x[0]+1 << ' ' << x[1]+1 << ' ' << x[2]+1 << '\n';}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}