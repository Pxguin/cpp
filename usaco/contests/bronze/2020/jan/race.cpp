#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("race.in","r",stdin);
    freopen("race.out","w",stdout);

    ll k; cin >> k;
    const int MAX_X = 1e5;
    ll ans[MAX_X+1];
    for (ll top=1,dist=1,dec=1; top<=MAX_X; top++,dist+=top) { // find min finish speed achievable for each top speed
        if (k-dist<0) {ans[top] = LLONG_MAX; continue;} 

        while ((dec+top-1)*(top-dec)/2-dec>=k-dist) {
            dec++;
        }
        ans[top] = dec;
    }

    int n; cin >> n;
    for (int i=0;i<n;i++) { // find maximum top speed such that the finish speed is <= X
        ll x; cin >> x;
        ll mx = upper_bound(ans+1,ans+MAX_X+1,x)-ans-1;
        x = min(x,mx);
        ll dist = (mx*(mx+1)+(x+mx-1)*(mx-x))/2, sec = mx+(mx-x); // do some math to calc # seconds to finish
        sec += (k-dist+(mx-1))/mx;
        cout << sec << '\n';
    }
}