#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmin(a, b) a = min(a,b)

const int N = 1e5, R = 19;
ll a[N+1];
ll dist[R+1], dp[1<<R][R];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    for (int i=0;i<(1<<R);i++) {for (int j=0;j<R;j++) {dp[i][j] = LLONG_MAX;}}

    ll l, r, n, k; cin >> l >> r >> n >> k;
    for (int i=0;i<n;i++) {cin >> a[i+1]; a[i+1] = l-a[i+1];}
    sort(a+1,a+n+1);
    a[0] = a[n]-l;

    for (int i=0;i<r;i++) { // dist[i]: move i robot positions clockwise
        ll cw = l/r*i, ccw = l-cw;
        ll t_cw = (cw*k+k)/(k+1), t_ccw = (k==1 ? LLONG_MAX : (ccw*k+k-2)/(k-1));
        dist[i] = min(t_cw,t_ccw);
    }
    
    for (int i=0;i<r-1;i++) {dp[1<<i][i] = dist[i+1];}

    for (int mask=1;mask<(1<<(r-1));mask++) {
        for (ll last=0;last<r-1;last++) {
            if (!((1<<last)&mask)) {continue;}
            dp[mask][last] = (dp[mask][last]+k-1)/k*k; // round up to nearest multiple of k
            int passed = dp[mask][last]/k;
            
            ll t = *(upper_bound(a,a+n+1,(((last+1)*l/r - passed)%l +l)%l) -1); // wait for next activation point to pass by
            t = (((last+1)*l/r -(t+passed)) %l+l)%l;

            dp[mask][last] += t*k; // round up dp value to the next time that activation point passes by
            for (int nxt=0;nxt<r-1;nxt++) { // transitions
                if ((1<<nxt)&mask) {continue;}
                chmin(dp[mask|(1<<nxt)][nxt],dp[mask][last]+dist[(nxt+r-last)%r]);
            }
        }
    }

    ll ans = LLONG_MAX;
    for (int i=0;i<r-1;i++) {chmin(ans,(ll)dp[(1<<(r-1))-1][i]);}
    cout << ans << '\n';
}