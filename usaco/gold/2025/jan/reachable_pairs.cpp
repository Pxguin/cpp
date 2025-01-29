#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

class DSU {
  private:
	vector<int> parents;
	vector<ll> sizes;

  public:
    ll pairs = 0;    v<int> over;

	DSU(int size) : parents(size), sizes(size, 1), over(size,1) {
		for (int i = 0; i < size; i++) { parents[i] = i;}
	}

	int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }
        pairs -= (sizes[x_root]-over[x_root])*(sizes[x_root]-over[x_root]-1)/2;
        pairs -= (sizes[y_root]-over[y_root])*(sizes[y_root]-over[y_root]-1)/2;

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
        over[x_root] += over[y_root];

        pairs += (sizes[x_root]-over[x_root])*(sizes[x_root]-1-over[x_root])/2;
		return true;
	}

    void rupd(int x) {
        pairs -= (sizes[x]-over[x])*(sizes[x]-over[x]-1)/2;
        over[x]--;
        pairs += (sizes[x]-over[x])*(sizes[x]-over[x]-1)/2;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;

    DSU rev(n);
    v<int> s(n);
    F0R(i,n) {
        char c; cin >> c;
        s[i] = (c=='1');
    }

    v<v<int>> adj(n), radj(n);
    F0R(i,m) {
        int u, va; cin >> u >> va;
        if (u>va) {swap(u,va);}
        adj[--u].pb(--va);
        radj[va].pb(u);
    }

    F0R(i,n) { // unite all nodes s_i=1
        if (s[i]==0) {continue;}
        for (int x : adj[i]) {
            if (s[x]==0) {continue;}
            rev.unite(x,i);
        }
    }

    v<ll> ans(n,0);
    for (int i=n-1;i>=0;i--) {
        rev.rupd(rev.find(i));
        if (s[i]==0) { // deal with all nodes s_i=0
            for (int x : adj[i]) {rev.unite(x,i);}
            for (int x : radj[i]) {if (s[x]==1) {rev.unite(x,i);}}
        }
        ans[i] = rev.pairs;
    }
    F0R(i,n) {cout << ans[i] << '\n';}
}