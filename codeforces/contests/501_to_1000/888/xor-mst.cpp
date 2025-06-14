#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define chmin(a, b) a = min(a,b)
#define vec vector

const int MAX_N = 2e5, l2 = 30;
int a[MAX_N], trie[MAX_N*l2+1][2], par[MAX_N*l2+1];
vec<int> comp[MAX_N*l2+1];
int nodes = 0;

void ins(int x) {
    int cur = 0;
    for (int i=l2-1;i>=0;i--) {
        bool b = (1<<i)&x;
        if (trie[cur][b]==0) {trie[cur][b] = ++nodes; par[nodes] = cur;}
        cur = trie[cur][b];
    }
    comp[cur].pb(x);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    for (int i=0;i<n;i++) {cin >> a[i]; ins(a[i]);}

    ll ans = 0;
    stack<int> todo; todo.push(0);
    stack<int> done;
    int dep = l2;
    
    while (todo.size()) { // basically iterative dfs
        int cur = todo.top(); todo.pop();
        int last = -1;
        if (trie[cur][0]) {todo.push(trie[cur][0]); last = 0;} // push children to stack
        if (trie[cur][1]) {todo.push(trie[cur][1]); last = 1;}

        if (trie[cur][0] && trie[cur][1]) {done.push(trie[cur][0]);} // mark which child is last processed child...
        else if (last!=-1) {done.push(trie[cur][last]);} // (so that after processing it, we go back to its parent)

        while (done.size() && done.top()==cur) { // go back to its parent
            dep++;
            cur = par[done.top()]; done.pop();
            int l = trie[cur][0], r = trie[cur][1];
            
            if (l && r) {
                if (comp[l].size()>comp[r].size()) {swap(l,r);}
                int mn = INT_MAX, cand;
                for (int x : comp[l]) { // for each number in smaller set...
                    cand = (1<<(dep-1));
                    for (int i=dep-2,node=r;i>=0;i--) { // find min xor in larger set...
                        bool b = (1<<i)&x;
                        if (trie[node][b]) {node = trie[node][b];}
                        else {node = trie[node][!b]; cand += (1<<i);}
                    } chmin(mn,cand);
                } ans += mn; // and add it to the answer
            }
            if (l) {comp[cur].swap(comp[l]);} // small to large merge (store set of all a[i] in this subtree)
            if (r) {
                if (comp[cur].size()<comp[r].size()) {swap(comp[cur],comp[r]);}
                for (int x : comp[r]) {comp[cur].pb(x);}
                comp[r].clear();
            }
        }
        if (last!=-1) {dep--;}
    }
    cout << ans << '\n';
}