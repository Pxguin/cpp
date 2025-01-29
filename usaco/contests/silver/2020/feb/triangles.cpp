#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ll long long

struct hsh {
	size_t operator()(const pair<int,int> &p) const {
		return p.f * 1239 + p.s;
	}
};

bool ycomp(const pair<int,int>& x, const pair<int,int>& y) {
	if (x.s != y.s) {return x.s < y.s;}
	return x.f < y.f;
}

int main() {
	freopen("triangles.in","r",stdin);
	freopen("triangles.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int a, b; 
	vector<pair<int,int>> p;
	for (int i=0;i<n;i++) {cin >> a >> b; p.pb(mp(a,b));}

	sort(p.begin(), p.end(), ycomp);
	p.pb(mp(INT_MAX, INT_MAX));
	unordered_map<pair<int,int>, ll, hsh> seg_x;
	unordered_map<pair<int,int>, ll, hsh> seg_y;
	int ptr = 0;
	ll right = 0, left = 0;
	for (int i=0;i<n+1;i++) {
		if (p[i].s == p[ptr].s) {
			right += p[i].f - p[ptr].f;
		} else {
			seg_x[p[ptr]] = right;
			for (int j=ptr+1;j<i;j++) {
				ll d = p[j].f-p[j-1].f;
				left += d*(j-ptr);
				right -= d*(i-j);
				seg_x[p[j]] = left+right;
			}
			right = 0; left = 0;
			ptr = i;
		}
	}
	
	sort(p.begin(), p.end());

	// all y segments
	ptr = 0;
	for (int i=0;i<n+1;i++) {
		if (p[i].f == p[ptr].f) {
			right += p[i].s - p[ptr].s;
		} else {
			seg_y[p[ptr]] = right;
			for (int j=ptr+1;j<i;j++) {
				ll d = p[j].s-p[j-1].s;
				left += d*(j-ptr);
				right -= d*(i-j);
				seg_y[p[j]] = left+right;
			}
			right = 0; left = 0;
			ptr = i;
		}
	}

	// now calc area
	ll ans = 0;
	for (int i=0;i<n;i++) {
		ans += (seg_x[p[i]]*seg_y[p[i]])%(1000000007);
		ans %= 1000000007;
	}
	cout << ans << "\n";
}
