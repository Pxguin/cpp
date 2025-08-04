#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define vec vector

const int N = 2e5;
vec<int> adj[N];

int ans = 0, d;
pii dp[N];

void dfs(int cur, int par=-1) {
    vec<pii> dist;
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs(x,cur);
            dist.pb({dp[x].f+1,dp[x].s});
        }
    }
    sort(all(dist),greater<>());

    dp[cur] = {d,cur};

    for (pii x : dist) {
        if (x.f+dp[cur].f<d) {
            ans--;
            dp[x.s].f = -1;
        } else {
            dp[cur] = x;
        }
    }
    if (dp[cur].f==d) {
        ans++;
        dp[cur] = {0,cur};
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n >> d;
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b); adj[b].pb(a);
    }
    dfs(0);
    cout << ans << '\n';
    for (int i=0;i<n;i++) {
        if (dp[i].f==0) {cout << i+1 << ' ';}
    }
}