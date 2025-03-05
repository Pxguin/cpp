#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) x.begin(),x.end()
#define v vector

const int MAX_N = 1e5, l2d = 17;

int tin[MAX_N], depth[MAX_N], t[MAX_N], a[MAX_N], b[MAX_N], c[MAX_N];
v<int> adj[MAX_N], add[MAX_N], sub[MAX_N], q[MAX_N];
map<pair<int,int>,int> save;
int timer = 0;

int lift[l2d][MAX_N];

void dfs(int cur, int par, int d) { // set up lca and euler tour
    lift[0][cur] = par;
    depth[cur] = d;
    tin[cur] = timer++;
    for (int x : adj[cur]) {
        if (x!=par) {dfs(x,cur,d+1);}
    }

    add[t[cur]].pb(tin[cur]);
    sub[t[cur]].pb(timer);
}

int kthpar(int a, int d) { // set up lca
    for (int i=0;i<l2d;i++) {
        if ((1<<i)&d) {a = lift[i][a];}
    } return a;
}

int lca(int a, int b) {
    if (depth[a]<depth[b]) {swap(a,b);}
    a = kthpar(a,depth[a]-depth[b]);
    if (a==b) {return a;}
    for (int i=l2d-1;i>=0;i--) {
        if (lift[i][a]!=lift[i][b]) {
            a = lift[i][a];
            b = lift[i][b];
        }
    }
    return lift[0][a];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);

    memset(lift,-1,sizeof(lift));
    int n, m; cin >> n >> m;
    for (int i=0;i<n;i++) {cin >> t[i]; t[i]--;}
    for (int i=0;i<n-1;i++) {
        int x, y; cin >> x >> y;
        adj[--x].pb(--y);
        adj[y].pb(x);
    }
    dfs(0,-1,0); // set up euler tour
    
    for (int b=1;b<l2d;b++) { // set up lca
        for (int i=0;i<n;i++) {
            if (lift[b-1][i]!=-1) {lift[b][i] = lift[b-1][lift[b-1][i]];}
        }
    }
    
    for (int i=0;i<m;i++) {
        cin >> a[i] >> b[i] >> c[i];
        q[--c[i]].pb(--a[i]); // these are the real queries
        q[c[i]].pb(--b[i]); // given pair {c,x}, find # nodes with type C on the path from X to the root
        q[c[i]].pb(lca(a[i],b[i]));
    }
    for (int i=0;i<n;i++) { // 2p on all arrays to answer queries
        sort(all(add[i])); sort(all(sub[i])); sort(all(q[i]),[&](int x, int y) {return tin[x]<tin[y];});
        int p1 = 0, p2 = 0, sum = 0;
        for (int x : q[i]) {
            while (p1<add[i].size() && add[i][p1]<=tin[x]) {sum++; p1++;}
            while (p2<sub[i].size() && sub[i][p2]<=tin[x]) {sum--; p2++;}
            save[{i,x}] = sum;
        }
    }
    for (int i=0;i<m;i++) { // answer the original queries
        int l = lca(a[i],b[i]);
        cout << (bool)(save[{c[i],a[i]}]+save[{c[i],b[i]}]-2*save[{c[i],l}]+(t[l]==c[i]));
    }
}