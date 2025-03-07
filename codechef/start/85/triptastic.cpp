#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define chmax(a, b) a = max(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define vec vector

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vec<vec<int>> a(n,vec<int>(m));
    vec<vec<ll>> ps(n+1,vec<ll>(m+1,0));
    F0R(i,n) {
        F0R(j,m) {
            cin >> a[i][j];
            ps[i+1][j+1] = a[i][j];
        }
    }
    F0R(i,n) { // prefix sum setup
        F0R(j,m) {
            ps[i+1][j+1] += ps[i+1][j]+ps[i][j+1]-ps[i][j];
        }
    }
    auto get = [&](int x1, int y1, int x2, int y2) {
        return ps[x2+1][y2+1]-ps[x1][y2+1]-ps[x2+1][y1]+ps[x1][y1];
    };
    int l = 0, h = max(n,m), mid = (l+h)/2, ans = -1; // binary search on distance
    while (l <= h) {
        ll mx = 0;
        F0R(i,n) { // fix the room of the mentor
            F0R(j,m) {
                if (a[i][j]==0) {continue;} // make sure there's space for the mentor
                chmax(mx,get(max(0,i-mid),max(0,j-mid),min(n-1,i+mid),min(m-1,j+mid))); // bounds for where students can go
            }
        }
        if (mx>k) {h = mid-1; ans = mid;} // if > K spots in some room then ok
        else {l = mid+1;}
        mid = (l+h)/2;
    } cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}