#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int n, k;
v<v<int>> adj;
v<bool> m;
ll ans = 0;

int dfs(int cur, int par) {
    int cnt = m[cur];
    for (int x : adj[cur]) {
        if (x!=par) {cnt += dfs(x,cur);}
    }

    ans += min(2*k-cnt,cnt);
    return cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;
    adj.resize(n); m.assign(n,false);
    F0R(i,2*k) {
        int x; cin >> x;
        m[--x] = true;
    }
    F0R(i,n-1) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs(0,0);
    cout << ans << '\n';
}