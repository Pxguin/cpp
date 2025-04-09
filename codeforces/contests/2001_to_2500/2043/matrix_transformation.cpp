#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define vec vector

void solve() {
    int n, m; cin >> n >> m;
    vec<vec<int>> adj(30*n+30*m);
    vec<bool> vis(30*n+30*m);
    vec<vec<int>> a(n,vec<int>(m)), b(n,vec<int>(m));
    F0R(i,n) {F0R(j,m) {cin >> a[i][j];}}
    F0R(i,n) {F0R(j,m) {cin >> b[i][j];}}
    queue<int> src;
    F0R(i,n) {
        F0R(j,m) {
            F0R(bit,30) {
                if (a[i][j]&(1<<bit)) {
                    if (b[i][j]&(1<<bit)) {
                        adj[bit+30*i].pb(30*n+bit+30*j); // row -> col
                    } else {
                        adj[30*n+bit+30*j].pb(bit+30*i); // col -> row
                        src.push(bit+30*i); // must visit the row node
                    }
                } else {
                    if (b[i][j]&(1<<bit)) {
                        adj[bit+30*i].pb(30*n+bit+30*j); // row -> col
                        src.push(30*n+bit+30*j); // must visit the col node
                    } else {
                        adj[30*n+bit+30*j].pb(bit+30*i); // col -> row
                    }
                }
            }
        }
    }

    vec<int> toposort, ord(30*(n+m),-1);
    function<void(int)> dfs = [&](int cur) {
        vis[cur] = true;
        for (int x : adj[cur]) {
            if (!vis[x]) {dfs(x);}
        } toposort.pb(cur);
    };
    while (src.size()) { // union of connected component of all mandatory nodes
        int cur = src.front(); src.pop();
        if (!vis[cur]) {dfs(cur);}
    }
    bool ans = true;
    reverse(all(toposort)); // if a toposort exists, then answer is yes
    F0R(i,toposort.size()) {ord[toposort[i]] = i;}
    F0R(i,30*(n+m)) {
        for (int j : adj[i]) {
            if (ord[i]!=-1 && ord[j]!=-1 && ord[i]>ord[j]) {ans = false;}
        }
    }
    cout << (ans ? "Yes" : "No") << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}