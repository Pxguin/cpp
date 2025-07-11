#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second

const int N = 3e5;
pii a[N], b[N];
set<int> used, rem;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    for (int i=0;i<n;i++) {cin >> a[i].f >> a[i].s;}
    sort(a,a+n);
    for (int i=n-1;i>=0;i--) { // b[i].s = d[i]; b[i].f = c[i]
        b[i].s = i; 
        b[i].f = lower_bound(a,a+n,make_pair(a[i].s,-1))-a;
    }
    sort(b,b+n);

    bool flag = false;
    int ans = 0, last = n;

    for (int i=n-1;i>=0;i--) { // greedy assignment
        for (int j=b[i].f;j<last;j++) {rem.insert(j);} // rem: stores set of mutable unassigned indices; used: mutable assigned

        if (rem.count(b[i].s)) { // if d[i] is unassigned mutable, then assign it
            rem.erase(b[i].s);
            ans++;
        } else if (used.count(b[i].s) && rem.upper_bound(b[i].s)!=rem.end()) { // if it's possible to assign to optimal index by shifting all other assignments
            used.erase(b[i].s);
            used.insert(*rem.upper_bound(b[i].s));
            rem.erase(rem.upper_bound(b[i].s));
            ans++;
        } else { // if it's not possible, assign it the earliest unassigned mutable index
            if (rem.empty()) {flag = true; break;} // this is the fail case
            used.insert(*rem.begin());
            rem.erase(rem.begin());
        }
        last = b[i].f;
    } cout << (flag ? -1 : ans) << '\n';
}