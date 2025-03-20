#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int a[n];
	for (int i=0;i<n;i++) {cin >> a[i];}
	vector<int> front(n), back(n);

	auto do_it = [&](vector<int>& ret) {
		stack<pair<int,int>> s; s.push(mp(-1,-1));
		for (int i=0;i<n;i++) {
			while (s.top().f >= a[i]) {s.pop();}
			ret[i] = (s.top().s == -1 ? 0 : s.top().s+1);
			s.push(mp(a[i], i));
		}
	};
	do_it(front); reverse(a, a+n); do_it(back);
	multiset<int> mx;
	vector<int> events[n+1];

	for (int i=0;i<n;i++) {
		mx.insert(a[n-i-1]);
		events[n-back[n-i-1]-front[i]].pb(a[n-i-1]);
	}
	for (int i=1;i<=n;i++) {
		cout << *(--mx.end()) << " ";
		for (int x : events[i]) {mx.erase(mx.find(x));}
	}
}
