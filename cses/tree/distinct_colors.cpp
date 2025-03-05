#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 2e5;
set<int> colors[MAX_N];
v<int> adj[MAX_N];
int ans[MAX_N];

void dfs(int cur, int par) {
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs(x,cur);
            if (colors[x].size()>colors[cur].size()) {colors[cur].swap(colors[x]);} // merging
            for (int c : colors[x]) {colors[cur].insert(c);}
        }
    } ans[cur] = colors[cur].size(); // colors[cur] stores the set of all colors in the subtree of cur
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    F0R(i,n) {
        int c; cin >> c;
        colors[i].insert(c); // initialize sets
    }
    F0R(i,n-1) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs(0,0);
    F0R(i,n) {cout << ans[i] << ' ';}
}