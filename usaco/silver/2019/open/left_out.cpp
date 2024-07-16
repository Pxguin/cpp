#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("leftout.in","r",stdin);
	freopen("leftout.out","w",stdout);
	
	int n; cin >> n;
	char c;
	vector<string> rows(n);
	unordered_map<string,int> freq;

	F0R(i,n) {
		string s = "";
		F0R(j,n) {
			cin >> c;
			s += (c=='R'?'1':'0'); // 0 L, 1 R
		} 
		if (s[0] == '1') {F0R(j,n) {s[j] = (s[j]=='1'?'0':'1');}}
		rows[i] = s; freq[s]++;
	}
	if (freq.size()==1 || freq.size()>2) {cout << -1 << '\n';}
	else {
		pii ans = {-1,10000};
		F0R(i,n) {
			if (freq[rows[i]]==1) {
				F0R(j,n) {
					rows[i][j] = (rows[i][j]=='1'?'0':'1');
					if (freq[rows[i]]) {ans = {i+1,min(ans.s,j+1)};}
					rows[i][j] = (rows[i][j]=='1'?'0':'1');
				} F0R(j,n) {rows[i][j] = (rows[i][j]=='1'?'0':'1');}
				F0R(j,n) {
					rows[i][j] = (rows[i][j]=='1'?'0':'1');
					if (freq[rows[i]]) {ans = {i+1,min(ans.s,j+1)};}
					rows[i][j] = (rows[i][j]=='1'?'0':'1');
				} F0R(j,n) {rows[i][j] = (rows[i][j]=='1'?'0':'1');}
				break;
			}
		}
		if (ans==mp(-1,10000)) {cout << -1 << '\n';}
		else {cout << ans.f << ' ' << ans.s << '\n';}
	}
}