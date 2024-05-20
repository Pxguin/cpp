#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll mod = 2019201997;
ll xmod = 2019201913;
ll ymod = 2019201949;

ll calc(ll x, ll y) {
    return (((x+1)*xmod%mod)+((y+1)*ymod%mod))%mod;
}

int n, k;
vector<bool> vis;
vector<ll> dist;

void prim() {
    dist[0] = 0;

    for (int i=0;i<n;i++) {
        int cur = -1;
        for (int j=0;j<n;j++) {
            if (!vis[j] && (cur == -1 || dist[j] < dist[cur])) {cur = j;}
        }
        vis[cur] = true;
        for (int j=0;j<n;j++) {
            if (!vis[j]) {dist[j] = min(dist[j], calc(min(cur,j),max(cur,j)));}
        }
    }
}

int main() {
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    vis.resize(n, false); dist.resize(n+1, mod);

    prim();
    sort(dist.begin(), dist.end());
    cout << dist[n-k+1] << '\n';
}