#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

v<v<int>> adj;
v<int> dp;
bool flag;

void check(int k, int cur, int par) {
    dp[cur] = 0;
    if (!flag) {return;}

    map<int,int> len; // stores frequency of all path lengths
    for (int x : adj[cur]) {
        if (x==par) {continue;}
        check(k,x,cur);
        if (dp[x]+1!=k) {len[dp[x]+1]++;} // extend child paths by 1
    }

    int left = 0;
    for (auto& [val,freq] : len) {
        if (2*val == k) {freq %= 2;} // pair up paths with lengths adding to K
        else {
            int paired = min(freq,len[k-val]);
            freq -= paired; len[k-val] -= paired;
        }

        left += freq;
        if (freq) {dp[cur] = val;}
    }
    if (left>1) {flag = false;} // fail case (if more than one unpaired path)
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("deleg.in","r",stdin);
    freopen("deleg.out","w",stdout);

    int n; cin >> n;
    adj.resize(n); dp.resize(n);
    F0R(i,n-1) {
        int u, v1; cin >> u >> v1;
        adj[--u].pb(--v1);
        adj[v1].pb(u);
    }

    v<bool> ans(n-1,false);
    FOR(i,1,n) {
        if ((n-1)%i==0) {
            flag = true;
            check(i,0,0); 
            ans[i-1] = (flag&&!dp[0]);
        }
    } 
    for (bool i : ans) {cout << i;}
}