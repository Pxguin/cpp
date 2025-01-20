#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

char goal[6] = {'b','e','s','s','i','e'};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    string s; cin >> s;
    int n = s.size();
    v<int> del(n);
    F0R(i,n) {cin >> del[i];}

    v<v<pii>> dp(n+1,v<pii>(6,make_pair(-1,-1)));
    dp[0][5] = {0,0};

    auto test = [&](pii& x, pii y) {
        if (y.f>x.f) {x = y;}
        else if (y.f==x.f && y.s<x.s) {x = y;}
    };

    F0R(i,n) {
        F0R(last,6) {
            if (dp[i][last].f==-1) {continue;}

            int nxt = (last+1)%6;
            // extend current bessie
            if (goal[nxt]==s[i]) {
                test(dp[i+1][nxt],{dp[i][last].f+(nxt==5),dp[i][last].s});
            }
            // try deleting
            test(dp[i+1][last],{dp[i][last].f,dp[i][last].s+del[i]});

            // try not deleting
            test(dp[i+1][5],{dp[i][last].f,dp[i][last].s});
        }
    }
    cout << dp[n][5].f << '\n' << dp[n][5].s << '\n';
}