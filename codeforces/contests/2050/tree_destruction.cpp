#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

v<v<int>> adj;
int ans;

int dfs(int cur, int par) {
    int ret = (int)adj[cur].size(); // start new path
    int mx1 = ret, mx2 = 0;
    for (int x : adj[cur]) {
        if (x!=par) {
            int res = dfs(x,cur)+(int)adj[cur].size()-2; // extend old path
            if (res>=mx1) {mx2 = mx1; mx1 = res;}
            else if (res>mx2) {mx2 = res;}
        }
    }
    chmax(ans,max(mx1,mx1+mx2-((int)adj[cur].size()-2)-2)); // combine two paths
    return mx1;
}

void solve() {
    int n; cin >> n;
    adj.clear(); adj.resize(n);
    F0R(i,n-1) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    ans = 1;
    dfs(0,0);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}