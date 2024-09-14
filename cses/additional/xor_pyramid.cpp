#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, x; cin >> n;
	int ans = 0;
	F0R(i,n) {
		cin >> x; 
		if (!(i&(n-1-i))) {ans ^= x;}
	} cout << ans << '\n';
}