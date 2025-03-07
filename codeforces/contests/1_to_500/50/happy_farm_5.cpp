#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ll long long
#define ld long double

pii start = mp(INT_MAX, INT_MAX);

int z(const pii& a, const pii& b, const pii& c) {
	ll val = (ll)(b.s-a.s)*(c.f-a.f)-(ll)(b.f-a.f)*(c.s-a.s);
	if (val) {return (val > 0 ? 1 : -1);} // -1: p2 is counterclockwise from p1
	return 0;
}

ll dist(const pii& a, const pii& b) {
	return (ll)(b.f-a.f)*(b.f-a.f)+(ll)(b.s-a.s)*(b.s-a.s);
}

bool cmp(const pii& a, const pii& b) {
	if (a == b) {return false;}
	int o = z(start, a, b);
	if (!o) {return (dist(start,a)<=dist(start,b));}
	return (--o);
}

pii nxt(stack<pii>& s1) {
	pii a = s1.top(); s1.pop(); 
	pii b = s1.top();
	s1.push(a); return b;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int a, b;
	vector<pii> points;
	for (int i=0;i<n;i++) {
		cin >> a >> b;
		points.pb(mp(a,b+1)); points.pb(mp(a,b-1));
		points.pb(mp(a-1,b)); points.pb(mp(a+1,b));
		if (b-1 < start.s || (b-1==start.s && a < start.f)) {start = mp(a,b-1);}
	}
	sort(points.begin(), points.end(), cmp);

	stack<pii> stack1;
	for (int i=0;i<4*n;i++) {
		while (stack1.size()>1 && z(nxt(stack1),stack1.top(),points[i]) > 0) {
			stack1.pop();
		} 
		if (stack1.empty() || (stack1.size()&&stack1.top()!=points[i])) {stack1.push(points[i]);}
	}

	vector<pii> hull;
	while (stack1.size()) {hull.pb(stack1.top()); stack1.pop();}
	hull.pb(hull[0]);

	ll ans = 0;
	for (int i=0;i<hull.size()-1;i++) {
		ll x = abs(hull[i+1].f-hull[i].f), y = abs(hull[i+1].s-hull[i].s);
		ans += max(x,y);
	}
	cout << ans << '\n';
}
