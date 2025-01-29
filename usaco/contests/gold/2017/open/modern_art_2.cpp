#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("art2.in","r",stdin);
	freopen("art2.out","w",stdout);
	
	int n; cin >> n;
	int a[n],s[n+1],e[n+1];
	F0R(i,n) {cin >> a[i]; s[i]=e[i]=-1;} s[n]=e[n]=-1;
	F0R(i,n) {e[a[i]]=i; s[a[n-i-1]]=n-i-1;} s[0]=e[0]=-1;

	stack<pii> st; st.push({-1,0}); 
	vector<int> c(n+1,0);
	int ans = 0;
	F0R(i,n) {
		if (s[a[i]]==i) {
			st.push({a[i],st.top().s+1}); 
			c[a[i]] = st.top().s;
			ans = max(ans, st.top().s);
		}
		if (st.top().s > c[a[i]] || st.size()>1&&a[i]==0) {ans = -1; break;}
		if (e[a[i]]==i) {
			c[a[i]] = 0; st.pop();
		}
	} cout << ans << '\n';
}