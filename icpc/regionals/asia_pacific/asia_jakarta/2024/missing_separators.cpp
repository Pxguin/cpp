#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    string s; cin >> s;
    int n = s.size();

    // lcp dp
    v<v<int>> lex(n+1,v<int>(n+1,0));
    for (int i=n-1;i>=0;i--) {
        for (int j=n-1;j>=0;j--) {
            if (s[i]!=s[j]) {lex[i][j] = 0;}
            else {lex[i][j] = lex[i+1][j+1]+1;}
        }
    }

    // dp dp
    v<v<pii>> dp(n+1,v<pii>(n+1,{-1,-1}));

    auto upd = [&](int i, int j) {
        j++;
        if (j==n) {return;}

        int k; // find k
        if (lex[i][j]>=j-i) {
            k = j+j-i;
        } else {
            if (s[i+lex[i][j]]<s[j+lex[i][j]]) {
                k = j+lex[i][j];
            } else {return;}
        } 
        
        if (dp[i][j-1].f>=dp[j][k].f) { // update k
            dp[j][k] = {dp[i][j-1].f+1,i};
        }
    };

    F0R(i,n) {
        dp[0][i] = {1,-1};
        upd(0,i); 
    }
    FOR(j,1,n) {
        FOR(i,1,j+1) {
            if (dp[i][j].f!=-1) {
                upd(i,j);
                if (i<n-1) {
                    if (dp[i][j].f>dp[i][j+1].f) {
                        dp[i][j+1] = dp[i][j];
                    }
                }
            }
        }
    }

    int w = 0; // backtrack to find actual strings
    pii p = {0,0};
    F0R(i,n) {
        if (dp[i][n-1].f>w) {
            w = dp[i][n-1].f;
            p = {i,n-1};
        }
    }
    cout << w << '\n';
    v<string> ans;
    while (p.s!=-1) {
        ans.pb(s.substr(p.f,p.s-p.f+1));
        p = {dp[p.f][p.s].s,p.f-1};
    }
    for (int i=w-1;i>=0;i--) {cout << ans[i] << '\n';}
}