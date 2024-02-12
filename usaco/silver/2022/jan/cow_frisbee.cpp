#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define ll long long

int n;
ll ans = 0;
void solve(vector<int>& h) {
    set<int> x;
    vector<int> idx(n);
    for (int i=0;i<n;i++) {idx[h[i]] = i;}
    for (int i=n;i>0;--i) {
        auto it = x.insert(idx[i]).first;
        if (++it != x.end()) {ans += (ll)(*it-idx[i]+1);}
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    vector<int> h(n);
    for (int& i : h) {cin >> i;}
    solve(h);
    reverse(h.begin(), h.end());
    solve(h);
    cout << ans << "\n";
}