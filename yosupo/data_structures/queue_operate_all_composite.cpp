#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define v vector

ll mod = 998244353;

ll mul(ll a, ll b) {return a*b%mod;}
ll add(ll a, ll b) {return (a+b)%mod;}
ll sub(ll a, ll b) {return (a+mod-b)%mod;}

ll exp(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b&1) {res = mul(a,res);}
		b /= 2;
		a = mul(a,a);
	} return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	ll x = 1, k = 0;
	deque<pii> q;

	int q1; cin >> q1;
	while (q1--) {
		int t; cin >> t;
		if (t==0) {
			int a, b; cin >> a >> b;
			q.push_back({a,b});
			x = mul(x,a); k = add(mul(k,a),b);
		} else if (t==1) {
			pii del = q.front(); q.pop_front();
			ll inv = exp(del.f,mod-2);
			x = mul(x,inv); k = sub(k,mul(x,del.s));
		} else {
			int a; cin >> a;
			cout << add(mul(x,a),k)%mod << '\n';
		}
	}
}