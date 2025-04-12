#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    pii stop, start;
    cin >> start.f >> start.s >> stop.f >> stop.s;
    
    vec<pii> p(m), x(m), y(m);

    F0R(i,m) {
        cin >> p[i].f >> p[i].s;
        y[i] = {p[i].s,i};
        x[i] = {p[i].f,i};
    }
    sort(all(x)); sort(all(y));
    vec<int> ix(m), iy(m);
    F0R(i,m) {
        ix[x[i].s] = i;
        iy[y[i].s] = i;
    }

    int ans = abs(start.f-stop.f)+abs(start.s-stop.s);
    vec<int> dist(m,INT_MAX);
    priority_queue<pii,vec<pii>,greater<pii>> pq;
    F0R(i,m) { // base cases (distance from starting point)
        dist[i] = min(abs(p[i].f-start.f),abs(p[i].s-start.s));
        pq.push({dist[i],i});
    }
    auto upd = [&](int d, int w, int to) { // dijkstra
        if (d+w<dist[to]) {pq.push({dist[to]=d+w,to});}
    };
    while (pq.size()) {
        auto[d,cur] = pq.top(); pq.pop();
        if (dist[cur]!=d) {continue;}
        chmin(ans,abs(p[cur].f-stop.f)+abs(p[cur].s-stop.s)+d); // try going directly to end point

        int a = ix[cur], b = iy[cur];
        if (a!=0) {upd(d,x[a].f-x[a-1].f,x[a-1].s);} // transition to closest locations (by x-coord) on left and right
        if (a!=m-1) {upd(d,x[a+1].f-x[a].f,x[a+1].s);}
        if (b!=0) {upd(d,y[b].f-y[b-1].f,y[b-1].s);} // closest locations by y-coord on top and bottom
        if (b!=m-1) {upd(d,y[b+1].f-y[b].f,y[b+1].s);}
    }
    cout << ans << '\n';
}