#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	string s[n];
	F0R(i,n) {cin >> s[i];}
	sort(s,s+n,[&](const string& x, const string& y) {return (x+y)<(y+x);});
	F0R(i,n) {cout << s[i];}
} 	