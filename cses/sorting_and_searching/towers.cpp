#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    v<int> k(n);
    F0R(i,n) {cin >> k[i]; k[i]*=-1;} // multiply by -1 so I check < instead of >

    multiset<int> towers;
    F0R(i,n) {
        auto it = towers.lower_bound(k[i]); // find biggest block > this block (I check < because mult k by -1)
        if (it!=towers.begin()) {towers.erase(--it);} // if a block exists then place it on top of that
        towers.insert(k[i]);
    } cout << towers.size() << '\n';
}