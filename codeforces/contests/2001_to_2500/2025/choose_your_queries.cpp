#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define vec vector

const int MAX_N = 3e5;
vec<pii> adj[MAX_N];
pii qr[MAX_N];
int deg[MAX_N] = {0}, vis[MAX_N] = {0};
bool ans[MAX_N], state[MAX_N] = {false};

void dfs(int cur) {
    for (auto[x,i] : adj[cur]) {
        if (!vis[x]) {
            vis[x] = vis[cur]+1;
            dfs(x);
            if (deg[x]) { // to child
                deg[x] = 0; 
                ans[i] = (qr[i].f==x);
            } else { // to par
                deg[cur] ^= 1;
                ans[i] = (qr[i].f==cur);
            }
        } else if (vis[cur]<vis[x]) { // not in spanning tree
            deg[cur] ^= 1;
            ans[i] = (qr[i].f==cur); // true: x; false: y
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q; cin >> n >> q;
    for (int i=0;i<q;i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].pb({b,i}); adj[b].pb({a,i});
        qr[i] = {a,b};
    }
    for (int i=0;i<n;i++) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(i);
        }
    }
    for (int i=0;i<q;i++) {
        int x = (ans[i] ? qr[i].f : qr[i].s);
        cout << (ans[i] ? 'x' : 'y'); // which direction
        cout << (state[x] ? '-' : '+') << '\n'; // derive if it's + or -
        state[x] ^= 1;
    }
}