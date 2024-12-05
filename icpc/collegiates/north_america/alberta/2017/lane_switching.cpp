#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<double,double>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int n, m, r;
v<v<pii>> cars;
v<v<int>> idx;
pii acm;
int ctr = 0, car;

bool check(double x) {
    v<v<int>> adj(ctr);
    v<v<pii>> c = cars;
    F0R(i,n) {
        F0R(j,c[i].size()) {c[i][j].f -= x; c[i][j].s += x;}
    }
    if (c[0][car+1].f<acm.s || c[0][car].s>acm.f) {return false;} // if the ACM start pos collides with a car

    F0R(i,n-1) {
        int p2 = 0, s1 = c[i].size()-1, s2 = c[i+1].size()-1;
        F0R(p1,s1) {
            if (c[i][p1+1].f-c[i][p1].s<=0) {continue;} // is the size of first gap > 0
            for (;p2<s2;p2++) {
                if (c[i+1][p2].s>=c[i][p1+1].f) {break;} // has p2 moved past p1 already (if so, move p1)
                if (c[i+1][p2+1].f-c[i+1][p2].s<=0) {continue;} // is the size of second gap > 0
                double space = min(c[i+1][p2+1].f,c[i][p1+1].f)-max(c[i+1][p2].s,c[i][p1].s); // intersection of gaps
                if (space>=acm.s-acm.f) { // if the car can pass through the intersection
                    adj[idx[i+1][p2]].pb(idx[i][p1]);
                    adj[idx[i][p1]].pb(idx[i+1][p2]);
                }
            } p2--; // in case one gap intersects more than one gap
        }
    }
    v<bool> vis(ctr,false); // dfs to see if you can reach lane n-1
    auto dfs = [&](auto& dfs, int cur)->void {
        vis[cur] = true;
        for (int x : adj[cur]) {
            if (!vis[x]) {dfs(dfs,x);}
        }
    };
    dfs(dfs,car);
    for (int i : idx[n-1]) {if (vis[i]) {return true;}}
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> m >> r;
    cars.resize(n); idx.resize(n);

    F0R(i,n) {cars[i].pb({0,0});}
    cin >> acm.f >> acm.s >> acm.f; acm.s += acm.f;
    F0R(i,m-1) {
        int lane, len, dist; cin >> lane >> len >> dist;
        cars[lane].pb({dist,len+dist});
    }
    F0R(i,n) {cars[i].pb({r,r}); sort(all(cars[i]));}

    F0R(i,n) { // locate the gap of the ACM car
        F0R(j,cars[i].size()-1) {
            idx[i].pb(ctr++);
            if (!i && cars[i][j].s<=acm.f) {car = j;}
        }
    }

    double ans = check(0)-1; // bin search
    double l = 0, h = r, mid = (l+h)/2;
    F0R(i,40) {
        if (check(mid)) {l = mid; ans = mid;}
        else {h = mid;}
        mid = l+(h-l)/2;
    }
    if (ans==-1) {cout << "Impossible";}
    else {cout << fixed << setprecision(1) << ans;}
}