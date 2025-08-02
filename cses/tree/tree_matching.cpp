#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vec vector

const int N = 2e5;
vec<int> adj[N];
bool marked[N] = {false};
int ans = 0;

void dfs(int cur=0, int par=-1) {
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs(x,cur);
            if (!marked[cur] && !marked[x]) {
                marked[cur] = true;
                ans++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b); adj[b].pb(a);
    } dfs();
    cout << ans << '\n';
}