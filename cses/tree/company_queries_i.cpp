#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, q, a, b; cin >> n >> q;
	vector<vector<int>> adj(n);
	int mxdist = ceil(log2(n));
	vector<vector<int>> par(n,vector<int>(mxdist+1,-2));
	FOR(i,1,n,1) {cin >> par[i][0]; par[i][0]--;}
	FOR(i,1,mxdist+1,1) {
		F0R(j,n) {
			int half = par[j][i-1];
			par[j][i] = (half==-2 ? -2 : par[half][i-1]);
		}
	}
	auto kth_par = [&](int cur, int k) {
		F0R(i,mxdist+1) {
			if (k&(1<<i)) {
				cur = par[cur][i];
				if (cur==-2) {break;}
			}
		} return cur;
	};
	F0R(i,q) {
		cin >> a >> b;
		cout << kth_par(--a,b)+1 << '\n';
	}
}