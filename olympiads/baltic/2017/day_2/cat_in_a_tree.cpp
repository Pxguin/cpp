#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) x.begin(),x.end()
#define vec vector

const int N = 2e5;
int ans = 0;
int dp[N];
vec<int> adj[N];
int d;

void dfs(int cur=0) {
    vec<int> dist;
    for (int x : adj[cur]) {
        dfs(x);
        dist.pb(++dp[x]);
    }
    sort(all(dist),greater<>());
    dp[cur] = d;
    for (int x : dist) {
        if (x+dp[cur]<d) {
            ans--;
        } else {
            dp[cur] = x;
        }
    }
    if (dp[cur]==d) {
        ans++;
        dp[cur] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n >> d;
    for (int i=0;i<n-1;i++) {
        int p; cin >> p;
        adj[p].pb(i+1);
    }
    dfs();
    cout << ans << '\n';
}