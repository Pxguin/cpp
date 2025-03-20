#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

bool solve() {
	int n; cin >> n;
	v<ll> d(2*n);
	F0R(i,2*n) {cin >> d[i];}
	sort(d.begin(),d.end(),greater<>());
	
	if (d[0]%(2*n) || d[0]&1 || d[0]!=d[1]) {return false;} // conditions: is it divisible by 2n, is it even, is it distinct
	ll last = d[0]/2/n; // find the last element
	FOR(i,1,n) {
		if (d[2*i]!=d[2*i+1] || d[2*i]==d[2*i-2] || d[2*i]&1) {return false;} // check same conditions as above
		if ((d[2*i-2]-d[2*i])%(2*(n-i))!=0) {return false;} // is the difference divisible by 2i (n-i in code because array is reversed)
		last -= (d[2*i-2]-d[2*i])/(2*(n-i)); // if so, then find the next integer in a
		if (last<=0) {return false;} // make sure it's positive
	} return true; // if all these checks pass, then an array exists
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {cout << (solve() ? "YES" : "NO") << '\n';}
}