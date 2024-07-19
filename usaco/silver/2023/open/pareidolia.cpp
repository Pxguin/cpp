#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	string s; cin >> s;
	int n = s.size();

	ll ans = 0;
	vector<ll> cnt(n+1,0);
	vector<int> e(n+1,n);
	char bessie[6] = {'b','e','s','s','i','e'};
	int last[6] = {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,1000000000};
	for (int i=n-1;i>=0;i--) {
		if (s[i]=='e') {last[5]=i;}
		F0R(j,6) {
			if (s[i]==bessie[j] && last[j]!=INT_MAX) {
				if (!j) {e[i] = last[j];}
				else {last[j-1] = min(last[j-1],last[j]);}
				last[j] = INT_MAX; 
			}
		}
		if (e[i]!=n) {cnt[i] = cnt[e[i]+1]+(n-e[i]);}
		else {cnt[i] = cnt[i+1]; e[i] = e[i+1];} 
		ans += cnt[i];
	} cout << ans << '\n';
}