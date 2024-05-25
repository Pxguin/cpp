#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int a[n];
	int ok[1001] = {0};
	for (int i=0;i<n;i++) {cin >> a[i]; ok[a[i]]=i+1;}

	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			if (a[i]+a[j]<=1000 && ok[a[i]+a[j]]) {
				cout << ok[a[i]+a[j]] << ' ' << i+1 << ' ' << j+1 << '\n'; 
				return 0;
			}
		}
	}
	cout << -1 << '\n';
}
