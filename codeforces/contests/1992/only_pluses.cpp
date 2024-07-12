#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b, s) for (int i = (a); i < (b); i += s)
#define F0R(i, a) for (int i = 0; i < (a); i++)

void solve() {
	int a, b, c; cin >> a >> b >> c;
	int ans = a*b*c;
	FOR(i,a,16,1) {
		FOR(j,b,16,1) {
			FOR(k,c,16,1) {
				if (i-a + j-b + k-c <= 5) {ans = max(ans,i*j*k);}
			}
		}
	} cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {solve();}
} 	