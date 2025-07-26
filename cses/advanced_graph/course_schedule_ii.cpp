#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;

    vec<int> indeg(n,0);
    vec<vec<int>> adj(n);
    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        adj[--b].pb(--a);
        indeg[a]++;
    }
    priority_queue<int> pq;
    for (int i=0;i<n;i++) {
        if (!indeg[i]) {pq.push(i);}
    }
    vec<int> ans;
    while (pq.size()) {
        int cur = pq.top(); pq.pop();
        ans.pb(cur);
        for (int x : adj[cur]) {
            if (--indeg[x]==0) {pq.push(x);}
        }
    } reverse(ans.begin(),ans.end());
    
    for (int i : ans) {cout << i+1 << ' ';}
}