#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

const int MAX_N = 3e5;
v<pii> adj[MAX_N];
ll dp1[MAX_N], dp2[MAX_N];
int d[MAX_N];

void dfs(int cur, int par) {
    v<ll> cand;
    for (pii x : adj[cur]) {
        if (x.f!=par) {
            dfs(x.f,cur);
            dp1[cur] += dp2[x.f]; // first don't select any edges
            if (d[x.f]>0 && dp1[x.f]+x.s>dp2[x.f]) { // only consider selecting the edge if the gain is positive
                cand.pb(dp1[x.f]+x.s-dp2[x.f]);
            }
        }
    }
    sort(all(cand),greater<>()); // greedily pick the largest gains first
    F0R(i,min(d[cur]-1,(int)cand.size())) {
        dp1[cur] += cand[i];
    }
    dp2[cur] = dp1[cur];
    if (d[cur]>0 && cand.size()>=d[cur]) {dp2[cur] += cand[d[cur]-1];}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    F0R(i,n) {cin >> d[i];}
    F0R(i,n-1) {
        int a, b, w; cin >> a >> b >> w;
        adj[--a].pb({--b,w});
        adj[b].pb({a,w});
    }
    dfs(0,0);
    cout << dp2[0] << '\n';
}