#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define vec vector

const int MAX_N = 1e5, l2d = 18;
int st[l2d][MAX_N];
vec<int> adj[MAX_N];
int dep[MAX_N], sz[MAX_N];

void dfs(int cur) {
    sz[cur] = 1;
    
    for (int x : adj[cur]) {
        adj[x].erase(find(all(adj[x]),cur));
        st[0][x] = cur;
        dep[x] = dep[cur]+1;
        dfs(x);

        sz[cur] += sz[x];
    }
}

int lift(int a, int d) {
    F0R(i,l2d) {
        if ((1<<i)&d) {a = st[i][a];}
    } return a;
}

int lca(int a, int b) {
    if (dep[a]<dep[b]) {swap(a,b);}
    a = lift(a,dep[a]-dep[b]);
    if (a==b) {return a;}
    for (int i=l2d-1;i>=0;i--) {
        if (st[i][a]!=st[i][b]) {
            a = st[i][a];
            b = st[i][b];
        }
    }
    assert(st[0][a]==st[0][b]);
    return st[0][a];
}

bool on_path(int a, int b, int c) { // is c on the path between a and b
    if (lca(a,b)==a) { // b is desc, a is anc
        return (lca(b,c)==c && lca(a,c)==a);
    } else { // c is a descendant of lca(a,b), and either a/b is a descendant of c
        return (lca(c,lca(a,b))==lca(a,b) && (lca(a,c)==c || lca(b,c)==c));
    }
}

int dist(int a, int b) {
    return dep[a]+dep[b]-2*dep[lca(a,b)];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    memset(st,-1,sizeof(st));
    int n, q; cin >> n >> q;
    F0R(i,n-1) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dep[0] = 0;
    dfs(0);
    FOR(b,1,l2d) {
        F0R(i,n) {
            if (st[b-1][i]!=-1) {st[b][i] = st[b-1][st[b-1][i]];}
        }
    }

    while (q--) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--; c--;
        if (dep[a]>dep[b]) {swap(a,b);}
        if (!on_path(a,b,c)) {cout << 0 << '\n';} // if not on path then return 0
        else {
            int ans = (lca(a,b)==c ? n : sz[c]); // if c is lca, then pool of possible nodes is n; otherwise, sz[c]
            if (lca(b,c)==c) { // if b is descendant of c, then subtract all nodes leading to b from c
                ans -= sz[lift(b,dep[b]-dep[c]-1)];
            }
            if (lca(a,c)==c) { // same thing for a
                ans -= sz[lift(a,dep[a]-dep[c]-1)];
            }
            cout << ans << '\n';
        }
    }
}