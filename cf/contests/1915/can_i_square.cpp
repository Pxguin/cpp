#include <iostream>
#include <cmath>
using namespace std;
 
void solve() {
    string s;
    int n; cin >> n;
    long long t = 0;
    long long a;
    for (int i=0;i<n;i++) {cin >> a; t += a;}
    if (floor(sqrt(t)) == sqrt(t)) {
        cout << "YES\n";
    } else {cout << "NO\n";}
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {solve();}
}
