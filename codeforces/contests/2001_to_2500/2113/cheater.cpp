#include <bits/stdc++.h>
using namespace std;

#define vec vector

void solve() {
    int n; cin >> n;
    vec<int> a(n), b(n);
    for (int i=0;i<n;i++) {cin >> a[i];}
    for (int i=0;i<n;i++) {cin >> b[i];}

    set<int> rem, cur, dealer; // rem: suffix; cur: prefix; dealer: dealer's hand
    for (int i=0;i<n;i++) {
        rem.insert(a[i]);
        dealer.insert(b[n-i-1]);
    }
    int ans = 0;

    rem.erase(a[0]); cur.insert(a[0]);
    for (int i=0;i<n;i++) {
        int del = *cur.begin(), add = del;
        if (rem.size() && *rem.rbegin()>del) {add = *rem.rbegin();}

        cur.erase(del); cur.insert(add); // replace minimum with max on suffix

        if (*cur.begin()>*dealer.begin()) { // does it work
            ans = i+1;
        }

        if (i!=n-1) { // update prefix suffix
            cur.erase(add); cur.insert(del);
            rem.erase(a[i+1]); cur.insert(a[i+1]);
            dealer.erase(b[n-i-1]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}