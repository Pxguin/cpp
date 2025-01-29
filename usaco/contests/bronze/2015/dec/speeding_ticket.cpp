#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("speeding.in","r",stdin);
	freopen("speeding.out","w",stdout);
	int ans = 0;
	int n, m; cin >> n >> m;
	int sum = 0;
	int limit[101] = {0}, bessie[101] = {0};
	int l, s;
	for (int i=0;i<n;i++) {
		cin >> l >> s; 
		limit[sum] = s;
		sum += l;
	} 
	sum = 0;
	for (int i=0;i<m;i++) {
		cin >> l >> s;
		bessie[sum] = s;
		sum += l;
	}
	for (int i=0;i<100;i++) {
		if (limit[i]) {l = limit[i];}
		if (bessie[i]) {s = bessie[i];}
		ans = max(ans, s-l);
	}
	cout << ans << '\n';
}
