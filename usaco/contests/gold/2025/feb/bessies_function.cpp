#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<v<int>> radj(n);
    v<int> a(n), c(n);
    F0R(i,n) {
        cin >> a[i]; a[i]--;
        radj[a[i]].pb(i);
    }
    F0R(i,n) {cin >> c[i];}
    v<bool> vis(n,false), vis2(n,false);
    v<pair<ll,ll>> dp(n);

    auto dfs = [&](auto& dfs, int cur, v<bool>& done)->void {
        dp[cur] = {0,c[cur]};
        done[cur] = true;
        for (int x : radj[cur]) {
            if (!done[x]) {
                dfs(dfs,x,done);
                dp[cur].f += dp[x].s; // first transition: this node is not in a self loop
                dp[cur].s += min(dp[x].f,dp[x].s); // second transition: in a self loop
            }
        }
    };

    ll ans = 0;
    F0R(i,n) {
        if (!vis[i]) {
            int p1 = a[i], p2 = a[a[i]];
            while (p1!=p2) {
                p1 = a[p1]; p2 = a[a[p2]];
            }

            vis[p1] = true; // try discarding an arbitrary edge in the cycle
            dfs(dfs,p1,vis);
            if (a[p1]==p1) {dp[p1].s -= c[p1];}
            ll add = dp[p1].s;

            vis2[a[p1]] = true; // in case that edge was necessary, try discard an adjacent edge to it as well
            dfs(dfs,a[p1],vis2);
            if (a[p1]==p1) {dp[p1].s -= c[p1];}
            chmin(add,dp[a[p1]].s);

            ans += add;
        }
    } cout << ans << '\n';
}