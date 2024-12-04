#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<pii> x(n);
    F0R(i,n) {cin >> x[i].f >> x[i].s;}
    sort(all(x),greater<>());

    v<int> dp;
    for (pii i : x) { // find lds
        int pos = lower_bound(all(dp),i.s)-dp.begin();
        if (pos==dp.size()) {dp.pb(i.s);}
        else {dp[pos]=i.s;}
    } cout << dp.size() << '\n';
}