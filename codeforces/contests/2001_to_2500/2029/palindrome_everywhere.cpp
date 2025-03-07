#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

bool solve() {
	int n; cin >> n;
	v<bool> s(n);
	int p = 0;
	bool red = false, blue = false;
	char c;
	F0R(i,n) {
		cin >> c;
		s[i] = (c=='R');
		if (s[i]!=s[0] && p==0) {p=i;}
		if (i) {
			red |= (s[i]&&s[i-1]);
			blue |= (!s[i]&&!s[i-1]);
		}
	} 
	red |= (s[0]&&s[n-1]);
	blue |= (!s[0]&&!s[n-1]);

	// cases
	if (p==0) {return true;} // if it's all R or all B
	if (red&&blue) {return false;} // if there is both RR and BB
    
	rotate(s.begin(),s.begin()+p,s.end());
	int gaps[2] = {0}; // frequency of odd and even blocks
	F0R(i,n) {
		if (s[i]==red) {
			int j = i;
			for (;j<n && (s[j]==red);j++) {} // find total size of the block
			gaps[(j-i)%2]++;
			i = j-1;
		}
	} return (gaps[0]==1 || gaps[0]+gaps[1]==1); // works if only one even block, or only one block in total
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;
	while (t--) {cout << (solve() ? "YES" : "NO") << '\n';}
}