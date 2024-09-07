#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)

using T = pair<pii,int>;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, l, r; cin >> n;
	vector<T> ranges;
	F0R(i,n) {cin >> l >> r; ranges.pb({{l,-r},i});}
	sort(ranges.begin(),ranges.end());
	F0R(i,n) {ranges[i].f.s *= -1;}

	stack<int> st;
	vector<bool> ok1(n,false), ok2(n,false);
	F0R(i,n) {
		while (st.size() && ranges[st.top()].f.s >= ranges[i].f.s) {
			ok1[ranges[st.top()].s] = true; st.pop();
		} st.push(i);
	} 
	int mx = -1;
	F0R(i,n) {
		if (ranges[i].f.f > mx) {mx = -1;}
		if (ranges[i].f.s <= mx) {ok2[ranges[i].s] = true;}
		mx = max(mx, ranges[i].f.s);
	}

	F0R(i,n) {cout << ok1[i] << ' ';} cout << '\n';
	F0R(i,n) {cout << ok2[i] << ' ';} cout << '\n';
}