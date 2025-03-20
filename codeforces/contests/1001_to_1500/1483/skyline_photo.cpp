#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector<ll> h(n+1), b(n+1);
	F0R(i,n) {cin >> h[i+1];}
	F0R(i,n) {cin >> b[i+1];}
	h[0] = b[0] = 0;

	vector<ll> dp(n+1,0);
	stack<int> ranges; ranges.push(0);
	stack<ll> val; val.push(0);
	multiset<ll> mx;

	FOR(i,1,n+1) {
		ll nxt = dp[i-1];
		while (h[i]<h[ranges.top()]) {
			chmax(nxt,val.top());
			mx.erase(mx.find(b[ranges.top()]+val.top()));
			ranges.pop();
			val.pop();
		} 
		ranges.push(i);
		val.push(nxt);
		mx.insert(b[i]+val.top());
		dp[i] = *mx.rbegin();
	} cout << dp[n] << '\n';
}