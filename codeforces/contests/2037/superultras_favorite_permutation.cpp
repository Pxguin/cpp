#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	if (n<=4) {cout << -1 << '\n'; return;} // if N<5 then it doesn't work

	for (int i=1;i<=n;i+=2) { // get all odd numbers
		if (i!=5) {cout << i << ' ';}
	} cout << 5 << ' ' << 4; // midpoint: 5+4
	for (int i=2;i<=n;i+=2) { // get all even numbers
		if (i!=4) {cout << ' ' << i;}
	} cout << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}