#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back

int n;

int to_bin(string& s) {
	int ret = 0, pow = 1;
	for (int i=n-1; i>=0; i--) {
		ret += pow*(s[i]-'0'); pow *= 2;
	} return ret;
}

int ok(int a, int b) {
	for (int i=0;i<n;i++) {if ((b&(1<<i))&&(a&(1<<i))) {a^=(1<<i);}}
	return a;
}

void solve() {
	int m; cin >> n >> m;
	vector<vector<pii>> adj(1<<n);
	string s; cin >> s;
	int d, n1, n2; string s1, s2;
	int start = to_bin(s);

	for (int i=0;i<m;i++) {
		cin >> d >> s1 >> s2;
		int n1 = to_bin(s1), n2 = to_bin(s2);
		for (int j=0;j<(1<<n);j++) {adj[j].pb(mp(ok(j,n1)|n2,d));}
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(mp(0,start));
	vector<ll> dist((1<<n), LLONG_MAX); dist[start] = 0;

	while (pq.size()) {
		pii cur = pq.top(); pq.pop();
		if (dist[cur.s] != cur.f) {continue;}
		for (pii x : adj[cur.s]) {
			if (cur.f+x.s < dist[x.f]) {
				pq.push({dist[x.f]=cur.f+x.s,x.f});
			}
		}
	}
	cout << (dist[0]==LLONG_MAX ? -1 : dist[0]) << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {solve();}
}
