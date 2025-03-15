#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAX_N = 2e5;
ordered_set<int> subtree[MAX_N];
int inv[MAX_N] = {0};
ll ans[MAX_N], bad[MAX_N] = {0}, ancdec[MAX_N] = {0};
vec<int> adj[MAX_N];

ll tot = 0, out_sum = 0, n;

void dfs(int cur, int par) {
    for (int x : adj[cur]) {
        if (x!=par) {
            dfs(x,cur);
            ancdec[x] = subtree[x].order_of_key(cur); // amt inversions from par to node in subtree of child
            if (subtree[cur].size()<subtree[x].size()) {subtree[cur].swap(subtree[x]);} // merging
            for (int i : subtree[x]) {subtree[cur].insert(i);}
        }
    }
    inv[cur] = subtree[cur].order_of_key(cur); // amount of inversions in subtree
    tot += inv[cur];

    subtree[cur].insert(cur);
}

void dfs2(int cur, int par) {
    ll b = bad[cur]; // keeps track of number of bad inversions
    out_sum += cur-inv[cur]; // amount of inversions not to a node in the subtree

    for (int x : adj[cur]) {
        if (x!=par) {
            bad[x] += ancdec[x]+b; // any of the existing inversions are bad, as well as inversions starting from this node
            dfs2(x,cur);
            bad[cur] += bad[x]-b-ancdec[x]; // retract "b" (existing inversions) for double counting; and ancdec[x] because they're not bad anymore
        }
    }
    ans[cur] = tot+out_sum-bad[cur]; // tot+out_sum = number of candidates inversions, subtract the amount of bad ones

    out_sum -= cur-inv[cur];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    F0R(i,n-1) {
        int a, b; cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs(0,0);
    dfs2(0,0);
    F0R(i,n) {cout << ans[i] << ' ';}
}