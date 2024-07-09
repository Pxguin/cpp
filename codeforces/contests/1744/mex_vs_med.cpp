#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

void solve() {
	int n; cin >> n;
	int a, idx[n];
	F0R(i,n) {cin >> a; idx[a]=i;}
	ll l = idx[0], r = idx[0];
	ll ans = 1;
	F0R(i,n-1) {
		ll nxt = idx[i+1];
		ll used = r-l-i;
		ll lb,rb,cur,sum;
		if ((nxt < l || nxt > r) && used <= i+1) {
			if (nxt < l) {lb = min(l-nxt-1,i+1-used); rb = min(i+1-used,n-r-1);}
			else {lb = min(i+1-used,l); rb = min(nxt-r-1,i+1-used);}
			rb = max(0LL,rb); lb = max(0LL,lb);
			lb = min(lb,(ll)i+1); rb = min(rb,(ll)i+1);
			cur = min(max((i+1-used)-lb,0LL),rb)+1;
			rb++; lb++;
			ans += (lb*cur); cur = rb-cur;
			sum = (lb-cur+lb-1)*(cur)/2;
			ans += sum;
		} 
		l = min(l,nxt); r = max(r,nxt);
	} cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
} 	