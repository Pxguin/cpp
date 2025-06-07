#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define all(x) x.begin(),x.end()
#define vec vector

const int MAX_N = 5e5;
vec<int> adj[MAX_N];
vec<pii> paths[MAX_N];
vec<ll> path[MAX_N];
pii mxpath[MAX_N];

pii ans = {0,1};

void dfs(int cur, int par=-1) {
    mxpath[cur] = {0,0};
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs(x,cur);
            paths[cur].pb({mxpath[x].f+1,mxpath[x].s});
            chmax(mxpath[cur].f,mxpath[x].f+1);
        }
    }
    for (auto[x,w] : paths[cur]) {
        if (x!=mxpath[cur].f) {continue;}
        mxpath[cur].s += w;
    }
    if (adj[cur].size()==1) {paths[cur] = {mxpath[cur] = {0,1}};}
}

void dfs2(int cur, int par=-1, pii par_info = {-1,1}) {
    
    paths[cur].pb({par_info.f+1,par_info.s});
    sort(all(paths[cur]),greater<>());

    path[cur] = {paths[cur][0].s};
    vec<ll> squares = {paths[cur][0].s*paths[cur][0].s};
    for (int i=1;i<paths[cur].size();i++) {
        if (paths[cur][i].f!=paths[cur][i-1].f) {path[cur].pb(0); squares.pb(0);}
        path[cur].back() += paths[cur][i].s;
        squares.back() += (paths[cur][i].s*paths[cur][i].s);
    }
    
    if (adj[cur].size()>=3) {
        pii best;
        ll mx[3] = {paths[cur][0].f,paths[cur][1].f,paths[cur][2].f};

        best.f = (mx[1]+mx[2])*mx[0];
        if (mx[0]!=mx[1] && mx[1]!=mx[2]) {
            best.s = path[cur][1]*path[cur][2];
        } else if (mx[0]==mx[1] && mx[1]!=mx[2]) {
            best.s = path[cur][0]*path[cur][1];
        } else if (mx[0]!=mx[1] && mx[1]==mx[2]) {
            best.s = (path[cur][1]*path[cur][1]-squares[1])/2;
        } else {
            best.s = (path[cur][0]*path[cur][0]-squares[0])/2;
        }

        if (ans.f==best.f) {ans.s += best.s;}
        else if (best.f>ans.f) {ans = best;}
    }
    
    for (int x : adj[cur]) {
        if (x!=par) {
            if (mxpath[x].f+1==paths[cur][0].f) {
                if (mxpath[x].s==path[cur][0]) {
                    dfs2(x,cur,{paths[cur][1].f,path[cur][1]});
                } else {
                    dfs2(x,cur,{paths[cur][0].f,path[cur][0]-mxpath[x].s});
                }
            } else {
                dfs2(x,cur,{paths[cur][0].f,path[cur][0]});
            }
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
    int rt = 0;
    for (int i=0;i<n;i++) {if (adj[i].size()>1) {rt = i;}}
    dfs(rt);
    dfs2(rt);

    cout << ans.f << ' ' << ans.s << '\n';
}