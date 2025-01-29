#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("shuffle.in","r",stdin);
	freopen("shuffle.out","w",stdout);

	int n; cin >> n;
	int pos[n], x, ans[n], prev[n];
	for (int i=0;i<n;i++) {cin >> pos[i]; pos[i]--;}
	for (int i=0;i<n;i++) {prev[pos[pos[pos[i]]]] = i;}
	for (int i=0;i<n;i++) {
		cin >> x;
		ans[prev[i]] = x;
	}
	for (int i : ans) {cout << i << '\n';}
}
