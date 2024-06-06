#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back

int main() {
	freopen("moop.in","r",stdin);
	freopen("moop.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n; cin >> n; 
	int x, y;
	vector<pii> moop;
	for (int i=0;i<n;i++) {cin >> x >> y; moop.pb(mp(x,y));}
	sort(moop.begin(), moop.end());

	int mn = moop[0].s;
	set<pii> range;
	for (int i=0;i<n;i++) {
		mn = min(mn, moop[i].s);
		int l = mn, r = moop[i].s;
		while (range.size() && range.begin()->f <= r) {
			r = max(r, range.begin()->s); range.erase(range.begin());
		}
		range.insert(mp(l,r));
	}

	cout << range.size() << '\n';
}
