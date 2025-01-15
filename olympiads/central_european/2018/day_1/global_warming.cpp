#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, d; cin >> n >> d;

    v<int> dp, dp2; // dp1 is without adding, dp2 is with adding
    int pos;
    auto doit = [&](v<int>& arr, int a) { // update lis array
        pos = lower_bound(all(arr),a)-arr.begin();
        if (pos==arr.size()) {arr.pb(a);}
        else {arr[pos] = a;}
    };

    F0R(i,n) {
        int a; cin >> a;
        doit(dp2,a+d); // update dp2
        doit(dp,a); // update dp1
        
        if (pos==dp2.size()) {dp2.pb(dp[pos]);} // transition from dp1 to dp2
        else {chmin(dp2[pos],dp[pos]);}
    }
    
    cout << dp2.size() << '\n';
}