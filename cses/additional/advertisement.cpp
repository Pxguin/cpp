#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
#define mp make_pair
#define ll long long
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	int k[n];
	for (int i=0;i<n;i++) {cin >> k[i];}
	vector<int> front(n), back(n);
 
	auto do_it = [&](vector<int>& ret) {
		stack<pair<int,int>> s; s.push(mp(-1,-1));
		for (int i=0;i<n;i++) {
			while (s.top().f >= k[i]) {s.pop();}
			ret[i] = (s.top().s == -1 ? 0 : s.top().s+1);
			s.push(mp(k[i], i));
		}
	};
	do_it(front);
	reverse(k, k+n);
	do_it(back);
	ll ans = 0;
 
	for (int i=0;i<n;i++) {
		ans = max(ans,(ll)(n-back[n-i-1]-front[i])*k[n-i-1]);
	}
	cout << ans << "\n";
}
