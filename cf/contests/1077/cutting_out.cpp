#include <bits/stdc++.h>
using namespace std;

#define pb push_back

vector<int> s(2e5+1,0);
vector<int> res;
int n, k;

bool check(int m) {
	res.clear();
	for (int i=1;i<2e5+1;i++) {
		for (int j=0;j<(s[i]/m);j++) {
			res.pb(i); 
			if (res.size() == k) {return true;}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k; int a;
	for (int i=0;i<n;i++) {cin >> a; s[a]++;}

	int l = 1, h = n, m = (l+h)/2;
	vector<int> ans(k,1);

	while (l <= h) {
		if (check(m)) {
			ans = res; 
			l = m+1;
		} else {h = m-1;}
		m = (l+h)/2;
	}
	for (int i : ans) {cout << i << ' ';}
}
