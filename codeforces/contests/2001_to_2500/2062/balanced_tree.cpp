#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define chmax(a, b) a = max(a,b)
#define vec vector

const int MAX_N = 2e5;
int l[MAX_N], r[MAX_N], a[MAX_N];
vec<int> adj[MAX_N];

ll ans = 0;
void dfs(int cur, int par) {
    a[cur] = 0;
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs(x,cur);
            chmax(a[cur],a[x]);
        }
    }
    a[cur] = min(r[cur],max(l[cur],a[cur])); // get optimal value for a
    for (int x : adj[cur]) {
        if (x!=par) {
            ans += max(0,a[x]-a[cur]); // get amount of times the root is added to
        }
    }
}

void solve() {
    int n; cin >> n;
    for (int i=0;i<n;i++) {adj[i].clear();}
    for (int i=0;i<n;i++) {cin >> l[i] >> r[i];}
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    ans = 0;
    dfs(0,0);
    cout << ans+a[0] << '\n'; // final value of the root
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}