#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>
using namespace std;

#define ll long long
#define f first
#define s second

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m, k; cin >> n >> m >> k;

    ll ans = 0;
    deque<pair<ll,ll>> t;

    ll w, a;
    vector<pair<ll,ll>> cows;
    for (int i=0;i<n;i++) {
        cin >> w >> a;
        cows.emplace_back(w,a);
    }
    sort(cows.begin(), cows.end(), greater<>());

    t.emplace_back(LLONG_MAX, m);
    for (auto& p : cows) {
        int initial = p.s;
        auto i = t.front();
        while (p.s > 0 && !t.empty() && p.f <= i.f-k) {
            if (p.s >= i.s) {
                p.s -= i.s;
                t.pop_front();
                i = t.front();
            } else {
                t.pop_front();
                t.emplace_front(i.f, i.s-p.s);
                p.s = 0;
            }
        }
        ll used = initial-p.s;
        ans += used;
        if (used > 0) {t.emplace_back(p.f, used);}
    }
    cout << ans << "\n";
}