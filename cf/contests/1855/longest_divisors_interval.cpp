#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    
    for (int z=0;z<t;z++) {
        long long n; cin >> n;
        long long ans = -1;
        for (int i=1;i<=n/2+1;i++) {
            if (n%i != 0) {ans = i-1; break;}
        }
        if (ans == -1) {ans = n;}
        cout << ans << "\n";
    }
}