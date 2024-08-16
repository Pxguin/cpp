#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

void solve() {
	int n, k, c; cin >> n >> c >> k;
	char t;
	vector<int> a(n);
	F0R(i,n) {cin >> t; a[i] = t-'A';}
	vector<vector<int>> ps(c,vector<int>(n+1,0));
	vector<int> bit(1<<c);
	int last = a[n-1];
	F0R(i,n) {
		ps[a[i]][i+1] = 1;
		F0R(j,c) {ps[j][i+1] += ps[j][i];} 
	} 
	F0R(i,n+1-k) {
		int cur = 0;
		F0R(j,c) {
			cur |= (ps[j][i]!=ps[j][i+k] ? (1<<j) : 0);
		} bit[cur] = true;
	}

	F0R(mask,1<<c) {
		if (bit[mask]) {
			F0R(j,c) {bit[mask|(1<<j)]=true;}
		}
	} int ans = c;
	F0R(mask,1<<c) {
		if (!bit[mask^((1<<c)-1)] && (1<<last)&mask) {ans = min(ans,__builtin_popcount(mask));}
	} cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
} 