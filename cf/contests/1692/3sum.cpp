#include <bits/stdc++.h>
using namespace std;

bool solve() {
	int n; cin >> n;
	int a[10]={0}; int a1;
	for (int i=0;i<n;i++) {cin >> a1; a[a1%10]++;}
	for (int i=0;i<10;i++) {
		for (int j=i;j<10;j++) {
			if (((i==j)&&(a[i]>1)) || ((i!=j)&&a[i]&&a[j])) {a[i]--; a[j]--;}
			else {continue;}
			if (a[(23-i-j)%10]) {return true;}
			a[i]++; a[j]++;
		}
	} return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {cout << (solve() ? "YES\n" : "NO\n");}
}
