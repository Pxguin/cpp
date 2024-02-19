#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int solve() {
	int n, q, c; cin >> n >> q >> c;
	int cows[n];
	int mx[n];
	int cur_max = 0;
	pair<int,int> query[q];
	for (int i=0;i<n;i++) {
		cin >> cows[i];
		cur_max = max(cur_max, cows[i]);
		mx[i] = cur_max;
	}
	for (int i=0;i<q;i++) {cin >> query[i].s >> query[i].f;}
	sort(query, query+q);
	int last_h = 0;
	int val = 1;
	int h, a;

	for (int i=0;i<q;i++) {
		h = query[i].f, a = query[i].s; h--; a--;
		if (h != last_h) {
			if (a < last_h) {return 1;}
			if (mx[a] < mx[h-1]) {
				bool flag = false;
				for (int j=a;j>=last_h;j--) {
					if (!cows[j]) {
						cows[j] = mx[h-1]; flag = true; break;
					}
				}
				if (!flag) {return 1;}
			}
			if (!cows[last_h]) {
				cows[last_h] = val;
				mx[last_h] = max(mx[last_h], cows[last_h]);
				if (i == q-1) {
					for (int j=last_h+1;j<=h;j++) {mx[j] = max(cows[j], mx[j-1]);}
				} else {
					for (int j=last_h+1;j<=query[i+1].f;j++) {mx[j] = max(cows[j], mx[j-1]);}
				}
			}
			if (cows[h]) {
				if (cows[h] <= mx[h-1]) {return 1;}
			} else {
				val = max(1,mx[h-1])+1;
				if (val > c) {return 1;}
			}
			last_h = h;
		}
	}
	if (!cows[h]) {cows[h] = val;}
	for (int i=0;i<n;i++) {cows[i] = max(1,cows[i]);}
	cout << cows[0];
	for (int i=1;i<n;i++) {cout << ' ' << cows[i];}
	return 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {cout << (solve() ? "-1\n" : "\n");}
}
