#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("gymnastics.in","r",stdin);
    freopen("gymnastics.out","w",stdout);
    
    int k, n; cin >> k >> n;
    v<v<int>> rank(n,v<int>(k));
    F0R(i,k) {
        F0R(j,n) {
            int cow; cin >> cow;
            rank[cow-1][i] = j; // rank array
        }
    }
    int ans = 0;
    F0R(cow1,n) {
        F0R(cow2,n) {
            int ok = 1;
            F0R(i,k) {ok &= (rank[cow1][i]>rank[cow2][i]);} // if cow1 did better than cow2
            ans += ok;
        }
    } cout << ans << '\n';
}