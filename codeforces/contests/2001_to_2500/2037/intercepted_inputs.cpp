#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
	int k; cin >> k;
	v<int> a(k), f(k+1,0);
	F0R(i,k) {cin >> a[i]; f[a[i]]++;}
	
	k -= 2;
	F0R(i,k+1) {
		f[a[i]]--; // subtract to deal with N=M edge case, add back later
		if (k%a[i]==0 && f[k/a[i]]>0) { // if you find a valid N,M pair
			cout << a[i] << ' ' << k/a[i] << '\n';
			return;
		} f[a[i]]++;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}