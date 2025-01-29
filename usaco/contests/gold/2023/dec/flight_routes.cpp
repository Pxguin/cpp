#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	char c;
	vector<vector<bool>> flights(n,vector<bool>(n));
	F0R(i,n) {
		F0R(j,n-i-1) {
			cin >> c;
			flights[i][j+i+1] = (c=='1');
		}
	}
	vector<vector<int>> adj(n);
	int ans = 0;
	for (int i=n-1;i>=0;i--) {
		vector<int> val(n,0);
		FOR(j,i+1,n) {
			if (flights[i][j]!=val[j]) {
				adj[i].pb(j); ans++;
			} val[j] = flights[i][j];
			for (int x : adj[j]) {
				val[x] ^= val[j];
			}
		}
	} cout << ans << '\n';
}