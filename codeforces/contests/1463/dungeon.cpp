#include <bits/stdc++.h>
using namespace std;

bool solve() {
	int a[3]; cin >> a[0] >> a[1] >> a[2];
	sort(a,a+3);
	int dmg = (a[2]-a[0])+(a[1]-a[0]); 
	if (dmg%6==3) {dmg+=3; a[0]--;}
	a[0] -= dmg/6;
	return (a[0] >= 0 && a[0]%3==0 && dmg%6==0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {cout << (solve() ? "YES\n" : "NO\n");}
}
