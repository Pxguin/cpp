#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int q; cin >> q;
	while (q--) {
		ll k; cin >> k;
		ll sum = 0, c = 9, i = 1, p = 1;
		while (k-sum>c*i) { // continue subtracting in bulk while possible
			sum += c*i;
			i++; c*=10; p*=10;
		}
		string dig = to_string((k-sum-1)/i+p); // num that kth digit is in
		cout << dig[(k-sum-1)%i] << '\n'; // get the actual kth digit
	}
}