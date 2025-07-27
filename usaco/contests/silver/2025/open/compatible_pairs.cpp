#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vec vector

const int N = 2e5;
int c[N], d[N];
bool vis[N] = {false};

vec<int> adj[N];
ll ans = 0;

void dfs(int cur) { // greedy
    vis[cur] = true;
    for (int x : adj[cur]) {
        if (!vis[x]) {
            dfs(x);

            ll add = min(c[cur],c[x]);
            ans += add;
            c[cur] -= add;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, a, b; cin >> n >> a >> b;
    vec<int> self;
    unordered_map<int,int> label; // technically cheating o(n)
    for (int i=0;i<n;i++) {
        cin >> c[i] >> d[i];
        if (d[i]*2==a || d[i]*2==b) {self.pb(i);}
        if (label.count(a-d[i])) { // build graph
            adj[i].pb(label[a-d[i]]);
            adj[label[a-d[i]]].pb(i);
        }
        if (label.count(b-d[i])) {
            adj[i].pb(label[b-d[i]]);
            adj[label[b-d[i]]].pb(i);
        }

        label[d[i]] = i;
    }
    for (int x : self) { // isolate self loops
        dfs(x);
        ans += c[x]/2; // use the self loop (add remaining from root)
    }
    for (int i=0;i<n;i++) { // dfs
        if (!vis[i]) {dfs(i);}
    }
    cout << ans << '\n';
}