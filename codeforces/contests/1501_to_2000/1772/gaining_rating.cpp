#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

void solve() {
    int n; ll x, y; cin >> n >> x >> y;
    v<ll> a(n);
    F0R(i,n) {cin >> a[i];}
    sort(all(a));

    ll ptr = upper_bound(all(a),x)-a.begin();
    ll d = ptr-(n-ptr);
    ll ans = 0;
    
    while (x!=y) {
        ll done = -1, time = -1;

        if (y-x<=ptr) {done = 0;} // min cycles needed to get to Y rating (-1 if impossible)
        else if (d>0) {
            done = (y-x-ptr + d-1)/d;
        }

        if (ptr<n) { // min cycles needed to beat this opponent
            if (a[ptr]-x<=ptr) {time = 0;}
            else if (d>0) {
                time = (a[ptr]-ptr-x+d-1)/d;
            }
        }

        if (time<0 && done<0) { // if none can happen, return false
            ans = -1; 
            break;
        } else if (time<0 || (done<=time && done>=0)) { // we get to skill level Y first
            x += done*d; 
            ans += done*n;
            ans += min(y-x,ptr); 
            x = y;
        } else { // we beat the opponent first
            x += time*d; 
            ans += time*n;
            d += 2; 
            ptr++;
        }
    } cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}