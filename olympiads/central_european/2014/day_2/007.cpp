#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmax(a, b) a = max(a,b)
#define vec vector

const int N = 2e5;
int d_007[N], d_null[N], d_a[N], d_b[N];
vec<int> adj[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    int s, d, a, b; cin >> s >> d >> a >> b;
    for (int i=0;i<m;i++) {
        int a1, b1; cin >> a1 >> b1;
        adj[--a1].pb(--b1);
        adj[b1].pb(a1);
    }
    for (int i=0;i<n;i++) {d_007[i] = d_null[i] = d_a[i] = d_b[i] = INT_MAX;}
    auto bfs = [&](int* dist, int src) { // normal bfs
        queue<int> q;
        q.push(src); dist[src] = 0;
        while (q.size()) {
            int cur = q.front(); q.pop();
            for (int x : adj[cur]) {
                if (dist[x]==INT_MAX) {
                    dist[x] = dist[cur]+1;
                    q.push(x);
                }
            }
        }
    };
    bfs(d_007,--s); bfs(d_null,--d); bfs(d_a,--a); bfs(d_b,--b);

    int ans = -1;
    if (d_007[a]!=d_007[b]) { // case 1: 007 goes to the closest server first
        chmax(ans,min(d_null[a]-d_007[a],d_null[b]-d_007[b]));
    } else { // she could get to both servers at equal times
        if (d_null[a]!=d_null[b]) { // case 2: first go to the server that null can get to earlier
            chmax(ans,min(min(d_null[a],d_null[b])-d_007[a],max(d_null[a],d_null[b])-d_007[a]-1));
        } else { // case 3
            int split_null = -1, split_007 = -1;
            for (int i=0;i<n;i++) {
                if (d_a[i]==d_b[i]) { // find the longest common prefix of two shortest paths (from D to A, and from D to B)
                    if (d_a[i]+d_null[i]==d_null[a]) {
                        if (split_null==-1 || d_a[i]<d_a[split_null]) {
                            split_null = i;
                        }
                    }
                    if (d_a[i]+d_007[i]==d_007[a]) { // same thing, but for node S
                        if (split_007==-1 || d_a[i]<d_a[split_007]) {
                            split_007 = i;
                        }
                    }
                }
            }
            chmax(ans,d_null[a]-d_007[a]-1); // she picks an arbitrary server to go to first (so she gets to other server 1 unit of time after)
            
            if (d_a[split_007]<=d_a[split_null]) { // if this holds, then 007 knows which server to go to
                chmax(ans,d_null[a]-d_007[a]);
            }
        }
    } cout << ans << '\n';
}