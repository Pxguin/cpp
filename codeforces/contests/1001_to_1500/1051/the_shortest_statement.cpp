#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 1e5, l2d = 18;
v<pii> adj[MAX_N];
v<pii> euler;
pii st[l2d][2*MAX_N+1];

int tin[MAX_N];
ll depth[MAX_N] = {0};
bool vis[MAX_N] = {false};
v<ll> sp[MAX_N];
set<int> tot;

int n;

int log2(int i) {return __builtin_clz(1)-__builtin_clz(i);}

void dfs(int cur, int par, int d) {
    tin[cur] = euler.size(); euler.pb({d,cur});
    vis[cur] = true;
    for (pii x : adj[cur]) {
        if (x.f!=par) {
            if (vis[x.f]) { // if it's already visited then this edge does not belong to the spanning tree
                sp[x.f].resize(n);
                tot.insert(x.f);
            } else { // it is in the spanning tree
                depth[x.f] = depth[cur]+x.s;
                dfs(x.f,cur,d+1);
                euler.pb({d,cur});
            }
        }
    }
}

ll dist(int a, int b) { // distance between two nodes
    if (tin[a]>tin[b]) {swap(a,b);}
    int i = log2(tin[b]-tin[a]+1);
    int lca = min(st[i][tin[a]],st[i][tin[b]-(1<<i)+1]).s;
    return depth[a]+depth[b]-2*depth[lca];
}

void dijkstra(int cur) { // run dijkstra
    priority_queue<pii,v<pii>,greater<pii>> pq;
    F0R(i,n) {sp[cur][i] = LLONG_MAX;}
    pq.push({sp[cur][cur]=0,cur});
    while (pq.size()) {
        pii x = pq.top(); pq.pop();
        if (x.f!=sp[cur][x.s]) {continue;}
        for (pii nxt : adj[x.s]) {
            if (x.f+nxt.s<sp[cur][nxt.f]) {
                pq.push({sp[cur][nxt.f]=x.f+nxt.s,nxt.f});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int m; cin >> n >> m;
    F0R(i,m) {
        int a, b, w; cin >> a >> b >> w;
        adj[--a].pb({--b,w});
        adj[b].pb({a,w});
    }
    dfs(0,0,0);

    F0R(i,euler.size()) {st[0][i] = euler[i];}
    FOR(i,1,l2d) { // setup rmq sparse table for lca
        for (int j=0;j+(1<<i)<=euler.size();j++) {
            st[i][j] = min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
    for (int x : tot) {dijkstra(x);}
    
    int q; cin >> q;
    F0R(i,q) {
        int a, b; cin >> a >> b;
        a--; b--;
        ll ans = dist(a,b); // tree case

        for (int x : tot) {chmin(ans,sp[x][a]+sp[x][b]);} // non-tree case (go through all edges not part of tree)
        cout << ans << '\n';
    }
}