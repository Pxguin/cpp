#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vec vector

const int N = 2e5, l2 = 19;
vec<int> adj[N];
int st[N] = {0}, en[N] = {0}, ans[N] = {0};
int n, m;

void dfs(int cur=0, int par=-1) {
    int st2 = 0;
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs(x,cur);
            st2 += st[x], en[cur] += en[x];
        }
    }
    ans[cur] += en[cur]-st2;
    st[cur] += st2;
}

namespace LCA {
    int dep[N], lift[l2][N];
    void dfs(int cur, int par=-1, int d=0) {
        dep[cur] = d; lift[0][cur] = par;
        for (int x : adj[cur]) {
            if (x!=par) {dfs(x,cur,d+1);}
        }
    }
    void init() {
        memset(lift,-1,sizeof(lift));
        dfs(0);
        for (int b=1;b<l2;b++) {
            for (int i=0;i<n;i++) {
                if (lift[b-1][i]!=-1) {lift[b][i] = lift[b-1][lift[b-1][i]];}
            }
        }
    }
    int jump(int a, int d) {
        for (int i=0;i<l2;i++) {
            if ((1<<i)&d) {a = lift[i][a];}
        } return a;
    }
    int lca(int a, int b) {
        a = jump(a,dep[a]-dep[b]);
        if (a==b) {return a;}
        for (int i=l2-1;i>=0;i--) {
            if (lift[i][a]!=lift[i][b]) {
                a = lift[i][a]; b = lift[i][b];
            }
        } return lift[0][a];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b); adj[b].pb(a);
    }
    LCA::init();
    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (LCA::dep[a]<LCA::dep[b]) {swap(a,b);}
        int c = LCA::lca(a,b);
        if (c==b) {
            st[b]++; en[a]++;
        } else {
            st[c] += 2;
            en[a]++; en[b]++;
            ans[c]--;
        }
    }
    dfs();
    for (int i=0;i<n;i++) {cout << ans[i] << ' ';}
}