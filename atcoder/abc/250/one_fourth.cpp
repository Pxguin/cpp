#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmin(a, b) a = min(a,b)

const int MAX_N = 1e5;
ll x[2*MAX_N], y[2*MAX_N];
ll ps[2*MAX_N+1] = {0};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    for (int i=0;i<n;i++) {
        cin >> x[i] >> y[i];
        x[i+n] = x[i];
        y[i+n] = y[i];
    }

    for (int i=0;i<2*n-1;i++) { // shoelace theorem/determinants
        ps[i+1] = ps[i]+x[i]*y[i+1]-x[i+1]*y[i];
    }
    ll area = abs(ps[n]);
    ll best = LLONG_MAX;
    for (int i=0;i<n;i++) { // fix first point to cut cake
        int lo = 3, hi = n-1, mid = (lo+hi)/2;
        int res = hi;
        while (lo <= hi) { // binary search on best second point
            ll cand = 4*abs(ps[i+mid-1]-ps[i]+x[i+mid-1]*y[i]-x[i]*y[i+mid-1]);
            if (cand>=area) { // check in o(1) with shoelace theorem
                res = mid; hi = mid-1;
            } else {lo = mid+1;}
            mid = (lo+hi)/2;
        }
        chmin(best,abs(4*abs(ps[i+res-1]-ps[i]+x[i+res-1]*y[i]-x[i]*y[i+res-1])-area)); // update answer
        if (res!=3) {
            chmin(best,abs(4*abs(ps[i+res-2]-ps[i]+x[i+res-2]*y[i]-x[i]*y[i+res-2])-area));
        }
        
    }
    cout << best << '\n';
}