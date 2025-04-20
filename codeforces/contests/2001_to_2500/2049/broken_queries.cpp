#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define vec vector

void solve() {
    int n; cin >> n;

    int a1, a2;
    cout << "? " << 1 << ' ' << n/4 << endl;
    cout << "? " << n/4+1 << ' ' << n/2 << endl;
    cin >> a1 >> a2;
    int half = (a1==a2); // is the one in the first or second half

    int lo = 2, hi = n-1, mid = (lo+hi)/2, ans; // binary search on k
    while (lo<=hi) {
        int x, ok;
        if ((mid>=n/2)^half) { // query the prefix
            cout << "? " << 1 << ' ' << mid << endl;
            cin >> x;
            ok = (x==half);
        } else { // query the suffix
            cout << "? " << n-mid+1 << ' ' << n << endl;
            cin >> x;
            ok = (x!=half);
        }
        if (ok) {hi = mid-1; ans = mid;}
        else {lo = mid+1;}
        mid = (lo+hi)/2;
    } cout << "! " << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {solve();}
}