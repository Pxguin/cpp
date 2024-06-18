#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define sz(x) int((x).size())

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m, k; cin >> n >> m >> k; k *= 2;
	pii c[n]; vector<int> a1, b1;
	F0R(i,n) {cin >> c[i].f;}
	int sz1; cin >> sz1; a1.resize(sz1); 
	F0R(i,sz1) {cin >> a1[i]; c[--a1[i]].s++;}
	cin >> sz1; b1.resize(sz1);
	F0R(i,sz1) {cin >> b1[i]; c[--b1[i]].s++;}

	priority_queue<int,vector<int>,greater<int>> a, b, u;
	set<pii> t; int r = m;
	int cur = 0, cur2 = 0; ll sum = 0;
	vector<int> used;
	for (int i : a1) {
		if (c[i].s==1) {a.push(c[i].f);} 
		else if (c[i].s==2) {u.push(c[i].f);}
	} 
	for (int i : b1) {if (c[i].s==1) {b.push(c[i].f);}}
	F0R(i,n) {if (c[i].s==0) {t.insert({c[i].f,r--});}}
	while (cur < k-1 && cur2 < m && sz(u)) {
		cur += 2; cur2++; sum += u.top();
		used.pb(u.top()); u.pop();
	}
	while (sz(a) && sz(b) && cur < k-1 && cur2 < m-1) {
		cur += 2; cur2 += 2; sum += a.top()+b.top();
		a.pop(); b.pop();
	}
	auto a2 = a, b2 = b;
	auto add = [&](auto& x) {while (sz(x)) {t.insert({x.top(),r--}); x.pop();}};
	t.insert({0,m+1}); t.insert({1e16,m+2}); t.insert({0,m+3}); t.insert({1e16,m+4});
	add(a); add(b); add(u);
	a = a2; b = b2;
	int l = m-k+sz(used);
	auto it = next(t.begin());
	ll ans = sum, sum2 = 0;

	auto calc = [&]() {
		if (l == 0) {return;}
		F0R(i,l) {it = next(it); sum2 += it->f;} 
		ans = sum2+sum;
		auto remove = [&](int x) {
			if (x <= it->f) {
				it = next(it);
				sum2 -= x; sum2 += it->f;
				t.erase(t.lower_bound({x,-1}));
			}
		};
		while (sz(a) && sz(b) && cur2 < m && sz(used)) {
			int x = used.back(), cand = a.top()+b.top();
			sum2 -= it->f; it = prev(it);
			sum += cand-x; cur2++;
			used.pop_back();
			// insert x (upd sum2)
			if (x <= it->f) {
				sum2 -= it->f; sum2 += x;
				it = prev(it); t.insert({x,r--});
			}
			// remove a, remove b (upd sum2)
			remove(a.top()); remove(b.top());
			a.pop(); b.pop();
			ans = min(ans, sum2+sum);
		}
	};
	calc(); 
	cout << (ans==LLONG_MAX||cur<k ? -1 : ans) << '\n';
}
