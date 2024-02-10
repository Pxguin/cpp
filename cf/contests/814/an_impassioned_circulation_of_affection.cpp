#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int q; cin >> q;
	int m; char c;
 
	while (q--) {
		cin >> m >> c;
		int num_painted = 0;
		int p1 = 0, p2 = 0;
		int ans = 0;
 
		while (p1 < n && p2 < n) {
			while (p2 < n) {
				if (s[p2] != c) {
					if (num_painted < m) {num_painted++;}
					else {break;}
				} 
				p2++;
			}
			ans = max(ans, p2-p1);
			num_painted -= (s[p1++] != c);
		}
 
		cout << ans << "\n";
	}
}