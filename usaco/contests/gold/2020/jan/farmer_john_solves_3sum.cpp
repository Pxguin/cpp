#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("threesum.in","r",stdin);
	freopen("threesum.out","w",stdout);

	int n, q; cin >> n >> q;
	int mx = 1e6;
	vector<int> a(n);
	F0R(i,n) {cin >> a[i];}
	vector<vector<ll>> ans(n,vector<ll>(n,0));
	vector<int> freq(2*1000000,0);
	F0R(i,n-2) {
		FOR(j,i+2,n) {
			freq[a[j-1]+mx]++;
			if (abs(a[i]+a[j])<=1000000) {ans[i][j] = freq[-(a[i]+a[j])+mx];}
		} FOR(j,i+2,n) {freq[a[j-1]+mx]--;}
	}
	FOR(i,2,n) { // sz of range
		F0R(j,n-i) {
			ans[j][j+i] += ans[j+1][j+i]+ans[j][j+i-1]-ans[j+1][j+i-1];
		}
	} 
	while (q--) {
		int a, b; cin >> a >> b;
		cout << ans[--a][--b] << '\n';
	}
}