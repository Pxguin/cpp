#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, s, q, v; cin >> n >> s;
	s--;
	vector<int> target(n,-1),jump(n,-1);
	vector<int> last(n,INT_MAX);
	F0R(i,n) {
		cin >> q >> v;
		if (!q) {jump[i]=v;}
		else {target[i]=v;}
	}
	int ans = 0;
	v = 1;
	while (true) {
		if (s<0||s>=n) {break;}
		if (target[s]>=0 && target[s]<=abs(v)) {target[s]=-1; ans++;}
		else if (jump[s]>=0) {
			if (jump[s]==0&&last[s]==v) {break;}
			last[s] = v;
			v += (v>0?1:-1)*jump[s]; v*=-1;
		}
		s += v;
	} cout << ans << '\n';
}