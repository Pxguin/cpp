#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	ll a; ll ans = 0;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	F0R(i,n) {
		cin >> a; ans += a;
		pq.push({a*3,3});
	} 
	F0R(i,n-2) {
		pii cur = pq.top(); pq.pop();
		ans += cur.f;
		cur.f = cur.f/cur.s*(cur.s+2); cur.s += 2; 
		pq.push(cur);
	} cout << ans << '\n';
}