#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int n, m, k; 
vector<pii> adj;
vector<int> to;
vector<bool> path;

void trav(int cur, int step, int src) {
	while (step!=m) {
		if (path[step]) {cur=adj[cur].f;}
		else {cur=adj[cur].s;}
		step++;
	} to[src] = cur;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("cruise.in","r",stdin);
	freopen("cruise.out","w",stdout);

	char c; cin >> n >> m >> k;
	adj.resize(n); to.resize(n); path.resize(m);
	F0R(i,n) {cin >> adj[i].f >> adj[i].s;}
	F0R(i,n) {adj[i].f--; adj[i].s--;}
	F0R(i,m) {cin >> c; path[i] = (c=='L');}

	F0R(i,n) {trav(i,0,i);} // ioi?

	vector<int> len(n,0); // find cycle
	int cur = 0, step = 0;
	while (!len[cur]) {
		len[cur] = ++step; 
		cur = to[cur];
	}
	if (len[cur]-1>k) {cur=0;} // find answer
	else {k = (k-len[cur]+1)%(step-len[cur]+1);}
	F0R(i,k) {cur = to[cur];}
	cout << cur+1 << '\n';
}