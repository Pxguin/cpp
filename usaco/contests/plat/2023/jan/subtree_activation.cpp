#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vec<vec<int>> adj(n);
    vec<vec<ll>> dp(n,vec<ll>(2,LLONG_MAX));
    for (int i=0;i<n-1;i++) {
        int p; cin >> p;
        adj[--p].pb(i+1);
    }

    function<int(int)> dfs = [&](int cur)->int {
        ll sz = 1, mx_sz = 0;
        dp[cur][1] = 0;

        ll mx[2] = {0,0};
        for (int x : adj[cur]) {
            ll sz_x = dfs(x);
            sz += sz_x;
            mx_sz = max(mx_sz,sz_x); // max subtree size
            dp[cur][1] += dp[x][1]; // dp[i][1]: everything in the subtree of i is satisfied

            ll d = dp[x][1]-dp[x][0];
            if (d>=mx[0]) {mx[1] = mx[0]; mx[0] = d;} // maximum two values of dp[x][1]-dp[x][0]
            else if (d>mx[1]) {mx[1] = d;}
        }
        dp[cur][0] = dp[cur][1]-mx[0]; // dp[i][0]: all the unsatisfied nodes in subtree of i form a path
        dp[cur][1] += sz*2-max(mx_sz*2,mx[0]+mx[1]); // end a path at here and satisfy this node, so cost sz*2
        // subtract either mx[0]+mx[1] (join two paths from children subtrees at this node), or extend an existing path (cost 2*(sz[cur]-sz[child]))
        return sz;
    };
    dfs(0);
    cout << dp[0][1] << '\n';
}