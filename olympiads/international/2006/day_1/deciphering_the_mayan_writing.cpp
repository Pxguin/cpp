#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)

int get(char c) {return (c-'A')-((c-'A')/32)*6;}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, m; cin >> n >> m;
	string w, s; cin >> w >> s;

	vector<int> freq(52,0), freq2(52,0);
	F0R(i,n) {freq[get(w[i])]++;}
	F0R(i,n-1) {freq2[get(s[i])]++;}
	int ans = 0;

	F0R(i,m-n+1) {
		freq2[get(s[i+n-1])]++;
		bool flag = true;
		F0R(j,52) {flag &= (freq[j]==freq2[j]);}
		ans += flag;
		freq2[get(s[i])]--;
	} cout << ans << '\n';
}