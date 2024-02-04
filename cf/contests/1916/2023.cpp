#include <iostream>
#include <cmath>
using namespace std;
 
#define ll long long
#define ld long double
 
void solve() {
    int n, k; cin >> n >> k;
    ll p = 1; int b; 
    for (int i=0;i<n;i++) {cin >> b; p *= b;}
    ld d = (ld)2023/p;
    if (floor(d) != d) {cout << "NO\n";return;}
    cout << "YES\n"; cout << d;
    while (--k) {cout << " " << 1;}cout << "\n";
    
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {solve();}
}