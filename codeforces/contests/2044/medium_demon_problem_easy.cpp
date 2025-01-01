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
    int ans = 0;
    
    auto dfs = [&](auto& dfs, int cur, int l)->void { // dfs to get length of paths
        vis[cur] = true;
        chmax(ans,l+2);
        for (int x : radj[cur]) {
            if (!vis[x]) {
                dfs(dfs,x,l+1);
            }
        }
    };

    F0R(i,n) {
        if (!vis[i]) { // floyd's algorithm to detect cycle
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

            for (int i : cyc) {dfs(dfs,i,0);} // dfs from all nodes in cycle
        }
    } cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}