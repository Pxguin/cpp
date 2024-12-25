#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
#define f first
#define s second
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define all(x) x.begin(),x.end()
#define v vector

void solve() {
    int n; cin >> n;
    v<pii> e(n);
    F0R(i,n) {cin >> e[i].f >> e[i].s; e[i].f += e[i].s;} // sort by s+t
    sort(all(e));

    priority_queue<ll> pq;
    ll tot = 0;
    for (pii x : e) {
        auto [st,t] = x;
        tot += t; pq.push(t); // add to set
        if (tot > st) { // remove largest t from set if necessary
            tot -= pq.top(); pq.pop();
        }
    } cout << pq.size() << '\n'; // size of set = answer
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}