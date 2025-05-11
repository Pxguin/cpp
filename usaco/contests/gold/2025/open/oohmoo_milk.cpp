#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX_N = 1e5, mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll n, d, a, b; cin >> n >> d >> a >> b;
    ll m[MAX_N];
    for (int i=0;i<n;i++) {cin >> m[i];}

    sort(m,m+n);
    ll rem = b*d;
    int r = n-1, l = n-1;
    ll reachsinglelimit, movetonext, outofmoves;

    while (rem) {
        reachsinglelimit = (m[l]-(m[r]-d)-1)*(r-l+1)+1; // case 1: we have subtracted from the rightmost index D times already
        movetonext = (l==n-a ? LLONG_MAX : (m[l]-m[l-1])*(r-l+1)); // case 2: the interval extends by 1
        outofmoves = rem; // case 3: we run out of moves

        if (outofmoves<=min(reachsinglelimit,movetonext)) { // if we run out of moves first
            for (int i=r;i>=l;i--) { // update all the values in the interval with their final values
                m[i] = m[l];
                m[i] -= rem/(r-l+1);
                m[i] -= (i<=rem%(r-l+1)+l-1);
            } rem = 0;
        } else if (reachsinglelimit<=min(movetonext,outofmoves)) { // if we have subtracted D from rightmost first
            rem -= m[l]-(m[r]-d); // update rem
            m[r] -= d; // final value of rightmost pointer
            r--; // remove rightmost from the interval
        } else { // we extend the interval first
            rem -= movetonext; // it costs this many moves until we extend interval
            l--; // extend interval
        }
    }
    ll ans = 0;
    for (int i=n-1;i>=n-a;i--) {m[i] += d;} // add D to each of the A largest values
    for (int i=0;i<n;i++) {ans = (ans+m[i]*m[i])%mod;} // calc answer
    cout << ans << '\n';
}