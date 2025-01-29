#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, k; char c; cin >> n >> k;
	vector<int> a(n);
	vector<vector<pii>> near(n,vector<pii>(k));
	F0R(i,n) {cin >> a[i]; a[i]--;}

	vector<int> last(k,-1);
	F0R(i,n) {
		F0R(j,k) {near[i][j].f = last[j];}
		last[a[i]] = i;
	} last.assign(k,-1);
	for (int i=n-1;i>=0;i--) {
		F0R(j,k) {near[i][j].s = last[j];}
		last[a[i]] = i;
	}
	vector<vector<bool>> ok(k,vector<bool>(k));
	F0R(i,k) {F0R(j,k) {cin >> c; ok[i][j]=(c=='1');}}
	
	priority_queue<pli,vector<pli>,greater<pli>> pq;
	vector<ll> dist(n,LLONG_MAX); dist[0] = 0; pq.push({0,0});

	auto test = [&](int& cur, int& idx) {
		if (ok[a[cur]][a[idx]] && dist[cur]+abs(cur-idx) < dist[idx]) {
			pq.push({dist[idx]=dist[cur]+abs(cur-idx),idx}); 
			ok[a[idx]][a[idx]] = true;
		}
	};

	while (pq.size()) {
		pli cur = pq.top(); pq.pop();
		if (dist[cur.s]!=cur.f) {continue;}
		F0R(i,k) {
			if (near[cur.s][i].f != -1) {test(cur.s,near[cur.s][i].f);}
			if (near[cur.s][i].s != -1) {test(cur.s,near[cur.s][i].s);}
		}
	} cout << (dist[n-1]==LLONG_MAX ? -1 : dist[n-1]) << '\n';
}