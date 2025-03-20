#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

void solve() {
    int n, m; cin >> n >> m;
    v<v<int>> a(n,v<int>(m));
    v<v<pii>> adj(n+n*m), grp(m);
    v<ll> dist(n+n*m,LLONG_MAX); // [0,n): global nodes, [km,km+m): attr m
    v<int> c(n);
    F0R(i,n) {cin >> c[i];}
    F0R(i,n) {
        F0R(j,m) {
            cin >> a[i][j];
            grp[j].pb({a[i][j],i+(j+1)*n});

            adj[i+(j+1)*n].pb({i,c[i]}); // global node edges
            adj[i].pb({i+(j+1)*n,0});
        }
    }
    F0R(i,m) {
        sort(all(grp[i]));

        F0R(j,grp[i].size()) { // build extra edges
            if (j) {
                adj[grp[i][j].s].pb({grp[i][j-1].s,grp[i][j].f-grp[i][j-1].f});
                adj[grp[i][j-1].s].pb({grp[i][j].s,0});
            }
        }
    }

    priority_queue<pii,v<pii>,greater<pii>> pq;
    dist[0] = 0; pq.push({0,0});
    while (pq.size()) { // basic dijkstra
        auto[d,cur] = pq.top(); pq.pop();
        if (d!=dist[cur]) {continue;}
        for (auto[x,w] : adj[cur]) {
            if (dist[x]>d+w) {pq.push({dist[x]=d+w,x});}
        }
    }
    cout << dist[n-1] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}