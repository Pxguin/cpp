#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define mp make_pair
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)

void solve() {
	int n, k, w, h; cin >> n >> k >> w >> h;
	char d;
	w *= 2; h *= 2;

	map<pii,ll> freq;
	ll x = 0, y = 0;
	ll dx = 0, dy = 0;
	F0R(i,n) {
		cin >> d;
		x += (d=='R')-(d=='L');
		dx = (dx+w+(d=='L')-(d=='R'))%w; // dist to next largest multiple of 2W
		y += (d=='U')-(d=='D');
		dy = (dy+h+(d=='D')-(d=='U'))%h; // same thing for 2H
		freq[{dx,dy}]++;
	}
	ll cx = 0, cy = 0, ans = 0;
	F0R(i,k) {
		ans += freq[{cx,cy}];
		cx = (cx+x+100000LL*w)%w; cy = (cy+y+100000LL*h)%h; // dist to next smallest multiple of 2W and 2H
	} cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}