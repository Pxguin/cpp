#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)

void solve() {
	string s; cin >> s;
	int n = s.size();
	F0R(i,n-1) { // two equal adjacent characters
		if (s[i]==s[i+1]) {cout << s[i] << s[i] << '\n'; return;}
	}
	F0R(i,n-2) { // three adjacent distinct characters
		if (s[i]!=s[i+1] && s[i+1]!=s[i+2] && s[i]!=s[i+2]) {
			cout << s[i] << s[i+1] << s[i+2] << '\n'; return;
		}
	}
	cout << "-1\n"; return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {solve();}
}