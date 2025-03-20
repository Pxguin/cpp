#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll hp = 0;
int n;
 
bool move(int& ptr, vector<ll>& a, ll& sum, int step) {
	int val = (step == -1) ? -1 : n;
	bool flag = false;
 
	while (ptr != val) {
		sum += a[ptr];
		if (sum >= 0) {
			flag = true;
			hp += sum;
			sum = 0;
		} else if (sum + hp < 0) {
			sum -= a[ptr];
			break;
		}
		ptr += step;
	}
 
	return flag || (ptr == val);
}
 
bool solve() {
	int k; cin >> n >> k; k--;
	vector<ll> a(n);
	ll lsum = 0, rsum = 0;
	for (int i=0;i<n;i++) {
		cin >> a[i];
	}
	int p1 = k-1, p2 = k+1;
	hp = a[k];
 
	while (p1 != -1 && p2 != n) {
		int res1 = move(p1, a, lsum, -1);
		int res2 = move(p2, a, rsum, 1);
		if (!(res1||res2)){
			return false;
		}
	}
	return true;
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {cout << (solve() ? "YES" : "NO") << "\n";}
}