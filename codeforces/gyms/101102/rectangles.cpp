#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
	int r, c; cin >> r >> c;
	v<v<int>> col(r,v<int>(c+2));
	F0R(i,r) {
		F0R(j,c) {cin >> col[i][j+1];}
		col[i][0]=col[i][1]; col[i][c+1]=-i;
	}
	v<int> h(c+2,1);
	ll ans = 0;
	F0R(i,r) {
		int prev = 1;
		FOR(j,1,c+2) {
			if (i && (col[i-1][j]==col[i][j])) {h[j]++;} // for each column, keep track of consecutive ranges of same-colored cells
			else {h[j]=1;}

			if (col[i][j-1]!=col[i][j]) { // range [prev,j)
				int temp = h[j], temp2 = h[prev-1]; // set the two boundaries to be 0 for stack part; change them back later
				h[prev-1] = h[j] = 0;
				int n = j-prev;

				v<int> right(n+1,n), left(n+1,0);
				stack<int> l1, r1;
				l1.push(0); r1.push(n+1);
				prev--;
				v<int> ignore(n+1,0);

				FOR(k,1,n+1) {
					while (h[k+prev]<=h[l1.top()+prev]) {l1.pop();} // nearest smaller val on left
					left[k]=l1.top();
					l1.push(k);

					while (h[n+1-k+prev]<=h[r1.top()+prev]) { // the val on right; if there's an equal value, then ignore this one (bc overcounting)
						ignore[n+1-k] |= (h[n+1-k+prev]==h[r1.top()+prev]);
						r1.pop();
					} right[n+1-k]=r1.top();
					r1.push(n+1-k);
				}
				FOR(k,1,n+1) { // calculate the amount of rectangles
					if (!ignore[k]) {
						ll extra = max(h[left[k]+prev],h[right[k]+prev]);
						ll width = right[k]-left[k]-1;
						ll height = h[k+prev];
						ans += width*(width+1)/2*(height-extra);
					}
				}
				h[prev]=temp2;
				h[prev=j] = temp;
			} 
		}
	} cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}