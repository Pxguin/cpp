#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<int> x(n);
    F0R(i,n) {cin >> x[i];}
    
    v<int> dp;
    F0R(i,n) {
        int pos = lower_bound(all(dp),x[i])-dp.begin();
        if (pos==dp.size()) {dp.pb(x[i]);}
        else {dp[pos]=x[i];}
    } cout << dp.size() << '\n';
}