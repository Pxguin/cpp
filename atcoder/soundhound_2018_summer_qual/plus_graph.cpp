#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector

const int MAX_N = 1e5;
vec<pii> adj[MAX_N];
ll val[MAX_N] = {0};
int vis[MAX_N] = {0};
ll start = -1, add = -1, ans = 1;
bool ok = true;

void dfs(int cur, bool c) {
    vis[cur] = c+1; // bipartite coloring
    for (auto[x,w] : adj[cur]) {
        if (!vis[x]) {
            val[x] = w-val[cur]; // set values greedily
            dfs(x,!c);
        } else {
            if (vis[cur]==vis[x]) { // ok odd length cycle found
                start = cur;
                add = (w-val[cur]-val[x])/2;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    F0R(i,m) {
        int a, b, c; cin >> a >> b >> c;
        adj[--a].pb({--b,c});
        adj[b].pb({a,c});
    }
    val[0] = 1;
    dfs(0,0);
    if (start!=-1) {
        F0R(i,n) {
            val[i] += (vis[i]==vis[start] ? 1 : -1)*add; // odd length cycle: 1 possibility
            if (val[i]<1) {ok = false;} // make sure all values are nonnegative
        }
    } else {
        ll diff = LLONG_MAX, same = 1;
        F0R(i,n) { // even length cycle: a range of possibilities
            if (vis[i]!=vis[0]) {chmin(diff,val[i]);}
            else {chmin(same,val[i]);}
        }
        ans = max(0LL,diff-(1-same));
    }

    F0R(i,n) {
        for (auto[x,w] : adj[i]) { // additional check
            if (val[x]+val[i]!=w) {ok = false;}
        }
    }

    if (!ok) {cout << 0 << '\n';}
    else {cout << ans << '\n';}
}