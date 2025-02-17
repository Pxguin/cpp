#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("revegetate.in","r",stdin);
    freopen("revegetate.out","w",stdout);

    int n, m; cin >> n >> m;
    v<v<int>> adjs(n), adjd(n);
    for (int i=0;i<m;i++) {
        int a, b; char c; cin >> c >> a >> b;
        if (c=='S') {
            adjs[--a].pb(--b);
            adjs[b].pb(a);
        } else {
            adjd[--a].pb(--b);
            adjd[b].pb(a);
        }
    }
    v<int> color(n,-1);
    bool no = false;

    auto dfs = [&](auto& dfs, int cur)->void { // basically set color of cur
        bool d[2] = {false}, d2[2] = {false};
        for (int x : adjs[cur]) {
            if (color[x]!=-1) {d[color[x]] = true;}
        }
        for (int x : adjd[cur]) {
            if (color[x]!=-1) {d2[color[x]] = true;}
        }
        if ((d[0]&&d[1]) || (d[0]&&d2[0]) || (d2[0]&&d2[1]) || (d[1]&&d2[1])) {no = true;} // contradiction or not
        color[cur] = ((d[0]||d[1]) ? d[1] : d2[0]); // not done the most efficiently

        for (int x : adjs[cur]) { // update adjacent
            if (color[x]==-1) {dfs(dfs,x);}
        }
        for (int x : adjd[cur]) {
            if (color[x]==-1) {dfs(dfs,x);}
        }
    };
    int c = 0;
    for (int i=0;i<n;i++) {
        if (color[i]==-1) { // find num components
            dfs(dfs,i); c++;
        }
    }
    if (no) {cout << 0;} // if it fails
    else { // answer is 2^c
        cout << 1;
        for (int i=0;i<c;i++) {cout << 0;}
    }
}