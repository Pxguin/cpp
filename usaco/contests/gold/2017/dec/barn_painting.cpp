#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vec vector

const int mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("barnpainting.in","r",stdin);
    freopen("barnpainting.out","w",stdout);

    int n, k; cin >> n >> k;
    vec<vec<int>> adj(n);
    vec<int> col(n,-1);
    vec<vec<int>> dp(n,vec<int>(3,0));
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b); adj[b].pb(a);
    }
    for (int i=0;i<k;i++) {
        int b, c; cin >> b >> c;
        col[--b] = --c;
    }
    function<void(int,int)> dfs = [&](int cur, int par)->void {
        if (col[cur]==-1) {dp[cur][0] = dp[cur][1] = dp[cur][2] = 1;}
        else {dp[cur][col[cur]] = 1;}

        for (int x : adj[cur]) {
            if (x!=par) {
                dfs(x,cur);
                ll sum = ((dp[x][0]+dp[x][1])%mod+dp[x][2])%mod;
                for (int i=0;i<3;i++) {
                    ll c = (sum-dp[x][i]%mod+mod)%mod;
                    dp[cur][i] = (dp[cur][i]*c)%mod;
                }
            }
        }
    };
    dfs(0,-1);
    cout << ((dp[0][0]+dp[0][1]%mod)+dp[0][2])%mod;
}