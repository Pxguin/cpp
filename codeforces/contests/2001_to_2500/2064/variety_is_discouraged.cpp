#include <bits/stdc++.h>
using namespace std;

#define vec vector

void solve() {
    int n; cin >> n;
    vec<int> a(n), freq(n);
    for (int i=0;i<n;i++) {cin >> a[i]; freq[--a[i]]++;}

    int al = 0, ar = -1;
    for (int r=0,l=0;r<n;r++) {
        if (freq[a[r]]==1 && r-l>ar-al) {al = l; ar = r;} // extend subarray if a[r] is distinct in the array
        else if (freq[a[r]]!=1) {l = r+1;} // reset subarray if a[r] is not distinct
    }
    if (ar==-1) {cout << 0 << '\n';}
    else {cout << al+1 << ' ' << ar+1 << '\n';} // return max length subarray
}

int main() {
    int t; cin >> t;
    while (t--) {solve();}
}