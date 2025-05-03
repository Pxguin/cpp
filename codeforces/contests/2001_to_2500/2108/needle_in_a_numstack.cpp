#include <bits/stdc++.h>
using namespace std;

#define vec vector

int query(int i) {
    cout << "? " << i+1 << endl;
    int x; cin >> x;
    return x;
}

void solve() {
    int n, k; cin >> n >> k;

    int idx1 = 0;
    vec<int> pref(k), suff(k);
    for (int i=0;i<k;i++) {
        pref[i] = query(i); // prefix: the period composed of the first k numbers
        suff[(n-i-1)%k] = query(n-i-1);
    }
    
    int start = 0;
    idx1 = n;
    for (int i=n-1;i>=n-k;i--) { // find an index that changes values across periods
        if (pref[i%k]!=query(i)) {start = i%k;}
    }
    int lo = 1, hi = (n-1-start)/k, mid = (lo+hi)/2;
    while (lo <= hi) { // find the earliest period where that index has a different value that in the prefix
        if (query(mid*k+start)!=pref[start]) {
            idx1 = mid*k+start;
            hi = mid-1;
        } else {lo = mid+1;}
        mid = (lo+hi)/2;
    }
    
    for (int i=1,j=idx1-1;i<k;i++,j--) { // find the earliest index that goes against the prefix
        if (pref[j%k]!=query(j)) {idx1 = j;}
    }
    idx1 = min(idx1,n-k);

    if (idx1==k || query(idx1-1)!=suff[(idx1-1)%k]) {cout << "! " << idx1 << ' ' << n-idx1 << endl;} // if exactly one possibility for split, then ok
    else {cout << "! -1" << endl;} // otherwise, -1
}

int main() {
    int t; cin >> t;
    while (t--) {solve();}
}