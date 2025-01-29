#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector<pii> a(n);
	F0R(i,n) {cin >> a[i].f >> a[i].s;}
	sort(a.begin(),a.end(),[&](pii& x, pii& y) {return x.s<y.s;});
	
	ll ans = 0;
	auto doit = [&](bool flag)->void {
		F0R(i1,n) {
			FOR(i2,i1+1,n) {
				ll mx = -2e9, mn = 2e9;
				ll c1 = a[i1].f, c2 = a[i2].f;
				if (c1>c2) {swap(c1,c2);}
				
				auto change = [&](pii cand) {
					if (cand.f<c1) {chmax(mx,cand.f);}
					if (cand.f>c2) {chmin(mn,cand.f);}
				};
				FOR(c,i1+1,i2) {change(a[c]);}
				ll tmx = mx, tmn = mn;

				vector<pii> mins = {{mx,mn}}; // precalc to find the closest cows (left and right) to the rectangle
				vector<int> idx = {i2};
				FOR(c,i2+1,n) {
					if (a[c].f>c1&&a[c].f<c2) {
						mins.pb({mx,mn}); 
						idx.pb(c);
					} else {change(a[c]);}
				}

				auto check = [&](int x, int y) { // checks that a valid square is possible
					tmx = max(mx,mins[y].f), tmn = min(mn,mins[y].s);
					return (tmn-tmx-2 < a[idx[y]].s-a[x].s);
				};
				auto check2 = [&](int x, int y) { // checks that H>W (or H>=W)
					if (!flag) {return a[idx[y]].s-a[x].s>=c2-c1;}
					else {return a[idx[y]].s-a[x].s>c2-c1;}
				};

				mx = tmx; mn = tmn;
				int p1 = mins.size()-1, p2 = p1;
				for (int i=i1;i>=0;i--) {
					if (a[i].f>=c1&&a[i].f<=c2) {
						while (p1>=0 && check(i,p1)) {p1--;} // p1 = which cows such that a square is possible
						while (p2>=0 && check2(i,p2)) {p2--;} // p2 = which cows such that H>W
						if (p1>=max(0,p2) && p2!=mins.size()-1) {ans += p1-p2;} // everything between p1 and p2 is valid
					} else {change(a[i]);}
				}
			}
		} 
	};
	doit(false);
	sort(a.begin(),a.end());
	F0R(i,n) {swap(a[i].f,a[i].s);}
	doit(true);
	ans += n+1;
	cout << ans << '\n';
}