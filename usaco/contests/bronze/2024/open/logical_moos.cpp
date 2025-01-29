#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n, q; cin >> n >> q;
	n += 4;
	vector<int> s(n);
	s[0]=s[n-1]=0; s[1]=s[n-2]=3;
	string w;
	F0R(i,n-4) {
		cin >> w;
		s[i+2] = (w=="false"?0:(w=="true"?1:(w=="and"?2:3)));
	}
	vector<bool> pref(n),suff(n);

	vector<int> l,r;
	vector<vector<bool>> doit(2,vector<bool>(n,false));
	for (int t=1;t>=0;t--) {
		int res, c = 0;
		reverse(s.begin(),s.end());
		l.clear(); r.clear();
		for (int i=0;i<n;) {
			if (i+1<n&&s[i+1]==2) {
				l.pb(i); res = 1;
				while (i<n-1&&s[i+1]==2) {
					res&=s[i];
					doit[t][i] = res|c;
					i+=2;
				} r.pb(i); doit[t][i]=(c|=(res&s[i]));
				i+=2;
			} else {
				doit[t][i]=(c|=s[i]);
				i+=2;
			}
		}
	} reverse(doit[1].begin(),doit[1].end());

	while (q--) {
		int a, b; cin >> a >> b >> w; a++; b++;
		int g = (w=="true");
		int a1 = s[a-1]-2, b1 = s[b+1]-2;
		int a2 = doit[0][a-2], b2 = doit[1][b+2];
		auto it1 = upper_bound(l.begin(),l.end(),a), it2 = lower_bound(r.begin(),r.end(),b);
		int a3 = doit[0][(it1==l.begin())?0:*(--it1)-2], b3 = doit[1][(it2==r.end())?n-1:*it2+2];

		int ans;
		if (!a1&&!b1&&g) {ans = (a3|b3|(a2&b2));} // and and true
		if (!a1&&!b1&&!g) {ans = !(a3|b3);} // and and false
		if (!a1&&b1&&g) {ans = (a3|b2|a2);} // and or true
		if (!a1&&b1&&!g) {ans = !(a3|b2);} // and or false
		if (a1&&!b1&&g) {ans = (a2|b3|b2);} // or and true
		if (a1&&!b1&&!g) {ans = !(a2|b3);} // or and false
		if (a1&&b1&&g) {ans = 1;} // or or true
		if (a1&&b1&&!g) {ans = !(a2|b2);} // or or false
		cout << (ans?'Y':'N');
	}
}