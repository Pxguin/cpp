#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vec vector

const int MAX_N = 1e5, l2d = 18;
vec<int> adj[MAX_N];
vec<int> ord[MAX_N];
int deg[MAX_N] = {0}, rem[MAX_N] = {0};

int par[l2d][MAX_N], dep[MAX_N];
void binliftdfs(int cur, int p, int d) { // precalc bin lifts
    par[0][cur] = p; dep[cur] = d;
    for (int x : adj[cur]) {
        if (x!=p) {binliftdfs(x,cur,d+1);}
    }
}

int lift(int a, int d) {
    for (int i=0;i<l2d;i++) {
        if (a!=-1 && ((1<<i)&d)) {a = par[i][a];}
    } return a;
}
bool is_anc(int a, int b) { // is a ancestor of b
    int d = dep[b]-dep[a];
    if (d>0) {b = lift(b,d);}
    return (a==b);
}

bool no[MAX_N] = {false}, ans[MAX_N] = {false};
void ansdfs(int cur, int p) { // mark which nodes can leave last
    ans[cur] = true;
    for (int x : adj[cur]) {
        if (x!=p && !no[x]) {ansdfs(x,cur);} // if the node is visitable
    }
}

int main() {
    freopen("gathering.in","r",stdin);
    freopen("gathering.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
        deg[a]++; deg[b]++;
    }
    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        ord[--a].pb(--b);
        rem[b]++;
    }
    queue<int> q;
    int unvis = n;
    for (int i=0;i<n;i++) {if (rem[i]==0&&deg[i]==1) {q.push(i);}}
    while (q.size()) { // check if a valid ordering exists
        int cur = q.front(); q.pop();
        unvis--;
        for (int x : adj[cur]) {
            if (--deg[x]==1&&rem[x]==0) {q.push(x);}
        }
        for (int x : ord[cur]) {
            if (--rem[x]==0&&deg[x]==1) {q.push(x);}
        }
    }

    if (unvis<=1) { // if a valid ordering does exist
        memset(par,-1,sizeof(par));
        binliftdfs(0,-1,0); // calc bin lifts
        for (int i=1;i<l2d;i++) {
            for (int j=0;j<n;j++) {
                if (par[i-1][j]!=-1) {par[i][j] = par[i-1][par[i-1][j]];}
            }
        }
        int start = -1;
        for (int i=0;i<n;i++) {
            for (int x : ord[i]) {
                if (is_anc(i,x)) { // if i is an ancestor of x, then 
                    int z = lift(x,dep[x]-dep[i]-1); // find z: the child of i that is ancestor of x, can only access nodes in z's subtree
                    if (start==-1 || dep[start]<dep[z]) {start = z;} // take the deepest value of z
                } no[i] = true; // cannot access i or it's subtree anymore
            }
        }
        ansdfs(start,-1); // dfs from the deepest value of z to get answer
    }
    for (int i=0;i<n;i++) {cout << ans[i] << '\n';}
}