#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s; cin >> s;
	int n = 0; vector<char> l;
	int adj[26][26] = {0};
	bool vis[26] = {false};
	F0R(i,s.length()) {
		if (!vis[s[i]-'a']) {
			vis[s[i]-'a'] = true; 
			n++; 
			l.pb(s[i]);
		} adj[s[i-1]-'a'][s[i]-'a'] += (bool)i;
	}
	vector<int> dp((1<<n),INT_MAX); dp[0] = 1;

	F0R(mask,(1<<n)) {
		F0R(i,n) {
			if (!(mask&(1<<i))) {
				int cnt = dp[mask]+adj[l[i]-'a'][l[i]-'a'];
				F0R(j,n) {
					if (mask&(1<<j)) {
						cnt += adj[l[i]-'a'][l[j]-'a'];	
					} 
				} dp[mask|(1<<i)] = min(dp[mask|(1<<i)],cnt);
			}
		}
	}
	cout << dp[(1<<n)-1] << '\n';
} 	