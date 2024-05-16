#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	while (n != 1) {
		cout << n << " ";
		if (n % 2) {n *= 3; n++;}
		else {n /= 2;}
	}
	cout << 1;
}
