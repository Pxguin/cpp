#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

void solve() {
    int n, m; cin >> n >> m;
    v<v<int>> adj(n), colors(n+1);
    v<int> c(n), s(n), f(n);

    F0R(i,n) {cin >> c[i];}
    F0R(i,n) {colors[c[i]].pb(i);}
    F0R(i,n) {cin >> s[i];}
    F0R(i,n) {cin >> f[i];}

    F0R(i,m) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b); adj[b].pb(a);
    }

    v<bool> no(n,false);

    auto bfs = [&](v<int>& op, int state) {
        queue<int> todo;
        v<bool> vis(n,false), col(n,false); // col: which color stalls can we visit?
        todo.push(0);
        while (todo.size()) { // get all keys/place all keys?
            int cur = todo.front(); todo.pop();
            if (vis[cur]) {continue;}

            col[op[cur]] = true; vis[cur] = true;
            for (int x : colors[op[cur]]) { // are any unvisited nodes of this color adjacent to the component?
                if (vis[x] || no[x]) {continue;} // pretty much just backtracking
                for (int a : adj[x]) {
                    if (vis[a]) {todo.push(x); break;}
                }
            }
            for (int x : adj[cur]) {
                if (!state) { // for getting keys
                    if (!vis[x] && col[c[x]]) {todo.push(x);}
                } else { // for placing keys
                    if (!vis[x] && !no[x] && (col[c[x]] || c[x]==f[x])) {todo.push(x);}
                }
            }
        }
        F0R(i,n) {
            if (!vis[i]) {
                no[i] = true; // this is to mark which nodes are unreachable
                vis[i] = (s[i]==f[i]);
            }
        }
        return (count(all(vis),true)==n); // we can get/place all keys if all nodes are ok
    };
    cout << (bfs(s,0)&&bfs(f,1) ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}