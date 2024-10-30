#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, a1; cin >> n;
	set<pii> a;
	F0R(i,n) {
		cin >> a1;
		if (a1-2) {a.insert({i,a1-2});}
	}

	vector<vector<int>> extra(n);
	while (a.size()) {
		pii x = *a.begin();
		auto it = a.begin();
		int start = x.f, cur = x.f;
		while (cur==x.f && it!=a.end()) {
			a.erase(it);
			if (x.s-2) {a.insert({x.f,x.s-2});}
			it = a.upper_bound({x.f,1e9});
			cur++;
			x = *it;
		} extra[start].pb(cur-1);
	}
	F0R(i,n) {cout<<'R';}
	for (int i=n-1;i>=0;i--) {
		cout << 'L';
		for (int j : extra[i]) {
			F0R(ctr,j-i+1) {cout<<'R';}
			F0R(ctr,j-i+1) {cout<<'L';}
		}
	}
}