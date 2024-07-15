#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

vector<vector<int>> g;
pii mecho, home;
int n, s;
pii d[4] = {{0,1},{0,-1},{1,0},{-1,0}};

bool check(int t) {
	vector<vector<int>> dist(n+2,vector<int>(n+2,INT_MAX));
	dist[mecho.f][mecho.s] = t*s;
	queue<pii> q; q.push(mecho);
	
	while (q.size()) {
		pii cur = q.front(); q.pop();
		if (dist[cur.f][cur.s]>=g[cur.f][cur.s]) {continue;}
		for (pii y : d) {
			if (dist[cur.f+y.f][cur.s+y.s]==INT_MAX) {
				dist[cur.f+y.f][cur.s+y.s] = dist[cur.f][cur.s]+1;
				q.push({cur.f+y.f,cur.s+y.s});
			}
		}
	} return (dist[home.f][home.s]!=INT_MAX);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> s;
	g = vector<vector<int>>(n+2,vector<int>(n+2,INT_MAX));
	char c; queue<pii> q;
	F0R(i,n) {
		F0R(j,n) {
			cin >> c;
			if (c=='M') {mecho = {i+1,j+1}; g[i+1][j+1]=-1;}
			else if (c=='D') {home = {i+1,j+1};}
			else if (c=='H') {g[i+1][j+1]=0; q.push({i+1,j+1});}
			else if (c=='G') {g[i+1][j+1]=-1;}
			else if (c=='T') {g[i+1][j+1]=-2;}
		}
	}
	F0R(i,n+1) {g[0][i] = g[i][0] = g[n+1][i] = g[i][n+1] = -2;}
	while (q.size()) {
		pii x = q.front(); q.pop();
		for (pii y : d) {
			if (g[x.f+y.f][x.s+y.s]==-1) {
				g[x.f+y.f][x.s+y.s]=g[x.f][x.s]+s;
				q.push({x.f+y.f,x.s+y.s});
			}
		}
	}
	int l = 0, h = n*n, m = (l+h)/2, ans = -1;
	while (l <= h) {
		if (check(m)) {ans = m; l = m+1;}
		else {h = m-1;}
		m = (l+h)/2;
	} cout << ans << '\n';
} 	