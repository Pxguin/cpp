#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, c; cin >> c >> n;
	char cow;
	int team;
	int t[n];
	vector<int> ans(1<<c,INT_MAX);
	for (int i=0;i<n;i++) {
		team = 0;
		for (int j=1;j<c+1;j++) {
			cin >> cow;
			if (cow == 'G') {team += (1 << (c-j));}
		}
		t[i] = team;
		ans[team] = 0;
	}

	for (int bit=0;bit<c;bit++) {
		for (int mask=0;mask<(1<<c);mask++) {
			int inv = mask^(1<<bit);
			if (ans[inv] != INT_MAX) {
				ans[mask] = min(ans[mask], ans[inv]+1);
			}
		}
	}
	for (int mask : t) {
		int inv = mask^((1<<c)-1);
		cout << c-ans[inv] << "\n";
	}

}
