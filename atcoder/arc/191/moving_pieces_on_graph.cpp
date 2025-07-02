#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmin(a, b) a = min(a,b)
#define vec vector

const int N = 2e5, INF = 1e7;
vec<int> adj[N];
int dist[N], dist2[N], from[N];
vec<int> todo[N];

void bfs(int u) { // calc shortest path from S to T
    queue<int> q;
    q.push(u); from[u] = -1; dist[u] = 0; // U = S
    while (q.size()) {
        int cur = q.front(); q.pop();
        for (int x : adj[cur]) {
            if (dist[x]==INF) {
                dist[x] = dist[cur]+1;
                from[x] = cur;
                q.push(x);
            }
        }
    }
}

void bfs2() { // calculate second shortest path from S to T
    queue<int> q;
    for (int d=0;d<N;d++) {
        for (int x : todo[d]) {
            if (d==dist2[x]) {q.push(x);}
        }
        while (q.size() && dist2[q.front()]==d) {
            int cur = q.front(); q.pop();
            for (int x : adj[cur]) {
                if (dist2[x]>dist2[cur]+1) {
                    dist2[x] = dist2[cur]+1;
                    q.push(x);
                }
            }
        }
    }
}

int from_ends(int cur, int last) { // calculate nearest vertex to cur with degree >2
    int d = 0;
    while (adj[cur].size()==2 && d<N) { // d<N check (if all vertices are in a cycle)
        d++;
        int nxt = (adj[cur][0]==last ? adj[cur][1] : adj[cur][0]); // move to the child that is not last
        last = cur; cur = nxt;
    } return (adj[cur].size()==1 || d==N ? INF : d+1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, u, v; cin >> n >> m >> u >> v;
    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    u--; v--;

    for (int i=0;i<n;i++) {dist[i] = dist2[i] = INF;}

    bfs(u);
    int ans = INF;
    int d = dist[v], last = v, cur = from[v];
    int nxt = -1;

    while (cur!=-1) {
        if (cur!=u && adj[cur].size()>2) {ans = 2*d+2;} // case 1: 2d+2 (two tokens "swap" along some vertex in path)

        if (from[cur]==u) {nxt = cur;}
        for (int x : adj[cur]) { // go along the found shortest path
            if (x!=from[cur] && x!=last) {
                chmin(dist2[x],dist[cur]+1); // update vertices distances (for finding second shortest path)
            }
        } last = cur; cur = from[cur];
    }
    chmin(ans,2*d+4*min(from_ends(u,nxt),from_ends(v,from[v]))); // case 2: two tokens "swap" via either S or T

    for (int i=0;i<n;i++) {
        if (dist2[i]!=INF) {todo[dist2[i]].pb(i);}
    }

    dist2[u] = -1;
    bfs2();
    chmin(ans,d+dist2[v]); // case 3: one token goes along shortest path, other goes along second shortest path
    cout << (ans==INF ? -1 : ans) << '\n';
}