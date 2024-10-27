#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)

using Event = pair<pii,int>;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	int q1,t1,x1,n1;
	vector<Event> cows, apples;
	F0R(i,n) {
		cin >> q1 >> t1 >> x1 >> n1;
		if (q1==1) {cows.pb({{x1+t1,t1-x1},n1});} 
		else {apples.pb({{x1+t1,t1-x1},n1});}
	}
	sort(cows.begin(),cows.end(),greater<>());
	sort(apples.begin(),apples.end(),greater<>());
	multiset<pii> cur;
	int ans = 0;

	while (apples.size()) {
		Event apple = apples.back();
		if (cows.size()&&cows.back().f.f<=apple.f.f) {
			Event cow = cows.back();
			cur.insert({cow.f.s,cow.s});
			cows.pop_back();
		} else {
			auto it = cur.upper_bound({apple.f.s,1e9});
			int rem = apple.s;
			while (it!=cur.begin()) {
				it--;
				pii x = *it; cur.erase(it);
				if (rem>=x.s) {rem -= x.s;} 
				else {
					x.s -= rem; rem = 0;
					cur.insert(x);
					break;
				}
				it = cur.upper_bound({apple.f.s,1e9});
			}
			apples.pop_back();
			ans += apple.s-rem;
		}
	} cout << ans << '\n';
}