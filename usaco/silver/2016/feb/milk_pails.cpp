#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("pails.in","r",stdin);
    freopen("pails.out","w",stdout);
    
    int x, y, k, m; cin >> x >> y >> k >> m;
    v<v<int>> vis(x+1,v<int>(y+1,INT_MAX));
    vis[0][0] = 0;

    int ans = m;
    queue<pii> todo;
    todo.push({0,0});
    int a, b;

    auto add = [&](int na, int nb) { // try visiting node {na,nb}
        if (vis[na][nb]==INT_MAX) {
            vis[na][nb] = vis[a][b]+1;
            todo.push({na,nb});
        }
    };

    while (todo.size()) {
        pii val = todo.front(); todo.pop();
        a = val.f; b = val.s;
        chmin(ans,abs(a+b-m));
        if (vis[a][b] == k) {continue;}

        add(x,b); add(0,b); // fill/empty bucket 1
        add(a,y); add(a,0); // fill empty bucket 2
        int da = min(x-a,b), db = min(y-b,a);
        add(a+da,b-da); add(a-db,b+db); // dump one bucket into the other
    } cout << ans << '\n';
}