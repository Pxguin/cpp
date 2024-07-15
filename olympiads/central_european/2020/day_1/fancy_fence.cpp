#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

ll mod = 1e9+7;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<ll> h(n+2,0),w(n+2,0);
	unordered_map<int,int> bounds;
	F0R(i,n) {cin >> h[i+1]; bounds[h[i+1]]=INT_MIN;}
	F0R(i,n) {cin >> w[i+1]; w[i+1]=(w[i+1]+w[i])%mod;} // ps
	
	vector<int> r(n+2,n+1),l(n+2,0); // nearest smaller values on h (or 0 if it doesn't exist)
	stack<int> s,s2; s.push(0); s2.push(n+1);
	FOR(i,1,n+1,1) {
		int j = n-i+1;
		while (s.size() && h[s.top()]>=h[i]) {s.pop();}
		l[i] = s.top(); s.push(i);
		while (s2.size() && h[s2.top()]>=h[j]) {s2.pop();}
		r[j] = s2.top(); s2.push(j);
	}

    // split the grid into subrectangles, and calculate independently
	ll ans = 0;
	auto add = [&](ll a, ll b)->ll {return (a+b)%mod;};
	auto sub = [&](ll a, ll b)->ll {return (a+mod-b)%mod;};
	auto mult = [&](ll a, ll b)->ll {return a*b%mod;};
	auto subgrids = [&](ll width, ll height)->ll {return mult(mult(width*width%mod+width%mod,height*height%mod+height%mod),250000002);};
	
	FOR(i,1,n+1,1) {
		if (l[i]>=bounds[h[i]]) {
			bounds[h[i]]=r[i];
			ll width = sub(w[r[i]-1],w[l[i]]);
			ll height = h[i], extra = max(h[r[i]],h[l[i]]);
			ans = add(ans,subgrids(width,height));
			ans = sub(ans,subgrids(width,extra));
		}
	} cout << ans << '\n';
}