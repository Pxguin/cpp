#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 100000, l2d = 17;
v<pii> adj[MAX_N];
v<pii> queries[MAX_N];
pair<pii,int> edges[MAX_N];
ll ans[MAX_N];
int on_stack[MAX_N];

ll lift[MAX_N][l2d], store[MAX_N][l2d]; // 2^k ancestor and min store dist up to that point

void dfs(int cur, int par, int d, ll len) {
    if (store[cur][0]==0) {store[cur][0] -= len;}

    on_stack[cur] = d;
    v<pii> nxt;
    for (pii x : queries[cur]) {
        int a = on_stack[edges[x.f].f.f], b = on_stack[edges[x.f].f.s];
        if (a && b) { // if both are ancestors, then we can't reach node E
            nxt.pb({d-min(a,b),x.s}); // we can't reach anything past the deeper ancestor (store earlier ancestor for bin lift purpose)
        } else {ans[x.s] = -2;} // escape
    }
    queries[cur] = nxt;
    for (pii x : adj[cur]) {
        if (x.f!=par) {
            lift[x.f][0] = cur; // update ancestor array
            dfs(x.f,cur,d+1,len+x.s);
            if (store[x.f][0]!=LLONG_MAX) { // calculate minimum store dist, minus length of path to root
                chmin(store[cur][0],store[x.f][0]+2*x.s);
            }
        }
    }
    on_stack[cur] = 0;
}

void dfs2(int cur, int par, ll len) {
    for (pii x : queries[cur]) {
        ll dist = LLONG_MAX, c = cur;
        F0R(b,l2d) { // lift up to the depth, store minimum store dist
            if (x.f&(1<<b)) {
                chmin(dist,store[c][b]);
                c = lift[c][b];
            }
        } if (dist!=LLONG_MAX) {ans[x.s] = dist+len;} // if a store exists
    }

    for (pii x : adj[cur]) {
        if (x.f!=par) {
            dfs2(x.f,cur,len+x.s);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, s, q, e; cin >> n >> s >> q >> e;
    F0R(i,n-1) {
        int a, b, w; cin >> a >> b >> w;
        adj[--a].pb({--b,w}); adj[b].pb({a,w});
        edges[i] = {{a,b},w};
    }
    memset(ans,-1,sizeof(ans));
    memset(lift,-1,sizeof(lift));
    F0R(i,n) {F0R(j,l2d) {store[i][j] = LLONG_MAX;}}
    F0R(i,s) {
        int a; cin >> a;
        store[--a][0] = 0; // base cases (note that all values are shifted up by 1 node)
    }
    F0R(i,q) {
        int a, b; cin >> a >> b;
        queries[--b].pb({--a,i});
    }
    dfs(--e,-1,1,0);

    FOR(p,1,l2d) { // update lift arrays
        F0R(i,n) {
            if (lift[i][p-1]!=-1) {
                lift[i][p] = lift[lift[i][p-1]][p-1];
                store[i][p] = min(store[i][p-1],store[lift[i][p-1]][p-1]);
            }
        }
    }
    dfs2(e,-1,0);
    F0R(i,q) {
        if (ans[i]==-1) {cout << "oo";}
        else if (ans[i]==-2) {cout << "escaped";}
        else {cout << ans[i];}
        cout << '\n';
    }
}