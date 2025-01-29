#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<ll,ll>
#define mp make_pair
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int mod = 1e9+7;
int add(int a, int b) {return (a+b)%mod;}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("palpath.in","r",stdin);
	freopen("palpath.out","w",stdout);
	
	int n; cin >> n;
	v<v<int>> grid(n);
	char c;
	F0R(i,n) {
		F0R(j,n) {
			cin >> c;
			grid[i].pb(c-'A');
		}
	}
	v<v<int>> dp(n,v<int>(n,0));
	dp[0][n-1] = (grid[0][0]==grid[n-1][n-1]);
	
	F0R(len,n-1) {
		v<v<int>> nxt(n,v<int>(n,0));
		F0R(i,len+1) { // row
			for (int j=n-1;j>n-1-len-1;j--) { // other row
				pii c1 = {i,len-i}, c2 = {j,n-1-(len-(n-1-j))};
				
				bool right = !(c1.s+1==n), left = !(c2.s==0);
				if (grid[c1.f+1][c1.s]==grid[c2.f-1][c2.s]) { // down up
					nxt[i+1][j-1] = add(nxt[i+1][j-1],dp[i][j]);
				}
				if (right&&left && grid[c1.f][c1.s+1]==grid[c2.f][c2.s-1]) { // right left
					nxt[i][j] = add(nxt[i][j],dp[i][j]);
				}
				if (right && grid[c1.f][c1.s+1]==grid[c2.f-1][c2.s]) { // right up
					nxt[i][j-1] = add(nxt[i][j-1],dp[i][j]);
				}
				if (left && grid[c1.f+1][c1.s]==grid[c2.f][c2.s-1]) { // down left
					nxt[i+1][j] = add(nxt[i+1][j],dp[i][j]);
				}
			}
		} dp = nxt;
	}
	int ans = 0;
	F0R(i,n) {
		ans = add(ans,dp[i][i]);
	} cout << ans << '\n';
}