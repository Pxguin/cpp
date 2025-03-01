#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 5000;
v<int> adj[MAX_N];
int dist[MAX_N];
int ans = INT_MAX;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    F0R(i,n) {
        int m; cin >> m;
        F0R(j,m) {
            int a; cin >> a;
            adj[--a].pb(i);
        }
    }
    F0R(rt,n) { // fix root
        F0R(i,n) {dist[i] = INT_MAX;}
        queue<int> q;
        q.push(rt); dist[rt] = 1;
        while (q.size()) { // bfs = spanning tree
            int cur = q.front(); q.pop();
            for (int x : adj[cur]) {
                if (dist[x]==INT_MAX) {
                    dist[x] = dist[cur]+1;
                    q.push(x);
                }
            }
        }
        int cand = 0;
        F0R(i,n) { // calc sum of depths = total salary
            if (dist[i]==INT_MAX) {cand = INT_MAX;}
            else if (cand!=INT_MAX) {cand += dist[i];}
        } chmin(ans,cand);
    } cout << ans << '\n';
}