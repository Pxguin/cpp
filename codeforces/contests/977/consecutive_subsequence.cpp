#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    map<int,pii> e; // max dp value for each a
    v<pii> dp; // maximum length of subsequence ending at i, plus pointer to previous index in subsequence

    F0R(i,n) {
        int a; cin >> a;
        dp.pb({1,-1});

        if (e.count(a-1)) { // see if a-1 existed
            dp[i] = e[a-1];
            dp[i].f++;
        }
        if (!e.count(a) || e[a].f<dp[i].f) {e[a] = {dp[i].f,i};} // update map
    }
    int mx = 0;
    F0R(i,n) { // find max length subsequence
        if (dp[i].f>dp[mx].f) {mx = i;}
    }
    v<int> ans;

    do {ans.pb(mx+1);} // retrieve subsequence
    while ((mx=dp[mx].s)!=-1);

    cout << ans.size() << '\n';
    for (int i=ans.size()-1;i>=0;i--) {cout << ans[i] << ' ';}
}