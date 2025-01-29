#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)

void solve() {
	int n; cin >> n;
	vector<int> h(n-1);
	set<int> rem;
	vector<int> c(n+1,0);
	F0R(i,n) {rem.insert(i+1);}
	F0R(i,n-1) {
		cin >> h[i]; 
		if (rem.count(h[i])) {rem.erase(h[i]);} // NlogN part
		else {c[h[i]]++;}
	} vector<int> ans(n,0);

	int flag = 0;
	F0R(i,n) {c[n] += (c[i]);} // testing if there are at least N-2 distinct values
	flag |= (c[n]>1);

	if (rem.size()==1) { // if there N-1 distinct values then one endpoint is the last element in H
		ans[0] = *rem.begin(); 
		ans[n-1] = h.back();
		if (*rem.begin()>h.back()) {swap(ans[0],ans[n-1]);}
	} else { // if there are N-2 distinct values then endpoints are the ones missing from H
		ans[0] = *rem.begin(), 
		ans[n-1] = *rem.rbegin();
	}
	int l = 0, r = n-1;
	F0R(i,n-1) {
		if (ans[l]<ans[r]) {
			flag |= (ans[r-1]&&ans[r-1]!=h[i]); // if a contradiction
			ans[--r] = h[i];
		} else {
			flag |= (ans[l+1]&&ans[l+1]!=h[i]);
			ans[++l] = h[i];
		}
	}
	if (flag) {cout << "-1\n";}
	else {
		F0R(i,n-1) {cout << ans[i] << ' ';}
		cout << ans.back() << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}