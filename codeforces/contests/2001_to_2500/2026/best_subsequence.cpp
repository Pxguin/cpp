#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector

void solve() {
    int n; cin >> n;
    vec<ll> a(n);
    vec<vec<int>> adj(n+60);
    F0R(i,n) {
        cin >> a[i];
        F0R(j,60) {
            if ((1LL<<j)&a[i]) {adj[i].pb(n+j); adj[n+j].pb(i);} // bipartite graph between array and bits
        }
    }
    vec<bool> vis;
    vec<int> to(n+60,-1);
    function<bool(int)> dfs = [&](int cur) {
        if (vis[cur]) {return false;}
        vis[cur] = true;
        for (int x : adj[cur]) {
            if (to[x]==-1 || dfs(to[x])) { // shift augmenting path
                to[x] = cur;
                return true;
            }
        }
        return false;
    };

    F0R(i,n+60) { // kuhn's
        vis.assign(n+60,false);
        dfs(i);
    }

    int ans = n;
    F0R(i,n) { // find max matching
        if (to[i]!=-1) {ans--;}
    } cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}