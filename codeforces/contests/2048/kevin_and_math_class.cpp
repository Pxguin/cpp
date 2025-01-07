#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int n; cin >> n;
    v<ll> a(n), b(n);
    F0R(i,n) {cin >> a[i];}
    F0R(i,n) {cin >> b[i];}

    stack<ll> s; // cartesian tree construction
    v<int> left(n,-1), right(n,-1);
    int t = -1, last = -1;
    F0R(i,n) {
        while (s.size() && b[s.top()]>=b[i]) {last = s.top(); s.pop();}

        if (s.size()) {right[s.top()] = i;}
        if (t!=-1 && b[i]<=b[t]) {left[i] = last;}

        s.push(i);
        t = i; last = t;
    }

    v<v<ll>> dp(n,v<ll>(63,LLONG_MAX));
    auto dfs = [&](auto& dfs, int cur)->void { // dp
        if (left[cur]!=-1) {dfs(dfs,left[cur]);}
        if (right[cur]!=-1) {dfs(dfs,right[cur]);}

        v<ll> l = (left[cur]!=-1 ? dp[left[cur]] : v<ll>(63,1));
        v<ll> r = (right[cur]!=-1 ? dp[right[cur]] : v<ll>(63,1));
        v<ll> conv(126);
        merge(l.rbegin(),l.rend(),r.rbegin(),r.rend(),conv.rbegin());

        F0R(i,62) { // transitions
            chmin(dp[cur][i],max(conv[i],a[cur]));
            chmin(dp[cur][i+1],(dp[cur][i]+b[cur]-1)/b[cur]);
        }
    };

    int rt = n-1;
    for (int i=n-1;i>=0;i--) { // find root of tree
        if (b[i]<b[rt]) {rt = i;}
    }
    dfs(dfs,rt);

    F0R(i,62) {
        if (dp[rt][i]==1) {cout << i << '\n'; return;}
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}