#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 2e5, log2dist = 18;
int adj[MAX_N], vis[MAX_N], dist[MAX_N];
v<int> radj[MAX_N];
int succ[MAX_N][log2dist], pos[MAX_N], comp[MAX_N];
v<int> len;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, q; cin >> n >> q;

    F0R(i,n) {
        cin >> adj[i];
        adj[i]--;
        succ[i][0] = adj[i];
        radj[adj[i]].pb(i);
        
        dist[i] = INT_MAX;
    }

    F0R(i,n) {
        if (dist[i]==INT_MAX) {
            
            // find sinks (nodes in cycle)
            int x = adj[i], y = adj[adj[i]];
            while (x!=y) {x = adj[x]; y = adj[adj[y]];}
            v<int> cyc;
            do {
                cyc.pb(x);
                x = adj[x];
            } while (x!=y);
                
            queue<int> q; // bfs from sinks
            for (int i : cyc) {
                dist[i] = 0; // store position in cycle and length of cycle
                pos[i] = q.size();
                comp[i] = len.size();
                q.push(i);
            }
            len.pb(cyc.size());

            while (q.size()) {
                int cur = q.front(); q.pop();
                for (int x : radj[cur]) {
                    if (dist[x]==INT_MAX) {
                        dist[x] = dist[cur]+1;
                        q.push(x);
                    }
                }
            }
        }
    }

    // calc bin lift arrays
    FOR(p,1,log2dist) {
        F0R(i,n) {succ[i][p] = succ[succ[i][p-1]][p-1];}
    }
    auto lift = [&](int c, int d) {
        F0R(i,log2dist) {
            if ((1<<i)&d) {c = succ[c][i];}
        } return c;
    };


    // queries
    while (q--) {
        int a, b; cin >> a >> b;
        a--; b--;
        int da = dist[a], db = dist[b], ans = 0;

        if (da && db && da>=db && lift(a,da-db)==b) { // both have non zero depth
            ans = da-db;
        } else if (db==0) { // b is in cycle
            ans = da; // lift a to cycle
            a = lift(a,da); 
            da = 0;
            if (comp[a]==comp[b]) { // if they're in the same cycle then move them a to b
                ans += (pos[b]-pos[a]+len[comp[a]])%len[comp[a]];
            } else {ans = -1;}
        } else {ans = -1;} // it's impossible otherwise
        cout << ans << '\n';
    }
    
}