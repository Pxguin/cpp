#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    
	int n, k; cin >> n >> k;
	v<int> x(n);
	F0R(i,n) {cin >> x[i];}

	multiset<ll> left, right;
	int k2 = (k+1)/2;
	ll sum1 = 0, sum2 = 0;

	auto balance = [&]() {
		if (left.size()>k2) {
			int d = *left.rbegin();
			sum2 += d; sum1 -= d;
			right.insert(d);
			left.erase(--left.end());
		} else if (right.size()>k-k2) {
			int d = *right.begin();
			sum2 -= d; sum1 += d;
			right.erase(right.begin());
			left.insert(d);
		}
	};

	F0R(i,n) {
		left.insert(x[i]);
		sum1 += x[i];
		balance();
		
		if (i>=k) {
			if (left.count(x[i-k])) {
				left.erase(left.find(x[i-k]));
				sum1 -= x[i-k];
			} else {
				right.erase(right.find(x[i-k]));
				sum2 -= x[i-k];
			} balance();
		}
		if (i>=k-1) {
			int sz = left.size(), sz2 = right.size();
			cout << sum2-sum1+(*left.rbegin())*(sz-sz2) << ' ';
		}
	}
}