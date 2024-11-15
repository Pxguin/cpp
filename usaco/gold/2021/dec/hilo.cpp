#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	v<int> a(n), hi(n,-1), pos(n);
	v<int> freq(n,0);
	set<int> cur;
	F0R(i,n) {
		cin >> a[i];
		pos[--a[i]]=i;
		if (cur.lower_bound(a[i])!=cur.end()) {hi[a[i]]=*cur.lower_bound(a[i]);}
		cur.insert(a[i]);
	}

	int ans = 0;
	cout << 0 << '\n';
	stack<int> s;
	F0R(num,n) {
		if (freq[num]) {ans--;} // this number transitions from HI to LO
		freq[num]=0;
		while (s.size()&&pos[s.top()]>pos[num]) {
			if (hi[s.top()]>num && (--freq[hi[s.top()]])==0) {ans--;} // update the stack and frequency array (and answer)
			s.pop();
		} s.push(num); // this number is now a LO so update the freq array and answer
		if (hi[num]>num && (freq[hi[num]]++)==0) {ans++;}
		cout << ans << '\n';
	}
}