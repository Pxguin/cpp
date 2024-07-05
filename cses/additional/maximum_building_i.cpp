#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	char a;
	vector<int> len(m,0);
	ll ans = 0;
	F0R(i,n) {
		F0R(j,m) {cin >> a; len[j] = (a=='.' ? len[j]+1 : 0);}
		stack<int> s,s2;
		vector<int> l(m,0),r(m,0);
		F0R(j,m) {
			while (s.size() && len[s.top()]>=len[j]) {s.pop();}
			l[j] = (s.size() ? s.top()+1 : 0); s.push(j);
			while (s2.size() && len[s2.top()]>=len[m-j-1]) {s2.pop();}
			r[m-j-1] = (s2.size() ? s2.top()-1 : m-1); s2.push(m-j-1); 
		}
		F0R(j,m) {ans = max(ans,(ll)(r[j]-l[j]+1)*len[j]);}
	} cout << ans << '\n';
}