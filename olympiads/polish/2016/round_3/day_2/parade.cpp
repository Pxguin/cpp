#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

v<v<int>> adj;
int ans;

int dfs(int cur, int par) {
    int mx1 = 0, mx2 = 0, sz = adj[cur].size();
    for (int x : adj[cur]) {
        if (x!=par) {
            int res = dfs(x,cur)+sz-2; // total is sum of degrees minus 2*(path length-1)
            if (res>=mx1) {mx2 = mx1; mx1 = res;}
            else if (res>mx2) {mx2 = res;}
        }
    }
    chmax(ans,max(mx1,mx1+mx2-sz)); // one path & two path
    return max(mx1,sz); // start a new path
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    adj.clear(); adj.resize(n);
    F0R(i,n-1) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    ans = 0;
    dfs(0,0);
    cout << ans << '\n';
}