#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

const int MAX_N = 3000*3+1;
v<int> adj[MAX_N];
int match[MAX_N] = {0}, dist[MAX_N];
int n;
const int INF = 1e9;

bool bfs() {
    queue<int> q;
    for (int i=1;i<=3*n;i++) { // initialize
        if (!match[i]) {
            q.push(i);
            dist[i] = 0;
        } else {dist[i] = INF;}
    }
    dist[0] = INF;
    
    while (q.size()) { // bfs, a layout for the dfs as to force an extension of the shortest augmented path
        int cur = q.front(); q.pop();
        for (int x : adj[cur]) {
            if (dist[match[x]]==INF) {
                dist[match[x]] = dist[cur]+1;
                q.push(match[x]);
            }
        }
    }
    return dist[0]!=INF; // this happens when no more augmented paths can be extended
}

bool kuhn(int cur) {
    if (cur==0) {return true;} // 0 = unmatched

    for (int x : adj[cur]) { // find augmented path, and then flip all edges on path so that path is 1 longer
        if (dist[match[x]]==dist[cur]+1 && kuhn(match[x])) { 
            match[x] = cur;
            match[cur] = x;
            return true;
        }
    }
    dist[cur] = INF;
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("canibali.in","r",stdin);
    freopen("canibali.out","w",stdout);

    cin >> n;
    v<array<int,4>> c(n+1);
    for (int i=1;i<=n;i++) {
        cin >> c[i][0] >> c[i][1] >> c[i][2] >> c[i][3];
    }
    sort(all(c));

    for (int i=1;i<=n;i++) { // build edges
        for (int j=i-1;j>=1;j--) {
            if (c[i][0]>=c[j][0]&&c[i][1]>=c[j][1]&&c[i][2]>=c[j][2]&&c[i][3]>=c[j][3]) {
                adj[i].pb(j+2*n); // [1,n] first copy, [n+1,2n] second copy, [2n+1,3n] third copy
                adj[i+n].pb(j+2*n);
            }
        }
    }

    int ans = n;
    while (bfs()) { // while augmented path can be extended, extend it
        for (int i=1;i<=3*n;i++) {
            if (!match[i] && kuhn(i)) {ans--;} // specifically extending the path
        }
    }
    cout << ans << '\n';
}