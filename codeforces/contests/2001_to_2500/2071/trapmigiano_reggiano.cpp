#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vec vector

void solve() {
    int n, st, en; cin >> n >> st >> en;
    st--; en--;
    vec<vec<int>> adj(n);
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    vec<vec<int>> d(n);
    function<void(int,int,int)> dfs = [&](int cur, int par, int dep)->void {
        d[dep].pb(cur);
        for (int x : adj[cur]) {
            if (x!=par) {dfs(x,cur,dep+1);}
        }
    };
    dfs(en,-1,0);
    for (int i=n-1;i>=0;i--) {
        for (int x : d[i]) {cout << x+1 << ' ';}
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}