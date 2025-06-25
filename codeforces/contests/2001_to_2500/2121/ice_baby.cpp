#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    multiset<int> sleep;
    sleep.insert(0);

    for (int i=0;i<n;i++) {
        int l, r; cin >> l >> r;
        auto it = sleep.upper_bound(r); // when shifting the range right one index, we overwrite the index after the rightmost index in range
        if (it!=sleep.end()) {sleep.erase(it);} // so delete that index
        sleep.insert(l); // shift range to the right and replace leftmost with l_i
        
        cout << sleep.size()-1 << ' '; // size of lnds
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}