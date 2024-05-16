#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define s second
#define f first
#define pii pair<int,int>

bool solve() {
    int n, k; cin >> n >> k;
    pii a[n];
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for (int i=0;i<n;i++) {cin >> a[i].s;}
    for (int i=0;i<n;i++) {cin >> a[i].f; a[i].f = abs(a[i].f);}
    for (pii i : a) {pq.push(i);}
    
    int rounds = 0;
    int cur = k;
    while (pq.size()) {
        pii q = pq.top(); pq.pop();
        if (cur >= q.s) {
            cur -= q.s;
        } else {
            q.s -= cur; cur = 0;
            pq.push(q);
        }
        if (cur == 0) {cur = k; rounds++;}
        if (pq.size() && rounds >= pq.top().f) {return false;}
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while (t--) {cout << (solve() ? "YES" : "NO") << '\n';}
}
