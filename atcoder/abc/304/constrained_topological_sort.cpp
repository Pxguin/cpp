#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define vec vector

const int MAX_N = 2e5;

vec<int> adj[MAX_N];
int indeg[MAX_N];

pii range[MAX_N];
int mn[MAX_N];
bool vis[MAX_N] = {false};

int ans[MAX_N];

void dfs(int cur) { // for each i, find minimum r of a descendant (reachable node) of i
    vis[cur] = true;
    for (int x : adj[cur]) {
        if (!vis[x]) {dfs(x);}
        chmin(mn[cur],mn[x]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    memset(indeg,0,sizeof(indeg));
    int n, m; cin >> n >> m;
    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        indeg[b]++;
    }
    for (int i=0;i<n;i++) {
        cin >> range[i].f >> range[i].s;
        mn[i] = range[i].s;
    }
    for (int i=0;i<n;i++) {if (!vis[i]) {dfs(i);}}

    memset(ans,0,sizeof(ans));
    priority_queue<pii,vec<pii>,greater<pii>> todo, wait;
    for (int i=0;i<n;i++) {if (indeg[i]==0) {wait.push({range[i].f,i});}}

    for (int i=1;i<=n;i++) {
        while (wait.size() && wait.top().f<=i) { // make sure l_i <= i
            todo.push({mn[wait.top().s],wait.top().s});
            wait.pop();
        }
        if (todo.empty()) {break;} // todo: candidates for next element in toposort
        int cur = todo.top().s; todo.pop(); // select one with minimum value of min r of a descendant
        ans[cur] = i;

        for (int x : adj[cur]) {
            if (--indeg[x]==0) {wait.push({range[x].f,x});}
        }
    }
    int flag = 1;
    for (int i=0;i<n;i++) {flag &= (range[i].f<=ans[i] && ans[i]<=range[i].s);} // make sure all are satisfied
    if (!flag) {cout << "No\n";}
    else {
        cout << "Yes\n";
        for (int i=0;i<n;i++) {cout << ans[i] << ' ';}
    }
}