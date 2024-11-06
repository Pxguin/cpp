#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)

int ans = 1e9;
vector<pii> best;
vector<pii> cur;
vector<int> to = {0,0,0};

void test(vector<int> a, vector<int> b, int msg) {
	int third = -1;
	auto pour = [&](int t1, int t2)->void {
		t1--; t2--;
		if (t2==2) {third = (t1 ? b.back() : a.back());}
		if (t1==0) {a.pop_back();}
		else if (t1==1) {b.pop_back();}
		cur.pb({to[t1],to[t2]});
	};
	// if a has size 1, don't do anything
	if (a.size()!=1) {pour(1,(a.back()!=b.back())+2);} // otherwise, pour into 2 if it's possible, else 3
	if (msg) {swap(to[0],to[1]); swap(a,b);} // you can either empty b or empty a
	while (a.size()>1) {pour(1,(a.back()!=b.back())+2);} // empty a, while it has size>1 then add it to tubes 2 or 3
	if (third==a.back()) {pour(3,1); third = -1;} // pour tube 3 into tube 1 if possible
	while (b.size()>1) {pour(2,(b.back()!=a.back())*2+1);} // empty 2 into tubes 1 or 3
	if (b.back()==a.back()) {pour(2,1);} // pour 2 into 1 if possible
	if (third!=-1) {pour(3,2);} // pour tube 3 back into 2 if possible
	
	if (cur.size()<ans) {ans = cur.size(); best = cur;}
	cur.clear();
}

void solve() {
	int n, p; cin >> n >> p;
	char c;
	vector<vector<int>> t(2);
	F0R(i,2) {
		char last = 'e';
		F0R(j,n) {
			cin >> c;
			if (c!=last) {t[i].pb(c=='1');}
			last = c;
		}
	}
	to = {0,1,2}; test(t[0],t[1],0);
	to = {0,1,2}; test(t[0],t[1],1);
	to = {1,0,2}; test(t[1],t[0],0);
	to = {1,0,2}; test(t[1],t[0],1);
	cout << ans << '\n';
	if (p!=1) {
		for (pii x : best) {cout << x.f+1 << ' ' << x.s+1 << '\n';}
	} ans = 1e9;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}