#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define vec vector
 
const int MAX_N = 2e5;
vec<int> adj[MAX_N];
 
int sz[MAX_N];
bool removed[MAX_N] = {false};
int freq[MAX_N] = {0};
int k;
 
int get_size(int cur, int par=-1) {
    sz[cur] = 1;
    for (int x : adj[cur]) {
        if (x!=par && !removed[x]) {
            sz[cur] += get_size(x,cur);
        }
    } return sz[cur];
}
int get_cent(int cur, int n2, int par=-1) {
    for (int x : adj[cur]) {
        if (x!=par && !removed[x]) {
            if (sz[x]*2>n2) {return get_cent(x,n2,cur);}
        }
    } return cur;
}
vec<int> paths;
int last = 0;
ll ans = 0;
void dfs(int cur, int rt, int par=-1, int d=0) {
    paths.pb(d);
    for (int x : adj[cur]) {
        if (x!=par && !removed[x]) {
            dfs(x,rt,cur,d+1);
            if (rt==cur) {
                for (int p=last+1;p<paths.size();p++) {
                    if (paths[p]<=k) {ans += freq[k-paths[p]];}
                }
                for (int p=last+1;p<paths.size();p++) {
                    freq[paths[p]]++;
                }
                last = paths.size()-1; 
            }
        }
    }
}
void decomp(int cur=0) {
    int cent = get_cent(cur,get_size(cur));
    removed[cent] = true;
    freq[0]++; last = 0;
    dfs(cent,cent);
    for (int x : paths) {freq[x]--;}
    paths.clear();
    
    for (int x : adj[cent]) {
        if (!removed[x]) {decomp(x);}
    }
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
 
    int n; cin >> n >> k;
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    decomp();
    cout << ans << '\n';
}