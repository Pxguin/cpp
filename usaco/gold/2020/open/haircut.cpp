#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	freopen("haircut.in","r",stdin);
	freopen("haircut.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n; 
	int a;
	vector<ll> ps(n+2,0);
	vector<ll> bit(n+2,0);
	auto add = [&](int idx) {
		for (++idx; idx <= n+1; idx += idx&-idx) {bit[idx]++;}
	};
	auto sum = [&](int idx) {
		ll res = 0;
		for (++idx; idx > 0; idx -= idx&-idx) {res += bit[idx];}
		return res;
	};
	
	for (int i=0;i<n;i++) {
		cin >> a; 
		add(a);
		ps[a+1] += sum(n)-sum(a);
	}
	for (int i=0;i<n;i++) {ps[i+1]+=ps[i]; cout << ps[i] << '\n';}
}
