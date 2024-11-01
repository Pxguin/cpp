#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	freopen("teleport.in","r",stdin);
	freopen("teleport.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	vector<pii> p(n);
	F0R(i,n) {cin >> p[i].f >> p[i].s;}
	int x = 0;

	vector<int> val;
	auto func = [&](int a, int b, int tp)->void {
		if (abs(tp-a)>=(b-a)) {return;}
		if (tp<=a) {val.pb(a+a-tp); val.pb(b); val.pb(b+(b-a-(a-tp)));} 
		else {val.pb(tp); val.pb(b); val.pb(b+b-tp);}
	};
	ll cand = 0;
	vector<pii> events;
	F0R(i,n) {
		if (p[i].f>p[i].s) {
			func(-p[i].f,-p[i].s,-x);
			F0R(j,val.size()) {val[j]*=-1;}
			reverse(val.begin(),val.end());
		} else {func(p[i].f,p[i].s,x);}
		F0R(j,val.size()) {events.pb({val[j],j});}
		cand += abs(p[i].f-p[i].s);
		val.clear();
	} sort(events.begin(),events.end());
	
	ll ans = cand;
	ll delta[4] = {0,0,0,0};
	ll last = -1e9;
	for (pii cur : events) {
		cand += (cur.f-last)*(delta[2]-delta[1]);
		delta[cur.s]--; delta[cur.s+1]++;
		last = cur.f;
		chmin(ans,cand);
	} cout << ans << '\n';
}