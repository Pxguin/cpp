#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	int a, b; ll t;
	vector<vector<pii>> adj(n);
	vector<int> deg(n,0);
	for (int i=0;i<m;i++) {
		cin >> a >> b >> t;
		adj[--b].pb(mp(--a,t));
		deg[a]++;
	}

	vector<pii> ans(n,mp(0,0));
	vector<ll> rank(n,0); vector<vector<vector<ll>>> cand(n); 
	vector<ll> nodes;
	for (int i=0;i<n;i++) {if (!deg[i]) {nodes.pb(i);}}

	while (nodes.size()) {
		vector<ll> nxt;
		while (nodes.size()) {
			ll cur = nodes.back(); nodes.pop_back();
			for (pii x : adj[cur]) {
				if (--deg[x.f]==0) {nxt.pb(x.f);}
				if (ans[cur].f+1 >= ans[x.f].f) {
                    cand[x.f].pb({-(ans[cur].f+1),x.s,rank[cur],ans[cur].s+x.s});
                }
			}
		}
		vector<vector<ll>> best;
		for (int j=0;j<nxt.size();j++) {
            int i = nxt[j];
            sort(cand[i].begin(), cand[i].end());
            while (cand[i].size() > 1) {cand[i].pop_back();}
            ans[i] = {-cand[i][0][0],cand[i][0][3]};
            best.pb({cand[i][0][1],cand[i][0][2],i});
        }
		sort(best.begin(),best.end());
        for (int i=0;i<best.size();i++) {
            rank[best[i][2]] = i;
        }
        nodes = nxt;
	}
	for (pii x : ans) {cout << x.f << ' ' << x.s << '\n';}
}