#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define chmin(a, b) a = min(a,b)
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("dirtraverse.in","r",stdin);
    freopen("dirtraverse.out","w",stdout);

    int n; cin >> n;
    vec<vec<int>> adj(n);
    vec<int> len(n);
    vec<bool> file(n,false);

    for (int i=0;i<n;i++) {
        string s; cin >> s;
        len[i] = s.size();
        int m; cin >> m;
        if (m!=0) {len[i]++;}
        else {file[i] = true;}
        while (m--) {
            int a; cin >> a;
            adj[i].pb(--a);
        }
    }
    ll ans = LLONG_MAX;
    vec<ll> dp1(n,0), leaf1(n,0), dp2(n,0);
    function<void(int,int)> dfs = [&](int cur, int par)->void {
        leaf1[cur] = file[cur];
        for (int x : adj[cur]) {
            if (x!=par) {
                dfs(x,cur);
                leaf1[cur] += leaf1[x];
                dp1[cur] += dp1[x]+leaf1[x]*len[x];
            }
        }
    };
    function<void(int,int)> dfs2 = [&](int cur, int par)->void {
        if (!file[cur]) {chmin(ans,dp1[cur]+dp2[cur]);}
        for (int x : adj[cur]) {
            ll leaf2 = leaf1[0]-leaf1[x];
            ll push = dp1[x]+leaf1[x]*len[x];
            dp2[x] = (dp2[cur]+dp1[cur]-push)+3*leaf2;
            dfs2(x,cur);
        }
    };
    dfs(0,-1); dfs2(0,-1);
    cout << ans << '\n';
}