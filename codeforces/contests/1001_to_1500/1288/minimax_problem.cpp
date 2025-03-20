#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n,vector<int>(m));
	F0R(i,n) {
		F0R(j,m) {cin >> a[i][j];}
	}
	pii ans;
	auto check = [&](int mid)->bool {
		vector<int> idx((1<<m),-1);
		vector<int> bitmask(n);
		F0R(i,n) {
			int mask = 0;
			F0R(j,m) {if (a[i][j] >= mid) {mask |= (1<<j);}}
			idx[mask] = i; bitmask[i] = mask;
		}
		for (int i=(1<<m)-1;i>=0;i--) {
			if (idx[i] != -1) {
				F0R(j,m) {
					if (i&(1<<j)) {idx[i^(1<<j)]=idx[i];}
				}
			}
		}
		F0R(i,n) {
			int inv = bitmask[i]^((1<<m)-1);
			if (idx[inv] != -1) {ans = {idx[inv]+1,i+1}; return true;}
		}
		return false;
	};
	int l = 0, h = 1e9, mid = (l+h)/2;
	while (l <= h) {
		if (check(mid)) {l = mid+1;}
		else {h = mid-1;}
		mid = (l+h)/2;
	} 
	cout << ans.f << ' ' << ans.s << '\n';
} 	