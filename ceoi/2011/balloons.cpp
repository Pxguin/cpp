#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define pii pair<ld,ld>
#define mp make_pair
#define f first
#define s second

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	ld x, r;
	stack<pii> s;
	cout << fixed << setprecision(3);
	F0R(i,n) {
		cin >> x >> r;
		ld r1 = r;
		while (s.size()) {
			pii p = s.top(); 
			ld cand = min((ld)(x-p.f)*(x-p.f)/(p.s*4.0),r);
			if (cand <= r1) {r1 = cand;}
			if (r1 >= p.s) {s.pop();}
			else {break;}
		} s.push({x,r1});
		cout << r1 << '\n';
	} 
}