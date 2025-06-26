#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define f first
#define s second
#define vec vector

const int MAX_N = 100000, l2d = 18;
pii lift[MAX_N+1][l2d];
vec<pii> adj[MAX_N];
ll spd[MAX_N], start[MAX_N];
int par[MAX_N];
ll dist[MAX_N], ans[MAX_N];

double isect(pll a, pll b) {return (double)(a.s-b.s)/(b.f-a.f);}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    for (int i=0;i<n-1;i++) {
        int u, v, d; cin >> u >> v >> d;
        adj[--u].pb({--v,d});
        adj[v].pb({u,d});
    }
    for (int i=1;i<n;i++) {cin >> start[i] >> spd[i];}
    spd[0] = start[0] = 0;

    stack<int> todo, go_back;
    vector<pll> hull;
    todo.push(0);
    dist[0] = ans[0] = 0;

    auto qry = [&](int l, int r) {
        int i = __builtin_clzll(1)-__builtin_clzll(r-l+1);
        return min(lift[r][i],lift[l+(1<<i)-1][i]);  
    };

    while (todo.size()) { // iterative dfs
        int cur = todo.top(); todo.pop();
        ans[cur] = 0;

        if (hull.size()) { // query convex hull for x coordinate (binary search on which line it is)
            int lo = 0, hi = hull.size()-1, mid = (lo+hi)/2, res = 0;
            while (lo <= hi) {
                auto[x,y] = qry(mid,hull.size()-1); // use sparse table to find nearest lines on convex hull to mid
                double pt = (x==-1 ? -1 : isect(hull[x],hull[-y]));
                if (pt<=spd[cur]) {res = mid; lo = mid+1;} // find intersection <= spd (the query x coordinate)
                else {hi = mid-1;}
                mid = (lo+hi)/2;
            }

            ans[cur] = hull[res].f*spd[cur]+hull[res].s + dist[cur]*spd[cur]+start[cur]; // compute dp value (cht)
        }
        hull.pb({-dist[cur],ans[cur]});

        int sz = hull.size();
        if (sz>1) { // add this line to the hull
            int lo = 1, hi = hull.size()-2, mid = (lo+hi)/2, res = hull.size()-1;
            while (lo <= hi) { // binary search on insert location
                auto[x,y] = qry(mid,sz-2); // use rmq to find nearest lines on hull to mid
                if (isect(hull[x],hull.back())<=isect(hull[x],hull[-y])) { // check if this new line removes any of the old lines
                    res = mid; hi = mid-1;
                } else {lo = mid+1;}
                mid = (lo+hi)/2;
            }
            lift[sz-1][0] = {res-1,-(sz-1)}; // res-1 is the first line that is not removed from the hull
        } else {
            lift[sz-1][0] = {-1,-(sz-1)}; // -1 = no line before this one
        }

        for (int i=1;i<l2d;i++) { // update sparse table (sort by prev line on hull, tiebreak by maximizing index)
            lift[sz-1][i] = (sz>=(1<<i) ? min(lift[sz-1][i-1],lift[sz-1-(1<<(i-1))][i-1]) : make_pair(-1,-(sz-1)));
        }
        
        int last = -1;
        for (auto[x,d] : adj[cur]) { // dfs to children
            if (x!=par[cur]) {
                par[x] = cur; dist[x] = dist[cur]+d;
                todo.push(x);
                if (last==-1) {last = x;}
            }
        }
        if (last!=-1) {go_back.push(last);}

        if (adj[cur].size()==1 && cur!=0) {hull.pop_back();}
        while (go_back.size() && go_back.top()==cur) { // dfs backtrack
            cur = par[cur]; go_back.pop();
            hull.pop_back();
        }
    }
    for (int i=1;i<n;i++) {cout << ans[i] << ' ';}
}