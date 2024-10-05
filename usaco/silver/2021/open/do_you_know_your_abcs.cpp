#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	F0R(i,n) {cin >> a[i];}

	vector<int> cand;
	F0R(i,n) {
		cand.pb(a[i]);
		FOR(j,i+1,n) {cand.pb(abs(a[j]-a[i]));}
	} int m = cand.size();
	sort(cand.begin(),cand.end());
	set<pair<pii,int>> ans;
	auto check = [&](int a1, int b1, int c1)->bool {
		multiset<int> v({a1,b1,c1,a1+b1,a1+c1,b1+c1,a1+b1+c1});
		for (auto x : a) {
			if (v.find(x)!=v.end()) {v.erase(v.find(x));}
			else {return false;}
		} return true;
	};
	F0R(i,m) {
		FOR(j,i+1,m) {
			FOR(k,j+1,m) {
				if (check(cand[i],cand[j],cand[k])) {ans.insert({{cand[i],cand[j]},cand[k]});}
			}
		}
	} cout << ans.size() << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}