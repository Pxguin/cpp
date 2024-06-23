#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define sz(x) int((x).size())

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a,b;
	vector<int> x[2],y[2];
	F0R(i,n) {
		cin >> a >> b; 
		if ((a+b)&1) {y[1].pb(a+b); x[1].pb(a-b);}
		else {y[0].pb(a+b); x[0].pb(a-b);}
	}
	ll ans = 0;
	F0R(i,2) {
		sort(x[i].begin(),x[i].end()); sort(y[i].begin(),y[i].end());
		ll sum = 0, sum1 = 0, cur = 0;
		FOR(j,1,sz(x[i]),1) {sum += x[i][j-1]; cur += (x[i][j]*(ll)j)-sum;}
		FOR(j,1,sz(y[i]),1) {sum1 += y[i][j-1]; cur += (y[i][j]*(ll)j)-sum1;}
		ans += cur/2;
	} cout << ans << '\n';
}
