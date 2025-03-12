#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vec vector

void solve() {
    int n; cin >> n;
    vec<vec<int>> adj(n);
    for (int i=1;i<n;i++) {
        int x; cin >> x;
        adj[--x].pb(i);
    }
    vec<bool> col(n);
    for (int i=0;i<n;i++) {
        char c; cin >> c;
        col[i] = (c=='W');
    }
    vec<vec<int>> cnt(n,vec<int>(2,0));
    int ans = 0;

    function<void(int)> dfs = [&](int cur) {
        cnt[cur][col[cur]]++; // update counter with this vertex's color
        for (int x : adj[cur]) {
            dfs(x);
            cnt[cur][0] += cnt[x][0]; // count # black vertices
            cnt[cur][1] += cnt[x][1]; // count # white vertices
        }
        ans += (cnt[cur][0]==cnt[cur][1]); // if black=white
    };
    dfs(0);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}