#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("circlecross.in","r",stdin);
	freopen("circlecross.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s; cin >> s;
	int ans = 0;
	for (int i=0;i<26;i++) {
		for (int j=0;j<26;j++) {
			queue<char> q;
			q.push(i+'A'); q.push(j+'A'); q.push(i+'A'); q.push(j+'A');
			for (char x : s) {if (q.size() && x == q.front()) {q.pop();}}
			if (q.empty()) {ans++;}
		}
	}
	cout << ans << '\n';
}
