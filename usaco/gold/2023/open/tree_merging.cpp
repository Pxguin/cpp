#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

// ok
v<v<int>> adj, adj2;
int rt, n, m;
v<pii> ans;
v<int> tomerge;
int flag;
v<bool> p;

void unite(int a, int b) { // merge two nodes
    ans.pb({a,b});
    for (int x : adj[a]) {adj[b].pb(x);}
}
void dfs(int cur, int b, v<int>& par) { // mark paths
    par[cur] = b;
    for (int x : adj2[cur]) {dfs(x,b,par);}
}
void test(int cur, v<int>& par) { // find paths
    if (p[cur]) {flag = par[cur];}
    for (int x : adj[cur]) {test(x,par);}
}
void compress(int cur) { // compress subtree
    int mx = -1;
    for (int x : adj[cur]) {chmax(mx,x);}
    for (int x : adj[cur]) {
        if (mx!=x) {unite(x,mx);}
    }
    if (mx!=-1) {adj[cur] = {mx};}
}

v<int> path;
bool find_path(int a, int b) { // find path for merging
    if (adj[a].size() && adj2[b].empty()) {return false;}
    if (adj[a].empty()) {return true;}
    for (int i : adj2[b]) {
        if (i>adj[a][0]) {
            path.pb(i);
            if (find_path(adj[a][0],i)) {return true;}
            path.pop_back();
        }
    } return false;
}
void mark(int a, int pt) { // mark path for merging
    tomerge[a] = path[pt];
    if (adj[a].size()) {
        mark(adj[a][0],pt+1);
    }
}

void solve() {
    // construct trees
    cin >> n;
    adj.clear(); adj.resize(n);
    ans.clear(); tomerge.assign(n,-1);
    p.assign(n,false);
    v<bool> to(n,false);

    F0R(i,n-1) {
        int u, v; cin >> u >> v;
        adj[--v].pb(--u);
        to[u] = true;
    }
    F0R(i,n) {if (!to[i]) {rt=i;}}

    cin >> m;
    adj2.clear(); adj2.resize(n);
    F0R(i,m-1) {
        int u, v; cin >> u >> v;
        adj2[--v].pb(--u);
        p[u] = p[v] = true;
    }

    // dfs
    auto solve = [&](auto& solve, int cur)->void {
        v<int> par(n,-1), todo;
        v<int> nxt;

        // find children, see which ones exist in final tree
        for (int a : adj[cur]) {
            if (tomerge[a]!=-1) {
                unite(a,tomerge[a]);
            } else if (p[a]) {
                dfs(a,a,par);
                nxt.pb(a);
            } else {todo.pb(a);}
        }
        
        // check to see which nodes are assigned for merging already
        // check to see which nodes can be instantly merged
        for (int a : todo) {
            flag = -1; test(a,par);
            if (flag!=-1) {unite(a,flag);}
            else { // for rest of children, compress subtree and find path
                compress(a);

                for (int i : nxt) {
                    if (i>a && find_path(a,i)) {
                        unite(a,i);
                        if (path.size()) {mark(adj[a][0],0);}
                        path.clear();
                        break;
                    }
                }
            }
        }
        for (int i : nxt) {solve(solve,i);}

    };
    solve(solve,rt);
    cout << ans.size() << '\n';
    for (pii i : ans) {cout << i.f+1 << ' ' << i.s+1 << '\n';} 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t; cin >> t;
    while (t--) {solve();}
}