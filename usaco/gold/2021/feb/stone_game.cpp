#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    v<int> a(n), ps(2e6+1);
    F0R(i,n) {
        cin >> a[i];
        ps[a[i]]++;
    }
    F0R(i,2e6) {ps[i+1] += ps[i];}
    ll ans = 0;
    FOR(x,1,1e6+1) {
        int cand = 0, flag = 0, idx = 0;
        for (int j=2*x;j<=2e6;j+=x) { // count occurences of each unique B
            if (ps[j-1]-ps[j-x-1]&1) {
                if (cand) {flag++;} // specifically keep track of odd occurences
                cand = ps[j-1]-ps[j-x-1], idx = j;
            } 
        }
        if (!flag && idx==2*x) {ans += cand;} // casework: if it's possible to remove one and make everything even
        else if (flag==1 && (ps[idx-x-1]-ps[idx-2*x-1])&1) {ans += cand;}
    } cout << ans << '\n';
}