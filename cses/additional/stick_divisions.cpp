#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int x, n; cin >> x >> n;
    v<int> d(n);
    F0R(i,n) {cin >> d[i];}
    priority_queue<int,vector<int>,greater<int>> pq;
    F0R(i,n) {pq.push(d[i]);}

    ll ans = 0;
    while (pq.size()>1) {
        int c1 = pq.top(); pq.pop(); // take smallest two and combine them
        int c2 = pq.top(); pq.pop();
        ans += c1+c2;
        pq.push(c1+c2);
    } cout << ans << '\n';
}