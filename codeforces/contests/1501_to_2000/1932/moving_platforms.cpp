#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

ll h;
ll euclid(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void solve() {
    int n, m; cin >> n >> m >> h;
    v<int> l(n), s(n);
    F0R(i,n) {cin >> l[i];}
    F0R(i,n) {cin >> s[i];}
    v<v<int>> adj(n);
    F0R(i,m) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    v<ll> dist(n,LLONG_MAX);
    priority_queue<pii,v<pii>,greater<pii>> pq;
    pq.push({0,0}); dist[0] = 0;

    while (pq.size()) {
        auto [d,cur] = pq.top(); pq.pop();
        if (d!=dist[cur]) {continue;}

        for (int to : adj[cur]) {
            ll ab = ((s[cur]-s[to])%h+h)%h; // compute extended euclidean alg to solve equation
            ll cd = (((s[to]*(d%h)+l[to])%h-(s[cur]*(d%h)+l[cur]))%h+h)%h;
            ll weight = -1;

            if (ab==0) { // side case
                if (cd==0) {weight = 0;}
            } else {
                ll g = gcd(ab,h);
                if (cd%g==0) { // reduce by gcd(a-b,h)
                    ll h2 = h/g;
                    ll x, y, res = euclid(ab/g,h2,x,y);
                    weight = ((x*cd/g)%h2+h2)%h2;
                }
            }

            if (weight!=-1 && weight+d+1<dist[to]) {
                pq.push({dist[to]=weight+d+1,to});
            }
        }
    } cout << (dist[n-1]==LLONG_MAX ? -1 : dist[n-1]) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}