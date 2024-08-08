#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int l = 1, h = 999, m = (l+h)/2;
		int a;
		while (l<h) {
			cout << "? 1 " << m << endl;
			cin >> a;
			if (a==m) {l = m+1;}
			else {h = m;}
			m = (l+h)/2;
		} cout << "! " << m << endl;
	}
} 