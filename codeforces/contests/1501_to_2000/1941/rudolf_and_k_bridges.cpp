#include <bits/stdc++.h>
using namespace std;

#define ll long long

multiset<ll> prev_d; 
vector<ll> row(2e5+1);
deque<ll> order; 

void solve() {
	deque<ll> row_order; ll sum = 0;
	ll ans = LLONG_MAX;
	int n, m, k, d; cin >> n >> m >> k >> d;
	d = min(m-1, d+1);
	for (int i=0;i<n;i++) {
		prev_d.insert(1); order.push_front(1);
		for (int j=0;j<m;j++) {cin >> row[j];}
		for (int j=1;j<m;j++) {
			ll cur = *prev_d.begin()+row[j]+1;
			prev_d.insert(cur); order.push_front(cur);
			if (prev_d.size() > d) {
				prev_d.erase(prev_d.find(order.back()));
				order.pop_back();
			}
		}
		ll mn = order.front();
		row_order.push_front(mn); sum += mn;
		if (row_order.size() > k) {sum -= row_order.back(); row_order.pop_back();}
		if (row_order.size() == k) {ans = min(ans, sum);}
		prev_d.clear(); order.clear();
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {solve();}
}