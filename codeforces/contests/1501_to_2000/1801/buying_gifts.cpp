#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)

void solve() {
	int n; cin >> n;
	vector<pii> a(n), b(n);
	F0R(i,n) {cin >> a[i].f >> b[i].f;}
	F0R(i,n) {a[i].s = b[i].s = i;}

	int lb = 0;
	F0R(i,n) {chmax(lb,min(a[i].f,b[i].f));}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	int ans = INT_MAX;
	auto do_it = [&]() {
		for (int i=n-1;i>=0;i--) {
			auto it = upper_bound(b.begin(),b.end(),mp(a[i].f,n));
			if (it==b.begin() || a[i].f<lb) {break;}
			it--;
			if (it->s==a[i].s) {
				if (it==b.begin()) {continue;}
				it--;
			} chmin(ans,a[i].f-it->f);
		}
	}; 
	do_it();
	swap(a,b);
	do_it();
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
}