#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second

int main() {
	freopen("censor.in","r",stdin);
	freopen("censor.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	string s, t; cin >> s >> t;
	string ans;
	
	for (int i=0;i<s.size();i++) {
		ans += s[i];
		if (ans.size() >= t.size()) {
			bool flag = true;
			for (int j=0;j<t.size();j++) {
				if (t[j] != ans[ans.size()-t.size()+j]) {flag = false;}
			}
			if (flag) {for (char x : t) {ans.pop_back();}}
		}
	}
	cout << ans << '\n';
}
