#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; ll m; cin >> n >> m;
	vector<ll> a(n);
	F0R(i,n) {cin >> a[i];}

	vector<ll> ss(2e5+2,0);
	vector<ll> ss2(2e5+2,0);
	F0R(i,n) {ss[a[i]]++; ss2[a[i]]+=a[i];}
	for (int i=1e5;i>=0;i--) {ss[i] += ss[i+1];}
	for (int i=1e5;i>=0;i--) {ss2[i] += ss2[i+1];}

	ll ans = 0;
	ll l=2,h=2*1e5,mid=(l+h)/2;
	while (l<=h) {
		ll cand = 0, tot = 0;
		F0R(i,n) {
			tot += ss[max(0LL,mid-a[i])];
			cand += ss2[max(0LL,mid-a[i])];
			cand += a[i]*ss[max(0LL,mid-a[i])];
		}
		if (tot>=m) {ans = cand-(mid*(tot-m)); l = mid+1;}
		else {h = mid-1;}
		mid = (l+h)/2;
	} cout << ans << '\n';
}