#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("248.in","r",stdin);
	freopen("248.out","w",stdout);
	
	int n; cin >> n;
	int ans = 0;
	vector<vector<int>> range(n,vector<int>(n,0));
	F0R(i,n) {cin >> range[i][i]; ans = max(ans,range[i][i]);}
	
	FOR(i,1,n) {
		F0R(j,n-i) {
			F0R(k,i) {
				if (range[j][j+k]&&range[j+k+1][j+i]&&(range[j][j+k]==range[j+k+1][j+i])) {
					range[j][j+i] = range[j][j+k]+1;
				}
			} ans = max(ans,range[j][j+i]);
		}
	} cout << ans << '\n';
}