#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define vec vector

const int MAX_N = 6e5+5, l2d = 20;
vec<pii> adj[MAX_N];
ll other[MAX_N], dist[l2d][MAX_N][2];
int anc[l2d][MAX_N], to[MAX_N], dep[MAX_N] = {0}; // anc: bin lift; to: index of complement
int n;

void dfs(int cur, int par) {
    anc[0][cur] = par;
    for (int i=1;i<l2d;i++) {
        if (anc[i-1][cur]!=-1) {anc[i][cur] = anc[i-1][anc[i-1][cur]];}
    }
    for (int i=0;i<adj[cur].size();i++) {
        auto[x,w] = adj[cur][i];
        if (x!=par) {
            dist[0][x][cur&1] = min(w,other[x]+adj[to[cur]][i].s+other[cur]); // to same parity tree
            dist[0][x][!(cur&1)] = min(other[cur]+w,other[x]+adj[to[cur]][i].s); // to other parity tree
            dep[x] = dep[cur]+1;
            dfs(x,cur);
        }
    }
}

int lift(int a, int d) {
    for (int i=0;i<l2d;i++) {
        if ((1<<i)&d) {a = anc[i][a];}
    } return a;
}

int lca(int a, int b) {
    if ((b&1) != (a&1)) {b = to[b];} // make them in same tree
    a = lift(a,dep[a]-dep[b]);
    if (a==b) {return a;}
    for (int i=l2d-1;i>=0;i--) {
        if (anc[i][a]!=anc[i][b]) {
            a = anc[i][a]; b = anc[i][b];
        }
    }
    assert(anc[0][a]==anc[0][b]);
    return anc[0][a]; // find lca
}

ll dist2(int a, int b1) {
    int b = b1;
    if ((b&1) != (a&1)) {b = to[b];}
    ll d[2] = {0,0};
    d[!(a&1)] = other[a];

    for (int i=0;i<l2d;i++) {
        if ((1<<i)&(dep[a]-dep[b1])) {
            ll d2[2];
            d2[a&1] = min(d[!(a&1)]+dist[i][to[a]][a&1],d[a&1]+dist[i][a][a&1]);
            d2[!(a&1)] = min(d[a&1]+dist[i][a][!(a&1)],d[!(a&1)]+dist[i][to[a]][!(a&1)]);
            d[0] = d2[0]; d[1] = d2[1];
            a = anc[i][a];
        }
    } return d[b1&1];
}

vec<pii> adj2[MAX_N/2+1];
void sp() { // sp between 2i and 2i+1
    ll sp2[MAX_N/2+1]; fill(sp2,sp2+MAX_N/2+1,LLONG_MAX);
    priority_queue<pii,vec<pii>,greater<pii>> pq;
    pq.push({sp2[n]=0,n});
    while (pq.size()) {
        auto[d,x] = pq.top(); pq.pop();
        if (d!=sp2[x]) {continue;}
        for (auto[x2,w] : adj2[x]) {
            if (w+d<sp2[x2]) {pq.push({sp2[x2]=w+d,x2});}
        }
        other[2*x] = other[2*x+1] = d;
    }
}

int main() {
    memset(anc,-1,sizeof(anc));

    cin >> n;
    for (int i=0;i<n;i++) {
        ll o; cin >> o;
        adj2[n].pb({i,o});

        to[2*i] = 2*i+1;
        to[2*i+1] = 2*i;
    }
    for (int i=0;i<n-1;i++) {
        ll x, y, w1, w2; cin >> x >> y >> w1 >> w2;
        x--; y--;
        adj[2*x].pb({2*y,w1}); adj[2*y].pb({2*x,w1});
        adj[2*x+1].pb({2*y+1,w2}); adj[2*y+1].pb({2*x+1,w2});

        adj2[x].pb({y,w1+w2}); adj2[y].pb({x,w1+w2});
    }
    sp();
    dfs(0,-1);dfs(1,-1);
    for (int b=1;b<l2d;b++) {
        for (int i=0;i<2*n;i++) {
            if (anc[b][i]==-1) {continue;}
            dist[b][i][i&1] = min(dist[b-1][i][i&1]+dist[b-1][anc[b-1][i]][i&1], // continue through same tree
                                dist[b-1][i][!(i&1)]+dist[b-1][to[anc[b-1][i]]][i&1]); // alternate trees twice
            dist[b][i][!(i&1)] = min(dist[b-1][i][i&1]+dist[b-1][anc[b-1][i]][!(i&1)], // alternate trees on second
                                dist[b-1][i][!(i&1)]+dist[b-1][to[anc[b-1][i]]][!(i&1)]); // alternate trees on first
        }
    }

    int q; cin >> q;
    while (q--) {
        int a, b, c; cin >> a >> b;
        if (dep[--a]<dep[--b]) {swap(a,b);}
        c = lca(a,b);
        cout << min(dist2(a,c)+dist2(b,c),dist2(a,to[c])+dist2(b,to[c])) << '\n';
    }
}