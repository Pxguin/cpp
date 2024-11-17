#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n = 1000;
	string s;
	ll ans = 0;
	F0R(i,n) {
		cin >> s;
		v<int> num;
		for (char c : s) {
			if (c-'0'<40) {num.pb(c-'0');}
		}
		ans += (10LL*num[0])+num.back();
	} cout << ans << '\n';
}