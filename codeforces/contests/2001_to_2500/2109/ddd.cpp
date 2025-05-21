#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define vec vector

void solve() {
    int n, m, l; cin >> n >> m >> l;
    vec<vec<int>> adj(n), dist(n,vec<int>(2,INT_MAX));
    vec<ll> a(l);
    
    for (int i=0;i<l;i++) {cin >> a[i];}

    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b); adj[b].pb(a);
    }

    dist[0][0] = 0;
    queue<pii> q; q.push({0,0});
    while (q.size()) { // shortest odd and even length paths to each vertex
        auto[cur,w] = q.front(); q.pop();
        for (int x : adj[cur]) {
            if (dist[x][!w]==INT_MAX) {
                dist[x][!w] = dist[cur][w]+1;
                q.push({x,!w});
            }
        }
    }

    ll mn_odd = LLONG_MAX, sum = 0;
    for (int i=0;i<l;i++) {
        if (a[i]&1) {chmin(mn_odd,a[i]);}
        sum += a[i];
    }
    ll even = sum-(sum&1 ? mn_odd : 0), odd = sum-(!(sum&1) ? mn_odd : 0);
    // maximum odd and even sum in the multiset

    for (int i=0;i<n;i++) { // it works if max_even_sum>=min_even_dist or max_odd_sum>=min_odd_dist
        cout << (even>=dist[i][0] || (mn_odd!=LLONG_MAX && odd>=dist[i][1]));
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}