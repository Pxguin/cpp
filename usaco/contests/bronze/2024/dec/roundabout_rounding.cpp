#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        
        ll lb = 5, ub = 4, ans = 0;
        for (ll i=1;i<=1e9;i*=10) {
            ub = ub*10+9; // upper bound, 4999...
            lb = 4*(i*10)+lb; // lower bound, 444...5
            ans += max(0LL,min(ub,n)-max(2LL,lb)+1); // intersection
        } cout << ans << '\n';
    }
}