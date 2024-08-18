#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("piepie.in","r",stdin);
	freopen("piepie.out","w",stdout);
	
	int n, d; cin >> n >> d;
	vector<pii> pies(2*n);
	F0R(i,n) {cin >> pies[i].f >> pies[i].s;}
	F0R(i,n) {cin >> pies[i+n].s >> pies[i+n].f;}

	queue<int> q;
	set<pii> left_b, left_e;
	vector<int> dist(2*n,INT_MAX);
	F0R(i,2*n) {
		if (!pies[i].s) {dist[i]=0; q.push(i);}
		else {
			if (i<n) {left_b.insert({pies[i].s,i});}
			else {left_e.insert({pies[i].s,i});}
		}
	}

	auto add = [&](int cur, set<pii>& s)->void {
		auto it = s.lower_bound({pies[cur].f-d,-1});
		while (it != s.end()) {
			if (it->f>pies[cur].f) {break;}
			dist[it->s] = dist[cur]+1;
			q.push(it->s);
			s.erase(it++);
		}
	};

	while (q.size()) {
		int cur = q.front(); q.pop();
		if (cur<n) {add(cur,left_e);}
        else {add(cur,left_b);}
	}
	F0R(i,n) {cout << (dist[i]==INT_MAX ? -1 : dist[i]+1) << '\n';}
}