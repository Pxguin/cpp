#include <bits/stdc++.h>
using namespace std;

#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    v<int> x(n), y(n);
    F0R(i,n) {cin >> x[i];}
    F0R(i,n) {cin >> y[i];}
    int ans = 0;
    F0R(i,n) {
        FOR(j,i+1,n) {
            chmax(ans,(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
        }
    } cout << ans << '\n';
}