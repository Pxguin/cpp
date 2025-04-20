#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define vec vector

void solve() {
    int n; cin >> n;
    vec<int> a(n);
    vec<ll> pts;
    F0R(i,n) {cin >> a[i];}
    sort(all(a));

    F0R(i,n-1) {
        if (a[i]==a[i+1]) {
            pts.pb(a[i]); // each coordinate appears twice so remove pairs of same coordinate while possible
            i++;
        }
    }
    if (pts.size()<4) {cout << "NO";} // need at least 4 coordinates
    else {
        cout << "YES\n";
        int m = pts.size(); // optimal pairing: first with third and second with fourth
        cout << pts[0] << ' ' << pts[m-1] << ' ' << pts[m-2] << ' ' << pts[m-1] << ' ';
        cout << pts[0] << ' ' << pts[1] << ' ' << pts[m-2] << ' ' << pts[1];
    }
    cout << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) {solve();}
}