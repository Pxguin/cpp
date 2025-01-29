#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("berries.in","r",stdin);
	freopen("berries.out","w",stdout);
	
	int n, k; cin >> n >> k; k /= 2;
	int b[n];
	F0R(i,n) {cin >> b[i];}

	int ans = 0;
	FOR(i,1,1001) {
		vector<int> mod(1001,0);
		int taken = 0;
		F0R(j,n) {mod[b[j]%i]++; taken += (b[j]/i);}
		if ((taken -= k) < 0) {break;}
		int cur = taken*i, left = k-taken;
		for (int j=1001;j>=0;j--) {
			cur += min(mod[j],left)*j;
			left -= mod[j];
			if (left<=0) {break;}
		} ans = max(ans, cur);
	} cout << ans << '\n';
}