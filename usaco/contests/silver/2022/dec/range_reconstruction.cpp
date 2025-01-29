#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector<vector<int>> r(n,vector<int>(n));
	F0R(i,n) {
		F0R(j,n-i) {cin >> r[i][j];}
	}
	vector<int> ans = {1};

	auto does_it_work = [&]()->bool {
		int idx = ans.size();
		F0R(i,idx) {
			int mn = 2e9, mx = -2e9;
			FOR(j,i,idx) {
				chmin(mn,ans[j]);
				chmax(mx,ans[j]);
			} if (mx-mn!=r[i][idx-i-1]) {return false;}
		} return true;
	};

	FOR(i,1,n) {
		ans.pb(ans.back()+r[i-1][1]);
		if (!does_it_work()) {ans.back() -= 2*r[i-1][1];}
	}
	F0R(i,n-1) {cout << ans[i] << ' ';}
	cout << ans[n-1] << '\n';
}