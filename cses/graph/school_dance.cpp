#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 1000;
v<int> adj[MAX_N];
int match[MAX_N];
bool vis[MAX_N];
int n, m;

bool kuhn(int cur) {
    if (vis[cur]) {return false;}
    vis[cur] = true;

    for (int x : adj[cur]) {
        if (match[x]==-1 || kuhn(match[x])) { // if an augmented path is found, flip edges on the path to extend it by 1
            match[x] = cur;
            match[cur] = x;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int k; cin >> n >> m >> k;
    memset(match,-1,sizeof(match));
    F0R(i,k) {
        int a, b; cin >> a >> b;
        adj[a-1].pb(b+n-1);
        adj[b+n-1].pb(a-1);
    }

    int ans = 0;
    F0R(i,n) {
        fill(vis,vis+n+m,false);
        if (kuhn(i)) {ans++;} // try to get every node in matching, one by one
    }

    cout << ans << '\n';
    F0R(i,n) {
        if (match[i]!=-1) {
            cout << i+1 << ' ' << match[i]-n+1 << '\n';
        }
    }
}