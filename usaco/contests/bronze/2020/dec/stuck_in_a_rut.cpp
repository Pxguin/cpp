#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define eb emplace_back
#define mp make_pair

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	char t; int a, b;
	vector<int> east, north;
	pii cows[n];
	for (int i=0;i<n;i++) {
		cin >> t >> a >> b;
		if (t == 'E') {east.eb(i);}
		else {north.eb(i);}
		cows[i] = mp(a, b);
	}

	sort(east.begin(), east.end(), [&](const int& x, const int& y) {
		return cows[x].s < cows[y].s;
	});
	sort(north.begin(), north.end(), [&](const int& x, const int& y) {
		return cows[x].f < cows[y].f;
	});
	int ans[n] = {0};


	for (int c1 : east) {
		for (int c2 : north) {
			if (!ans[c1] && !ans[c2] && 
			cows[c1].f < cows[c2].f && cows[c2].s < cows[c1].s) {
				if (cows[c1].s-cows[c2].s > cows[c2].f-cows[c1].f) {
					ans[c2] = cows[c1].s-cows[c2].s;
				} else if (cows[c1].s-cows[c2].s < cows[c2].f-cows[c1].f) {
					ans[c1] = cows[c2].f-cows[c1].f;
				}
			}
		}
	}
	for (int i : ans) {
		if (i) {cout << i;}
		else {cout << "Infinity";}
		cout << '\n';
	}
}
