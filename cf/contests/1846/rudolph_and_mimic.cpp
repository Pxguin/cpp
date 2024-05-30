#include <bits/stdc++.h>
using namespace std;

#define pb push_back

void solve() {
	int n; cin >> n;
	vector<int> cur(10,0); int t;
	for (int i=0;i<n;i++) {cin >> t; cur[t]++;}
	bool change = false;
	vector<int> list;

	for (int z=0;z<5;z++) {
		cout << "- " << list.size();
		while (list.size()) {cout << ' ' << list.back(); list.pop_back();}
		cout << '\n'; cout.flush();

		vector<int> nxt(10,0), order(n);
		for (int i=0;i<n;i++) {cin >> t; nxt[t]++; order[i] = t;}
		for (int i=1;i<=9;i++) {
			if (cur[i] < nxt[i]) {
				if (!change) { // get rid of everything else
					for (int j=0;j<n;j++) {if (order[j] != i) {list.pb(j+1);}}
					n -= list.size();
					change = true;
					for (int j=1;j<=9;j++) {nxt[j] = (i==j ? nxt[j] : 0);}
					break;
				} else {
					// the mimic has been found
					for (int j=0;j<n;j++) {
						if (order[j] == i) {
							cout << "! " << j+1; 
							cout << '\n'; cout.flush(); 
							return;
						}
					}
				}
			}
		}
		cur = nxt;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}
