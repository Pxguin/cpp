#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

void solve() {
    int k; cin >> k;
    v<int> n(k);
    priority_queue<int,v<int>> pq;
    F0R(i,k) {
        cin >> n[i];
        F0R(j,n[i]-1) {int a; cin >> a;}
        pq.push(n[i]);
    }
    int ans = 0, bit = 20;
    while (pq.size()&&bit>=0) { // fill in bits high to low
        if (pq.top()<(1<<bit)) {bit--;} // numbers aren't big enough for this bit
        else { // add this bit in
            int x = pq.top(); pq.pop();
            if (x>=(1<<(bit+1))) {x = (1<<(bit+1))-1;} // make sure x has this bit active (actually pointless in retrospect)
            x ^= (1<<bit); ans |= (1<<bit); // turn the bit off (in retrospect, use x -= (1<<bit))
            bit--;
            pq.push(x);
        }
    } cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}