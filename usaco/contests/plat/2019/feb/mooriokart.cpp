#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int mod = 1e9+7;
void add(ll& a, ll b) {a = (a+b)%mod;}
ll mul(ll a, ll b) {return a*b%mod;}
void mul2(ll& a, ll b) {a = a*b%mod;}
void sub(ll& a, ll b) {a = (a+mod-b)%mod;}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("mooriokart.in","r",stdin);
	freopen("mooriokart.out","w",stdout);

	int n, m, x1, y; cin >> n >> m >> x1 >> y;
	int k = n-m;
	int a, b, d;
	y = max(0,y-k*x1);
	vector<vector<pii>> adj(n);

	F0R(i,m) {
		cin >> a >> b >> d;
		adj[--a].pb({--b,d});
		adj[b].pb({a,d});
	}

	vector<int> comp;
	vector<bool> vis(n,false);
	auto c = [&](auto& c, int cur, int par)->void {
		comp.pb(cur);
		vis[cur] = true;
		for (pii x : adj[cur]) {
			if (x.f!=par) {c(c,x.f,cur);}
		}
	};
	
	map<int,int> dist;
	auto dfs = [&](auto& dfs, int rt, int cur, int par, int d)->void {
		if (cur>rt) {dist[d]++;}
		for (pii x : adj[cur]) {
			if (x.f!=par) {dfs(dfs,rt,x.f,cur,d+x.s);}
		}
	};
	
	vector<pii> dp(y+1,{0,0}); dp[0]={1,0};

	F0R(i,n) {
		if (!vis[i]) {
			comp.clear();
			c(c,i,i);
			dist.clear();
			for (int x : comp) {dfs(dfs,x,x,x,0);}
			vector<pii> nxt(y+1,{0,0});
			
			F0R(i,y+1) {
				for (auto it=dist.begin();it!=dist.end();it++) {
					int d = it->f; int ctr = it->s;
					int t = (d+i<y ? d+i : y);
					add(nxt[t].f,mul(dp[i].f,ctr));
					add(nxt[t].s,(mul((dp[i].s+mul(dp[i].f,d))%mod,ctr)));
				}
			}
			dp = nxt;
		}
	}

	ll build = mul(dp[y].f,k*x1);
	add(dp[y].s,build);
	FOR(i,1,k) {mul2(dp[y].s,2*i);}
	cout << dp[y].s << '\n';
}