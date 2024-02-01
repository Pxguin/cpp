#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define s second

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("sort.in","r",stdin); freopen("sort.out","w",stdout);
	int n; cin >> n;
	int a[n];
	for (int i=0;i<n;i++) {cin >> a[i]; a[i]--;}
	int idx[n]; iota(idx, idx+n, 0);

	sort(idx, idx+n);
	map<int,vector<int>> m;
	for (int i=0;i<n;i++) {m[a[i]].pb(i);}
	int ptr = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		for (int i : it->second) {idx[i] = ptr; ptr++;}
	}
	

	int ans = 0;
	for (int i=0;i<n;i++) {
		/*if (idx[i] < i) {ans = max(ans, i-idx[i]);}
		else if (idx[i] > i) {
			vector<int> a2(idx[i]-i);
			partial_sort_copy(a+i, a+idx[i]+1, a2.begin(), a2.end());
			int move = a2.end() - lower_bound(a2.begin(), a2.end(), i);
			ans = max(move, ans);
		}*/
		ans = max(ans, i-idx[i]);
	}
	cout << ans+1 << "\n";
}
