#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(x) x.begin(),x.end()
#define vec vector

const int MAX_N = 2e5, F = 30;
int fib[F];

vec<int> adj[MAX_N];
int a = -1, b = -1;

int dfs(int cur, int par, int f) {
    int sz = 1;
    for (int x : adj[cur]) {
        if (x!=par) {
            sz += dfs(x,cur,f);
        }
    }
    if (sz==fib[f-2]) {a = cur; b = par;} // find the edge that splits the tree
    else if (sz==fib[f-1]) {a = par; b = cur;}
    return sz;
}

bool check(int cur, int sz) {
    if (fib[sz]==1) {return true;} // base case
    a = -1; b = -1;
    dfs(cur,-1,sz);
    int a1 = a, b1 = b;
    if (a1==-1) {return false;} // recursively find edge that splits tree, 

    adj[a1].erase(find(all(adj[a1]),b1)); // delete edge, 
    adj[b1].erase(find(all(adj[b1]),a1));
    
    return (check(a1,sz-2) && check(b1,sz-1)); // check if two subgraphs are fibtrees
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    fib[0] = fib[1] = 1;
    for (int i=2;i<F;i++) {fib[i] = fib[i-1]+fib[i-2];}

    int n; cin >> n;
    for (int i=0;i<n-1;i++) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    int sz = -1;
    for (int i=0;i<30;i++) {if (fib[i]==n) {sz = i;}} // check if N is fibonacci

    cout << (sz!=-1 && check(0,sz) ? "YES" : "NO") << '\n';
}