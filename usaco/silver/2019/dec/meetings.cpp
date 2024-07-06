#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

struct Cow {
	int w, x, d;
	Cow (int w, int x, int d) : w(w), x(x), d(d) {};
	bool operator<(const Cow& y) {return (x<y.x);}
};

int main() {
	freopen("meetings.in","r",stdin);
	freopen("meetings.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n, l, w, p, d; cin >> n >> l;
	ll tot = 0; 
	vector<pii> cows;
	vector<Cow> a;
	F0R(i,n) {
		cin >> w >> p >> d;
		a.pb(Cow(w,p,d));
		tot += w;
	} tot = (tot+1)/2;
	sort(a.begin(),a.end());

	int ptr = 0;
	F0R(i,n) {
		if (a[i].d==-1) {cows.pb({a[i].x,a[ptr++].w});}
	} ptr = n-1;
	for (int i=n-1;i>=0;i--) {
		if (a[i].d==1) {cows.pb({l-a[i].x,a[ptr--].w});}
	}
	sort(cows.begin(),cows.end());
	ll cur = 0, t;
	F0R(i,n) {
		cur += cows[i].s;
		if (cur >= tot) {t = cows[i].f; break;}
	} int ans = 0;
	
	set<pii> neg; int idx = 0;
	F0R(i,n) {if (a[i].d==-1) {neg.insert({a[i].x,++idx});}}
	neg.insert({4*l,idx}); neg.insert({-1,0});
	for (int i=n-1;i>=0;i--) {
		if (a[i].d==1) {
			auto right = (--neg.upper_bound({a[i].x+2*t,100000}));
			auto left = (--neg.lower_bound({a[i].x,0}));
			ans += (right->s-left->s);
		}
	} cout << ans << '\n';
} 	