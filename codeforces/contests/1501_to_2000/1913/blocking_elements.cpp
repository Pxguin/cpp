#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,ll>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define vec vector

const int MAX_N = 1e5;
ll a[MAX_N+1], dp[MAX_N+1], nxt[MAX_N+1], ps[MAX_N+1];

void solve() {
    int n; cin >> n;
    for (int i=0;i<n;i++) {cin >> a[i];}
    a[n] = 0; ps[0] = a[0];
    for (int i=1;i<=n;i++) {ps[i] = ps[i-1]+a[i];}

    ll lo = 0, hi = 1e14, mid = (lo+hi)/2;
    auto check = [&](ll x) {
        for (int i=0;i<=n;i++) {dp[i] = 1e15;}

        for (int i=0;i<=n;i++) {if (ps[i]-a[i]<=x) {dp[i] = a[i];}}
        multiset<ll> mn;
        priority_queue<pii,vec<pii>,greater<pii>> todo;
        
        for (int i=0;i<=n;i++) {
            while (todo.size() && todo.top().f==i) {
                mn.erase(mn.find(todo.top().s));
                todo.pop();
            }
            if (mn.size()) {chmin(dp[i],*mn.begin()+a[i]);}
            todo.push({upper_bound(ps,ps+n,ps[i]+x)-ps+1,dp[i]});
            mn.insert(dp[i]);
        }
        return dp[n];
    };

    ll ans = 0;
    while (lo <= hi) {
        if (mid>=check(mid)) {ans = mid; hi = mid-1;}
        else {lo = mid+1;}
        mid = (lo+hi)/2;
    }
    cout << min(max(check(ans),ans),max(check(ans-1),ans-1)) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}