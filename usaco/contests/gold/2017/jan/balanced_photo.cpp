#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	freopen("bphoto.in","r",stdin);
	freopen("bphoto.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	pii a[n]; int b[n];
	F0R(i,n) {cin >> a[i].f; a[i].s=i;}
	F0R(i,n) {b[i] = a[i].f;}
	sort(a,a+n); a[0].f=0;
	FOR(i,1,n,1) {a[i].f = a[i-1].f+(a[i].f>b[a[i-1].s]);}
	sort(a,a+n,[&](const pii& x, const pii& y) {return x.s < y.s;});

	vector<int> bit(n+2,0), bit2(n+2,0);
	auto add = [&](int idx, vector<int>& fenwick) {
		for (++idx;idx<=n;idx+=idx&-idx) {fenwick[idx]++;}
	};
	auto sum = [&](int idx, vector<int>& fenwick) {
		int ret = 0;
		for (++idx;idx>0;idx-=idx&-idx) {ret+=fenwick[idx];}	
		return ret;
	};
	int l[n],r,ans=0;
	for (int i=n-1;i>=0;i--) {
		l[i] = (n-1)-i-sum(a[i].f,bit);
		add(a[i].f,bit); 
	} 
	F0R(i,n) {
		r = i-sum(a[i].f,bit2);
		add(a[i].f,bit2);
		ans += (l[i]>r*2 || r>l[i]*2);
	}
	cout << ans << '\n';
} 	
