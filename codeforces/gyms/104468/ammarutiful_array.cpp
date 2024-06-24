#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int c = 0;
	
	pair<int,int> elements[n];
	for (int i=0;i<n;i++) {cin >> elements[i].f;}
	for (int i=0;i<n;i++) {cin >> elements[i].s; c = max(c,elements[i].s);}

	vector<ll> ps[c+1];
	ll add[c+1] = {0};
	for (int i=0;i<c+1;i++) {ps[i].pb(0);}
	
	for (pair<int,int> i : elements) {
		ps[i.s].pb(*(ps[i.s].rbegin()) + i.f);
	}

	int q; cin >> q;
	ll col, num; int type;
	ll total = 0;
	for (int i=0;i<q;i++) {
		cin >> type >> col >> num; type--;
		if (!type) {
			add[col] += num;
			total += num;
		} else {
			int l = 0, h = ps[col].size()-1;
			int m = (l+h)/2;
			int ans = 0;

			while (l <= h) {
				if (ps[col][m] + m*(total-add[col]) <= num) {
					l = m+1;
					ans = m;
				} else {h = m-1;}
				m = (l+h)/2;
			}
			cout << ans << "\n";
		}
	}
}
