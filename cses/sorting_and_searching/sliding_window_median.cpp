#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, k; cin >> n >> k;
	v<int> x(n);
	F0R(i,n) {cin >> x[i];}

	ordered_multiset<int> s;
	F0R(i,k) {s.insert(x[i]);}
	cout << *s.find_by_order((k+1)/2-1);

	FOR(i,1,n-k+1) {
		s.erase(s.upper_bound(x[i-1]));
		s.insert(x[i+k-1]);
		cout << ' ' << *s.find_by_order((k+1)/2-1);
	}
}