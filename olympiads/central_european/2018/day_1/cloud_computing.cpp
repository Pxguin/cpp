#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, c, f, val; cin >> n;
    v<pair<int,pii>> pool;
    F0R(i,n) {
        cin >> c >> f >> val;
        pool.pb({f,{val,c}});
    }
    int m; cin >> m;
    F0R(i,m) {
        cin >> c >> f >> val;
        pool.pb({f,{-val,-c}});
    }
    sort(all(pool));

    ll ans = 0;
    v<ll> dp(2000*50+1,LLONG_MIN);
    dp[0] = 0;

    while (pool.size()) {
        pii x = pool.back().s; pool.pop_back();
        
        if (x.s>0) {
            for (int i=2000*50;i>=0;i--) { // computer order
                if (dp[i]!=LLONG_MIN && i+x.s>=0) {
                    chmax(dp[i+x.s],dp[i]-x.f);
                }
            }
        } else {
            F0R(i,2000*50+1) { // customer order
                if (dp[i]!=LLONG_MIN && i+x.s>=0) {
                    chmax(dp[i+x.s],dp[i]-x.f);
                }
            }
        }
        
    }
    for (ll i : dp) {chmax(ans,i);}
    cout << ans << '\n';
}