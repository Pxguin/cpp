#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define pii pair<double,double>
#define mp make_pair
#define f first
#define s second

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, d; cin >> n >> d;
	pii a[n];
	F0R(i,n) {cin >> a[i].f >> a[i].s; a[i].s=abs(a[i].s);}
    
	auto check = [&](double m)->bool {
		double prev = 0;
		F0R(i,n) {
			double dist = sqrt(m*m-(a[i].s)*(a[i].s));
			double x1 = a[i].f-dist, x2 = a[i].f+dist;
			if (x1 < prev) {prev = max(prev,x2);}
		} return (d>=prev);
	};
	
	double l = 0, h = 1e9*3, m = (l+h)/2;
	double ans;
	cout << fixed << setprecision(4);
	while (l <= h-1e-4) {
		if (check(m)) {
			l = m; ans = m;
		} else {h = m;}
		m = (l+h)/2;
	}
	cout << ans << '\n';
}