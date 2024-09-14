#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (double i = (a); i < (b); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	double n, k; cin >> n >> k;
	double ans = 0;
	FOR(j,1,k+1) {
		ans += (pow(j/k,n)-pow((j-1)/k,n))*j;
	}
	cout << fixed << setprecision(6) << ans << '\n';
}
