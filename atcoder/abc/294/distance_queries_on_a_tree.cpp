#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 2e5+2, l2d = 18;
ll bit[MAX_N] = {0};
void add(int i, ll a) {
    for (;i<MAX_N;i+=i&-i) {bit[i] += a;}
}
ll get(int i) {
    ll res = 0;
    for (;i;i-=i&-i) {res += bit[i];}
    return res;
}

int tin[MAX_N], tout[MAX_N], depth[MAX_N];
int timer = 1;
v<pii> adj[MAX_N];

int lift[l2d][MAX_N];

void dfs(int cur, int par, int d) {
    lift[0][cur] = par; depth[cur] = d;
    tin[cur] = timer++;
    for (pii x : adj[cur]) {
        if (x.f!=par) {
            dfs(x.f,cur,d+1);
            add(tin[x.f],x.s); // add weight of the edge to all nodes in the deeper node's subtree
            add(tout[x.f],-x.s);
        }
    }

    tout[cur] = timer;
}

int jump(int a, int d) {
    for (int i=0;i<l2d;i++) {
        if ((1<<i)&d) {a = lift[i][a];}
    } return a;
}

int lca(int a, int b) {
    if (depth[a]<depth[b]) {swap(a,b);}
    a = jump(a,depth[a]-depth[b]);
    if (a==b) {return a;}

    for (int i=l2d-1;i>=0;i--) {
        if (lift[i][a]!=lift[i][b]) {
            a = lift[i][a];
            b = lift[i][b];
        }
    } return lift[0][a];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    memset(lift,-1,sizeof(lift));
    int n; cin >> n;
    v<pair<pii,int>> e(n-1); // edges
    F0R(i,n-1) {
        cin >> e[i].f.f >> e[i].f.s >> e[i].s;
        adj[--e[i].f.f].pb({--e[i].f.s,e[i].s});
        adj[e[i].f.s].pb({e[i].f.f,e[i].s});
    }
    dfs(0,-1,0);
    F0R(i,n-1) { // useless calc
        if (depth[e[i].f.f]<depth[e[i].f.s]) {swap(e[i].f.f,e[i].f.s);}
    }
    FOR(b,1,l2d) {
        F0R(i,n) {
            if (lift[b-1][i]!=-1) {lift[b][i] = lift[b-1][lift[b-1][i]];}
        }
    }
    
    int q; cin >> q;
    while (q--) {
        int t, a, b; cin >> t >> a >> b;
        if (t==1) {
            a--;
            add(tin[e[a].f.f],b-e[a].s); // update subtrees
            add(tout[e[a].f.f],-(b-e[a].s));
            e[a].s = b;
        } else {
            a--; b--; // distance between a and b
            cout << get(tin[a])+get(tin[b])-2*get(tin[lca(a,b)]) << '\n';
        }
    }
}