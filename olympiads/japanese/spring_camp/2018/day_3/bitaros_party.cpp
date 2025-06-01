#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define all(x) x.begin(),x.end()
#define vec vector

const int K = 150, MAX_N = 1e5;
vec<pii> mx[MAX_N];
vec<int> adj[MAX_N], radj[MAX_N];

bool bad[MAX_N];
int dist[MAX_N];
int c[MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, q; cin >> n >> m >> q;
    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        radj[b].pb(a);
    }
    int from[MAX_N]; memset(from,-1,sizeof(from));
    for (int cur=0;cur<n;cur++) {
        mx[cur].pb({0,cur});
        vec<int> index;
        for (int x : radj[cur]) {
            for (auto[l,y] : mx[x]) {
                if (from[y]==-1) {
                    index.pb(y);
                }
                chmax(from[y],l+1);
            }
        }
        for (int y : index) {mx[cur].pb({from[y],y}); from[y] = -1;}
        sort(all(mx[cur]),greater<>());
        while (mx[cur].size()>K) {mx[cur].pop_back();}
    }
    while (q--) {
        int t, y; cin >> t >> y; t--;
        for (int i=0;i<y;i++) {cin >> c[i]; bad[--c[i]] = true;}
        int ans = -1;

        if (y<K) {
            for (auto[w,x] : mx[t]) {
                if (!bad[x]) {ans = w; break;}
            }
        } else {
            memset(dist,-1,sizeof(dist));
            dist[t] = 0;
            for (int i=t;i>=0;i--) {
                if (dist[i]==-1) {continue;}
                for (int x : radj[i]) {chmax(dist[x],dist[i]+1);}
                if (!bad[i]) {chmax(ans,dist[i]);}
            }
        }
        cout << ans << '\n';
        for (int i=0;i<y;i++) {bad[c[i]] = false;}
    }
}

/*
if y>=sqrt(ysum), then do o(n) brute force
if y<sqrt(ysum), then store sqrt(ysum) longest paths to each node

*/