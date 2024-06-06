#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;

	ll ans = 0; int n = s.size();
	ll ps[2019]={0}; int cur = 0; ps[0]=1;
	int exp = 1;
	for (int i=0;i<n;i++) {
		cur = (cur+(s[n-i-1]-'0')*exp) % 2019; ps[cur]++;
		exp = (exp*10)%2019;
	}
	for (int i=0;i<2019;i++) {
		ans += ps[i]*(ps[i]-1)/2;
	} cout << ans << '\n';
}
