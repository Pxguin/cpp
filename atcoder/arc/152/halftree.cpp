#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k; cin >> n >> k;
    if (n%2==0) {
        cout << -1;
    } else {
        cout << n/2 << '\n';
        int g = gcd(n,k);
        int cur = 0, nxt = (cur+k/g)%(n/g);
        for (int i=0;i<n/g/2;i++) {
            for (int j=cur*g;j<(cur+1)*g-1;j+=2) { // thick edges
                cout << j << ' ' << j+1 << '\n';
            }
            for (int j=0;j<g;j+=2) { // thin edges
                cout << cur*g+j << ' ' << nxt*g+j << '\n';
            }
            if (i==n/g/2-1) { // if it's last group
                for (int j=nxt*g+1;j<(nxt+1)*g-1;j+=2) { // (other set of) vertical edges
                    cout << j << ' ' << j+1 << '\n';
                }
            }
            cur = (nxt+k/g)%(n/g); nxt = (cur+k/g)%(n/g);
        }
    }
}