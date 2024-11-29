#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int mod = 1e9+7;
void add(int& a, int b) {a = (a+b)%mod;}
int dp[100001][4][4][4] = {0};
unordered_map<char,int> m;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	string s; cin >> s;
	int n = s.size();
	s = 'e'+s;
	m['A']=0; m['C']=1; m['T']=2; m['G']=3;
	
	F0R(c,4) { // base cases
	    F0R(c2,4) {
	        if (s[1]!='?'&&m[s[1]]!=c2) {continue;}
	        dp[1][c][c2][c2] = 1;
	    }
	}

	FOR(i,2,n+1) {
	    F0R(c3,4) {
	        if (s[i]!='?'&&m[s[i]]!=c3) {continue;}
	        F0R(c,4) {
	            F0R(c2,4) {
	                F0R(notc3,4) { // first transition
	                    if (notc3==c3) {continue;}
	                    add(dp[i][c][c2][c3],dp[i-1][c][c2][notc3]);   
	                }
	            }
	            F0R(x,4) { // second transition
                    add(dp[i][x][c3][c3],dp[i-1][c][x][c]);
                }
	        }
	    }
	}

	int ans = 0;
	F0R(c,4) { // answer
	    F0R(c2,4) {
	        add(ans,dp[n][c][c2][c]);
	    }
	} cout << ans << '\n';
}