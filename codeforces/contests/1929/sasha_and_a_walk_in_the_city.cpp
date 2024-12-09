#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int n;
v<v<int>> adj;
v<ll> dp, dp2;
ll mod = 998244353;
void dfs(int cur, int par) {
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs(x,cur);
            dp[cur] = (dp[cur]*dp[x])%mod; // no ancestor
            dp2[cur] = (dp2[cur]+dp[x]-1)%mod; // yes ancestor
        }
    } dp[cur] = (dp[cur]+1)%mod;
}

void solve() {
    cin >> n;
    adj.clear(); adj.resize(n);
    dp.assign(n,1); dp2.assign(n,0);
    F0R(i,n-1) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs(0,0);
    F0R(i,n) {dp[0] = (dp[0]+dp2[i])%mod;} // ans is the sum of dp values
    cout << dp[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}