#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vec vector

const int MAX_N = 2e5;
vec<int> adj[MAX_N];
set<int> comp[MAX_N];
int y = 0;

int par[MAX_N];
int get(int x) {return par[x]==x ? par[x] : par[x]=get(par[x]);}
void join(int a, int b) {
    a = get(a); b = get(b);
    if (a==b) {return;}
    if (comp[a].size()<comp[b].size()) {swap(a,b);} // adjacency list of component
    par[b] = a;
    for (int x : comp[b]) {comp[a].insert(x);}
    while (comp[a].size() && *comp[a].begin()<=y) {comp[a].erase(comp[a].begin());} // only stores cows > the current cow
}

int main() {
    int n, m; cin >> n >> m;
    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        if (a<b) {swap(a,b);}
        adj[--a].pb(--b); // what to transition from for cow a
        comp[b].insert(a); // only need to consider all cows with greater indices in adjacency list
    }
    iota(par,par+n,0);

    ll ans = -m;
    for (;y<n;y++) {
        for (int x : adj[y]) {join(x,y);} // join with all adjacent cows with lower indices
        ans += comp[get(y)].size(); // add number of nodes adjacent to component of i, with index > i
    }
    cout << ans << '\n';
}