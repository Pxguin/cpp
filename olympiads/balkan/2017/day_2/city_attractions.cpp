#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define vec vector

const int MAX_N = 3e5;
int to[MAX_N];
vec<int> adj[MAX_N];
int a[MAX_N];
pii self[MAX_N], dp2[MAX_N], mx[MAX_N][2];
bool vis[MAX_N] = {false};

/*
rerooting dp -> construct functional graph -> get answer
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; ll k; cin >> n >> k;

    for (int i=0;i<n;i++) {cin >> a[i];}
    for (int i=0;i<n-1;i++) {
        int u, v; cin >> u >> v;
        adj[--u].pb(--v);
        adj[v].pb(u);
    }
    
    for (int i=0;i<n;i++) {self[i] = {a[i],-i};}
    function<void(int,int)> dfs = [&](int cur, int par)->void {
        mx[cur][0] = mx[cur][1] = {-1e6,-1e6};
        for (int x : adj[cur]) {
            if (x!=par) {
                dfs(x,cur);
                pii push = max(mx[x][0],self[x]); push.f--;
                if (push>=mx[cur][0]) {
                    mx[cur][1] = mx[cur][0];
                    mx[cur][0] = push;
                } else if (push>mx[cur][1]) {
                    mx[cur][1] = push;
                }
            }
        }
    };

    function<void(int,int)> dfs2 = [&](int cur, int par)->void {
        to[cur] = -max(dp2[cur],mx[cur][0]).s;
        for (int x : adj[cur]) {
            if (x!=par) {
                pii push = max(mx[x][0],self[x]); push.f--;
                pii push2 = max(dp2[cur],self[cur]);
                if (push==mx[cur][0]) {
                    chmax(push2,mx[cur][1]); push2.f--;
                    dp2[x] = push2;
                } else {
                    chmax(push2,mx[cur][0]); push2.f--;
                    dp2[x] = push2;
                }
                dfs2(x,cur);
            }
        }
    };
    dp2[0] = {-1e6,-1e6};
    dfs(0,-1); dfs2(0,-1);

    int targ = -1, len = 0;
    vec<int> cyc;
    function<void(int)> heck = [&](int cur)->void {
        if (vis[cur]) {targ = cur; return;}
        len++;
        vis[cur] = true;
        heck(to[cur]);
        if (targ!=-1) {cyc.pb(cur);}
        if (cur==targ) {targ = -1;}
    };
    heck(0);
    reverse(cyc.begin(),cyc.end());
    int ans = 0; len -= cyc.size();
    if (k<=len) {
        for (int i=0;i<k;i++) {ans = to[ans];}
    } else {
        ans = cyc[(k-len)%cyc.size()];
    }
    
    cout << ans+1 << '\n';
}