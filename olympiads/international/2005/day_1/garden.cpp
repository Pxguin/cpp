#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int l, w, n, k; cin >> l >> w >> n >> k;
	v<v<int>> ps(w+1,v<int>(l+1,0));

	int a, b;
	F0R(i,n) {
		cin >> a >> b;
		ps[w-b + 1][a-1 + 1]++;
	}

	F0R(i,w) {
		F0R(j,l) {
			ps[i+1][j+1] += ps[i][j+1]+ps[i+1][j]-ps[i][j];
		}
	}
	auto get = [&](int r1, int c1, int r2, int c2) {
		return ps[r2+1][c2+1]-ps[r2+1][c1]-ps[r1][c2+1]+ps[r1][c1];
	};

	v<int> left(l,1e9),right(l,1e9),up(w,1e9),down(w,1e9);

	FOR(height,1,w+1) {
		F0R(row,w-height+1) {
			int ptr = 0;
			F0R(i,l) { // for each left ptr find the min right ptr such that k flowers are contained
				while (ptr<l && get(row,i,row+height-1,ptr)<k) {ptr++;}
				if (ptr!=l && get(row,i,row+height-1,ptr)==k) { // candidate rectangle
					int p = 2*(ptr-i+1 + height);
					chmin(right[i],p); chmin(left[ptr],p);
					chmin(down[row],p); chmin(up[row+height-1],p);
				}
			}
		}
	}
	F0R(i,l-1) { // get min perimeter to left/right of each splitting line
		chmin(left[i+1],left[i]);
		chmin(right[l-i-2],right[l-i-1]);
	}
	F0R(i,w-1) {
		chmin(up[i+1],up[i]);
		chmin(down[w-i-2],down[w-i-1]);
	}
	int ans = INT_MAX; // test each line
	F0R(i,l-1) {chmin(ans,left[i]+right[i+1]);}
	F0R(i,w-1) {chmin(ans,up[i]+down[i+1]);}

	if (ans>=2e9) {cout << "NO" << '\n';}
	else {cout << ans << '\n';}
}