#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define sz(x) int((x).size())

const ld pi = acos(-1);

struct Circle {
	int x, y, r; 
	Circle (int x1, int y1, int r1) : x(x1), y(y1), r(r1) {};
	bool operator<(const Circle& z) {return r < z.r;}
};

vector<vector<int>> adj;
vector<Circle> d;
vector<vector<ld>> dp(4); 

void dfs(int cur) {
	ld a = pi*d[cur].r*d[cur].r;
	ld nxt[4] = {0,0,0,0};

	for (int x : adj[cur]) {
		dfs(x);
		F0R(i,4) {nxt[i] += dp[i][x];}
	}

	// even even / odd odd, switching to even odd & odd even
	F0R(i,2) {dp[i][cur] = max(nxt[2]-a,nxt[3]+a);}
	
	// even odd / odd even, switching to even even & odd odd
	F0R(i,2) {dp[2][cur] = nxt[i]+a;}
	F0R(i,2) {dp[3][cur] = nxt[i]-a;}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	int x1, y1, r1;
	F0R(i,n) {
		cin >> x1 >> y1 >> r1;
		d.pb(Circle(x1,y1,r1));
	} sort(d.begin(),d.end());
	adj.resize(n);
	
	auto ok = [&](const Circle& a, const Circle& b) {
		return ((a.x+a.r)<=(b.x+b.r) && (a.x-a.r)>=(b.x-b.r) && (a.y+a.r)<=(b.y+b.r) && (a.y-a.r)>=(b.y-b.r));
	}; 
	F0R(i,4) {dp[i]=vector<ld>(n,LLONG_MIN);}
	ld ans = 0;
	F0R(i,n) {
		bool flag = true;
		FOR(j,i+1,n,1) {
			if (ok(d[i],d[j])) {adj[j].pb(i); flag = false; break;}
		}
		if (flag) {dfs(i); ans += dp[2][i];}
	} 
	// max given 4 states: odd even / even odd / even even / odd odd
	cout << fixed << setprecision(8) << ans << '\n';
}
