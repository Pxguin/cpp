#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int l = 1, h = 999, m1 = l+(h-l)/3, m2 = h-(h-l)/3, a;
		while (l<h) {
			cout << "? " << m1 << ' ' << m2 << endl;
			cin >> a;
			if (a == m1*(m2+1)) {h = m2; l = m1+1;}
			else if (a == m1*m2) {l = m2+1;}
			else {h = m1;}
			m1 = l+(h-l)/3, m2 = h-(h-l)/3;
		} cout << "! " << m1 << endl;
	}
}