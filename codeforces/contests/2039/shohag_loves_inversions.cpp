#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define v vector

ll mod = 998244353;
ll add(ll a, ll b) {return (a+b)%mod;}
ll mul(ll a, ll b) {return a*b%mod;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;

    v<ll> dp(1e6+1,0), ans(1e6+1,0);
    dp[4] = 2;
    ll mulsum = dp[4]*4, sumsum = 2+3;

    for (int i=5;i<=1e6;i++) { // dp (# such that max != num inversions)
        dp[i] = add(mulsum,sumsum);
        sumsum = add(sumsum,i-1);
        mulsum = add(mulsum,mul(dp[i],i));
    }

    ll dpsum = 0;
    for (int i=2;i<=1e6;i++) { // add # such that max = num inversions
        dpsum = add(dpsum,dp[i]);
        ans[i] = add(dpsum,i-1);
    }
    
    while (t--) {
        int n; cin >> n;
        cout << ans[n] << '\n';
    }
}