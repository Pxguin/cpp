#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define f first
#define s second

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("mountains.in","r",stdin);
    freopen("mountains.out","w",stdout);

    vector<ll> mount;
    vector<pair<ll,ll>> start;
    int n; cin >> n;
    int ans = n;

    ll x,y;
    for (int i=0;i<n;i++) {
        cin >> x >> y;
        mount.push_back(x+y);
        start.emplace_back(x-y, i);
    }
    sort(start.begin(), start.end());

    auto m = start[0];
    for (int i=1;i<n;i++) {
        auto m2 = start[i];
        if (mount[m2.s] > mount[m.s]) {
            if (m2.f == m.f) {ans--;}
            m = m2;
        } else {ans--;}
    } cout << ans << "\n";
}