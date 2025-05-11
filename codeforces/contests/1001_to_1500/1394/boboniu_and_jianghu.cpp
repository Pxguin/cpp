#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define chmin(a, b) a = min(a,b)
#define all(x) x.begin(),x.end()
#define vec vector

const int MAX_N = 2e5;
vec<int> adj[MAX_N];
int t[MAX_N], h[MAX_N];

ll dp[MAX_N][2];

void dfs(int cur) {
    dp[cur][0] = dp[cur][1] = LLONG_MAX;
    vec<ll> both;
    ll tot = 0, inc = 0, dec = 0;

    for (int x : adj[cur]) {
        adj[x].erase(find(all(adj[x]),cur));

        dfs(x);
        if (h[cur]>h[x]) {tot += dp[x][0]; inc++;} // if it is strictly increasing
        else {
            tot += dp[x][1]; dec++; // default ones that can be either inc/dec to decreasing
            if (h[cur]==h[x]) {
                both.pb(dp[x][1]-dp[x][0]);
            }
        }
    }
    sort(all(both),greater<>());
    auto cmp = [&]() { // update dp values
        ll mn = min(inc,dec); // pair up as many inc and dec together
        ll t2 = (inc+dec-mn)*t[cur]+tot;
        chmin(dp[cur][0],t2+((inc-mn)||(cur==0) ? 0 : t[cur])); // propagate an inc sequence to the parent
        chmin(dp[cur][1],t2+((dec-mn)||(cur==0) ? 0 : t[cur])); // propagate a dec sequence upwards
    };
    cmp();
    for (ll x : both) { // fix amount of inc subsequences
        tot -= x;
        inc++; dec--;
        cmp(); // update dp
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    for (int i=0;i<n;i++) {cin >> t[i];}
    for (int i=0;i<n;i++) {cin >> h[i];}
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs(0);

    cout << min(dp[0][0],dp[0][1]) << '\n';
}