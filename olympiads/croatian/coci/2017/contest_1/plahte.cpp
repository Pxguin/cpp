#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define vec vector

const int MAX_N = 8e4+1, l2d = 18;
pair<pii,int> pts[3*MAX_N]; // set of all points, in sorted order
pair<pii,pii> p2[MAX_N]; //  points, not in sorted order
int lift[MAX_N][l2d];
vec<int> adj[MAX_N]; // for the tree
set<int> col[MAX_N];
int ans[MAX_N], c[MAX_N]; // c stores the color of each paintball; ans = answer for each sheet

int jump(int a, int d) {
    for (int i=0;i<l2d;i++) {
        if ((1<<i)&d) {
            a = lift[a][i];
            if (a==-1) {a = 0;}
        }
    } return a;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, m; cin >> n >> m;
    memset(lift,-1,sizeof(lift));
    p2[0] = {{0,0},{2e9,2e9}};

    for (int i=0;i<n;i++) {
        cin >> pts[i].f.f >> pts[i].f.s;
        cin >> pts[i+n+m].f.f >> pts[i+n+m].f.s;
        pts[i].s = i+1; pts[i+n+m].s = i+n+m+1;
        p2[i+1] = {pts[i].f,pts[i+n+m].f};
    } // [1,n]: pts, [n+1,n+m] balls, [n+m+1,2*n+m] pts2
    for (int i=n;i<n+m;i++) { // the indexing is done so that processing order is rect start -> paintball -> rect end
        cin >> pts[i].f.f >> pts[i].f.s >> c[i-n+1];
        pts[i].s = i+1;
    }
    sort(pts,pts+2*n+m);
    set<pii> active;
    active.insert({0,0});

    for (int i=0;i<2*n+m;i++) {
        int idx = pts[i].s;
        auto[x,y] = pts[i].f;
        
        if (idx<=n+m) { // if it's paintball or rectangle
            int it = prev(active.upper_bound({y,1e9}))->s; // find first rectangle with smaller y coordinate
            int lo = 0, hi = n, mid = (lo+hi)/2, ans = -1; // strictest rect containing this rect/point is an ancestor of that rect
            int goal = (idx<=n ? p2[idx].s.s : y);
            while (lo <= hi) { // binary lifting to get best answer
                int x2 = jump(it,mid);
                if (p2[x2].s.s>=goal) {hi = mid-1; ans = x2;}
                else {lo = mid+1;}
                mid = (lo+hi)/2;
            }
            
            if (idx<=n) { // depending on if it's a sheet or a point do different things
                active.insert({y,idx});
                adj[ans].pb(idx);
                lift[idx][0] = ans;
                for (int j=1;j<l2d;j++) {
                    if (lift[idx][j-1]!=-1) {lift[idx][j] = lift[lift[idx][j-1]][j-1];}
                }
            } else {col[ans].insert(c[idx-n]);}
        } else {
            active.erase(active.find({p2[idx-n-m].f.s,idx-n-m}));
        }
    }

    function<void(int,int)> dfs = [&](int cur, int par) { // distinct colors
        for (int x : adj[cur]) { // the par parameter is useless
            if (x!=par) {
                dfs(x,cur);
                if (col[x].size()>col[cur].size()) {swap(col[x],col[cur]);}
                for (int i : col[x]) {col[cur].insert(i);}
            }
        } ans[cur] = col[cur].size();
    };
    dfs(0,0);
    for (int i=1;i<=n;i++) {cout << ans[i] << '\n';}
}
