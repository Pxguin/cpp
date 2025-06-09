#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vec vector

const int MAX_N = 1e5;
vec<int> adj[MAX_N];
bool removed[MAX_N] = {false};
int sz[MAX_N];
vec<int> cent_adj[MAX_N];

int get_sizes(int cur, int par=-1) {
    sz[cur] = 1;    
    for (int x : adj[cur]) {
        if (x!=par && !removed[x]) {
            sz[cur] += get_sizes(x,cur);
        }
    } return sz[cur];
}
int get_cent(int cur, int n2, int par=-1) {
    for (int x : adj[cur]) {
        if (x!=par && !removed[x]) {
            if (sz[x]*2>n2) {return get_cent(x,n2,cur);}
        }
    } return cur;
}
int decomp(int cur=0) {
    int cent = get_cent(cur,get_sizes(cur));
    removed[cent] = true;
    for (int x : adj[cent]) {
        if (!removed[x]) {cent_adj[cent].pb(decomp(x));}
    } return cent;
}

int ans[MAX_N];
void dfs(int cur, int par=-1) {
    for (int x : cent_adj[cur]) {
        if (x!=par) {
            ans[x] = ans[cur]+1;
            dfs(x,cur);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    int rt = decomp();
    ans[rt] = 0;
    dfs(rt);

    for (int i=0;i<n;i++) {cout << (char)('A'+ans[i]) << ' ';}
}