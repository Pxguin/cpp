#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vec vector

const int MAX_N = 2e5;
vec<int> adj[MAX_N];
int sz[MAX_N];
int n;

void dfs1(int cur, int par=-1) {
    sz[cur] = 1;
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs1(x,cur);
            sz[cur] += sz[x];
        }
    }
}
int dfs2(int cur, int par=-1) {
    for (int x : adj[cur]) {
        if (x!=par) {
            if (sz[x]>n/2) {return dfs2(x,cur);}
        }
    } return cur;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> n;
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b); adj[b].pb(a);
    }
    dfs1(0);
    cout << dfs2(0)+1 << '\n';
}