#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

bool solve() {
    int n; cin >> n;
    v<int> a(n), b(n);
    int nogood = -1, mn = INT_MAX;
    F0R(i,n) {cin >> a[i];}
    F0R(i,n) {
        cin >> b[i];
        if (a[i]<b[i]) {
            if (nogood!=-1) {mn = -2;} // fail if missing more than one type of resource
            else {nogood = b[i]-a[i];}
        } else {chmin(mn,a[i]-b[i]);} // find minimum amount of crafts possible
    } return mn>=nogood; // if we can craft enough
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {cout << (solve() ? "YES" : "NO") << '\n';}
}