#include <bits/stdc++.h>
using namespace std;

#define v vector

void solve() {
    int n, m; cin >> n >> m;
    set<int> trains;
    v<int> a(n);
    for (int i=0;i<n;i++) { // make initial trains
        cin >> a[i];
        if (trains.size() && a[*trains.rbegin()]<=a[i]) {continue;}
        else {trains.insert(i);}
    }
    while (m--) {
        int k, d; cin >> k >> d;
        a[--k] -= d;
        auto it = --trains.upper_bound(k);
        if (a[*it] > a[k] || *it==k) { // does this form a new train/is the existing head of a train
            trains.insert(k);
            it = trains.lower_bound(k);
            while (it!=prev(trains.end()) && a[*next(it)]>=a[k]) { // join this train together with later trains while possible
                trains.erase(next(it));
            }
        }
        cout << trains.size() << ' ';
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}