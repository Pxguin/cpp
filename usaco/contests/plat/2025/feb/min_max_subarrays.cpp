#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define vec vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vec<ll> a(n+2);
    vec<int> l(n+2), r(n+2), l2(n+2), sl(n+2), sr(n+2);
    vec<vec<int>> freq(n+1);

    for (int i=0;i<n;i++) {
        cin >> a[i+1];
        freq[a[i+1]].pb(i+1);
    }

    a[0] = a[n+1] = INT_MAX;
    set<int> s = {0,n+1};
    for (int i=n;i;i--) { // find nearest largest (and second nearest largest) values on left and right
        for (int j=0;j<freq[i].size();j++) {
            int x = freq[i][j];
            auto b = s.lower_bound(x);
            l[x] = *prev(b); r[x] = *b;
            sl[x] = (l[x]==0 ? 0 : *prev(prev(b))); sr[x] = (r[x]==n+1 ? n+1 : *next(b));
            l2[x] = l[x];
            if (j) {chmax(l2[x],freq[i][j-1]); chmin(r[freq[i][j-1]],x); chmin(sr[freq[i][j-1]],x);}
        }
        for (int x : freq[i]) {s.insert(x);}
    }
    
    ll ans = 0;

    bool dp[64] = {false};
    auto solve = [&](int k) { // brute forces answer for all subarrays of length k
        for (int i=1;i<=n-k+1;i++) {
            memset(dp,false,sizeof(dp));
            dp[(1<<k)-1] = true;
            ll ret = 0;
            for (int mask=(1<<k)-1;mask;mask--) { // mask = subset of indices that still remain
                if (!dp[mask]) {continue;}
                if (__builtin_popcount(mask)==1) { // if only one index remains
                    for (int j=0;j<k;j++) {
                        if ((1<<j)&mask) {chmax(ret,a[i+j]);}
                    }
                } else {
                    int prev = -1;
                    for (int j=0;j<k;j++) {
                        if ((1<<j)&mask) { // brute force all pairs to choose for the next operation
                            if (prev!=-1) {dp[mask^((__builtin_popcount(mask)&1)^(a[i+prev]<a[i+j]) ? (1<<j) : (1<<prev))] = true;}
                            prev = j;
                        }
                    }
                }
            } ans += ret;
        }
    };

    for (int i=1;i<=n-2;i++) {ans += (a[i+1]>max(a[i],a[i+2]) ? max(a[i],a[i+2]) : max(max(a[i],a[i+1]),a[i+2]));} // brute force k=3
    solve(4); solve(6);

    for (int i=1;i<=n;i++) {
        ans += a[i]*((r[i]-i+1)/2)*((i-l[i]+1)/2); // even on right, even on left
        ans += a[i]*((r[i]-i)/2)*((i-l[i])/2); // odd on right, odd on left
        ans -= a[i]*max(0,min(i+3,r[i])-i -max(0,l[i]-(i-3))); // subtract ones of length 3

        if (a[r[i]]!=INT_MAX && a[r[i]]!=a[i]) { // max is to the right
            int diff = (r[i]-i)&1;

            ans += a[i]*((sr[i]-r[i]+1)/2)*((i-l[i]+diff)/2); // even R, odd L
            ans += a[i]*((sr[i]-r[i])/2)*((i-l[i]+1-diff)/2); // odd R, even L

            for (int j=4;j<=6;j+=2) { // sub ones of length 4, 6
                if (r[i]-i+1<=j) {
                    ans -= a[i]*max(0,min(i+j,sr[i])-r[i] -max(0,l[i]-(r[i]-j)));
                }
            }
        }

        if (a[l2[i]]!=INT_MAX) { // max is to the left
            int diff = (i-l2[i])&1;

            ans += a[i]*((r[i]-i+1)/2)*((l2[i]-sl[i]+diff)/2); // even R, odd L
            ans += a[i]*((r[i]-i)/2)*((l2[i]-sl[i]+1-diff)/2); // odd R, even L

            for (int j=4;j<=6;j+=2) { // sub len 4, 6
                if (i-l2[i]+1<=j) {
                    ans -= a[i]*max(0,min(l2[i]+j,r[i])-i -max(0,sl[i]-(i-j)));
                }
            }
        }
    }
    cout << ans << '\n';
}