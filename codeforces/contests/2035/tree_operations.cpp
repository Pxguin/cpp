#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int n, x;
const int MAX_N = 2000;
const ll MAX_A = 1e9;
ll a[MAX_N], cnt[MAX_N];
v<int> adj[MAX_N];

void dfs(int cur, int par, ll m, int b) {
    cnt[cur] = m+(cur<b);

    for (int nxt : adj[cur]) {
        if (nxt!=par) {
            dfs(nxt,cur,m,b);

            if (cnt[nxt]<a[nxt]) { // make sure that cnt[i]>=a[i]
                cnt[cur] -= a[nxt]-cnt[nxt];
                cnt[nxt] = a[nxt];
            }
            if ((cnt[nxt]-a[nxt])&1) { // and that the # of extra operations (cnt[i]-a[i]) is even
                cnt[nxt]++; cnt[cur]--;
            }
        }
    }
}

void solve() {
    cin >> n >> x;
    x--;
    ll sum = 0;

    F0R(i,n) {cin >> a[i]; sum += a[i];}

    F0R(i,n) {adj[i].clear();}
    F0R(i,n-1) {
        int u1, v1; cin >> u1 >> v1;
        adj[--u1].pb(--v1);
        adj[v1].pb(u1);
    }
    ll ans = LLONG_MAX;
    for (int buf=2*n-1;buf>=0;buf--) {
        if ((buf&1) != (sum&1)) {continue;} // only check same parity as sum
        ll l = 0, h = MAX_A, m = (l+h)/2;
        while (l <= h) {
            dfs(x,-1,(2LL*n*m+buf)/n,buf%n); // 2n*m+buf = number of operations

            if (cnt[x]>=a[x] && ((cnt[x]-a[x])&1)==0) { // if the root is ok
                ans = min(ans,2LL*n*m+buf);
                h = m-1;
            } else {l = m+1;}
            m = (l+h)/2;
        }
    }
    cout << (ans==LLONG_MAX ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}