#include <bits/stdc++.h>
using namespace std;

#define s second
#define f first
#define pb push_back
#define ll long long

void solve() {
	int n, m, k; cin >> n >> m >> k;
	int a;
	vector<pair<vector<int>,vector<int>>> ok(m);
	ll turns[m+1]; turns[0] = n;
	ll change[m];
	bool moves[m];
	for (int i=0;i<m;i++) {
		for (int j=0;j<k;j++) {
			cin >> a;
			if (a%2) {ok[i].s.pb(a);}
			else {ok[i].f.pb(a);}
		}
		sort(ok[i].f.begin(), ok[i].f.end());
		sort(ok[i].s.begin(), ok[i].s.end());
	}
	// 0 = even, 1 = odd
	for (int i=0;i<m;i++) {
		if (ok[i].s.empty()) { // if odd is empty, pick even
			moves[i] = 0; n += ok[i].f.front();
			change[i] = ok[i].f.back()+ok[i].f.front();
		}
		else if (ok[i].f.empty()) {
			moves[i] = 1; n += ok[i].s.front();
			change[i] = ok[i].s.back()+ok[i].s.front();
		}
		else {
			if (ok[i].f.back() >= ok[i].s.back()) { // if even loss > odd loss
				moves[i]=0; n -= ok[i].s.back();
				change[i] = ok[i].f.back()-ok[i].s.back();
			}// pick even
			else {
				moves[i] = 1; n -= ok[i].f.back();
				change[i] = ok[i].s.back()-ok[i].f.back();
			}//pick odd
		}
		turns[i+1] = n;
		if (n <= 0) {cout << -1 << "\n";return;}
	}
	for (int i=m-1;i>=0;i--) {turns[i] = min(turns[i+1], turns[i]);} // ss
	ll total = 0;
	for (int i=0;i<m;i++) {
		if (moves[i]) { // if odd swap to even
			total += change[i];
			if (turns[i+1] - total > 0) {moves[i] = 0;}
			else {total -= change[i];}
		}
	}
	cout << (moves[0]?"Odd":"Even");
	for (int i=1;i<m;i++) {
		cout << " " << (moves[i]?"Odd":"Even");
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {solve();}
}
