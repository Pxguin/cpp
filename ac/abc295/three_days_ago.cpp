#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	ll states[1<<10] = {0}; states[0] = 1;
	vector<bool> sum(10, false);
	for (char a : s) {
		int x = (int)a-48;
		sum[x] = !sum[x];
		int res = 0;
		for (int i=0;i<10;i++) {
			if (sum[i]) {res|=(1<<i);}
		}
		states[res]++;
	}
	ll ans = 0;
	for (int i=0;i<(1<<10);i++) {ans += states[i]*(states[i]-1)/2;}
	cout << ans << '\n';
}
