#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
	int n; cin >> n;
	int last = 0;
	v<bool> ans(n,false);
	FOR(i,1,n) { // query prefixes
		cout << "? 1" << ' ' << i+1 << endl;
		int cur; cin >> cur;

		if (cur>last) { // if answer is larger then there's a 1 here
			if (!last) {
				F0R(j,cur) {ans[i-j-1] = false;}
				F0R(j,i-cur) {ans[j] = true;}
			} ans[i] = true;
			last = cur;
		} else { // otherwise there's a 0 here, assuming we haven't gotten all 0's in queries so far
			if (last) {ans[i] = false;}
		}
	} 
	if (!last) {cout << "! IMPOSSIBLE" << endl;}
	else {
		cout << "! ";
		F0R(i,n) {cout << ans[i];} cout << endl;
	}
}

int main() {
    int t; cin >> t;
	while (t--) {solve();}
}