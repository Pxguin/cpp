#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int n; cin >> n;
    v<int> a(n);
    F0R(i,n) {cin >> a[i]; a[i]--;}

    v<v<int>> adj(n);

    F0R(i,n-1) {
        int a1, b1; cin >> a1 >> b1;
        adj[--a1].pb(--b1); adj[b1].pb(a1);
    }
    v<bool> ans(n), ok(n,false);
    v<int> par(n);

    auto dfs = [&](auto& dfs, int cur, int p)->void {
        par[cur] = p;
        if (cur!=0 && (a[par[par[cur]]]==a[cur] || a[par[cur]]==a[cur])) { // check if parent or 2nd ancestor has same value
            ans[a[cur]] = true;
        }
        for (int x : adj[cur]) {
            if (x!=p) {
                dfs(dfs,x,cur);
            }
        }
        for (int x : adj[cur]) { // do two children have the same value
            if (x!=p) {
                if (ok[a[x]]) {ans[a[x]] = true;}
                ok[a[x]] = true;
            }
        }
        for (int x : adj[cur]) {
            ok[a[x]] = false;
        }
    };
    dfs(dfs,0,0);
    F0R(i,n) {cout << ans[i];}
    cout << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}