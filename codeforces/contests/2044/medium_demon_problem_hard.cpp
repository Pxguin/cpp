#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int n; cin >> n;
    v<int> to(n);
    F0R(i,n) {cin >> to[i]; to[i]--;}

    v<v<int>> radj(n);
    F0R(i,n) {radj[to[i]].pb(i);}

    v<bool> vis(n,false);
    int ans = 2; // by default
    v<int> sz;
    
    auto dfs = [&](auto& dfs, int cur)->void {
        vis[cur] = true;
        sz.back()++;
        for (int x : radj[cur]) {
            if (!vis[x]) {
                dfs(dfs,x);
            }
        }
    };

    F0R(i,n) {
        if (!vis[i]) {
            int p1 = to[i], p2 = to[to[i]];
            while (p1!=p2) {
                p1 = to[p1]; p2 = to[to[p2]];
            }
            v<int> cyc;
            do {
                cyc.pb(p2);
                vis[p2] = true;
                p2 = to[p2];
            } while (p1!=p2);

            sz.clear();
            for (int k : cyc) {
                for (int j : radj[k]) { // find sizes of all nodes pointing towards this node (sinks)
                    if (vis[j]) {continue;}
                    sz.pb(0); dfs(dfs,j);
                }
            }
            for (int k : sz) {chmax(ans,k+2);} // ans is max size of a sink
        }
    } cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}