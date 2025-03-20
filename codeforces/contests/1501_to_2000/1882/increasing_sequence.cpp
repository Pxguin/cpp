#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    for (int z=0;z<t;z++) {
        int n; cin >> n;
        long a;
        long b = 0;
        for (int i=0;i<n;i++) {
            cin >> a;
            b++;
            if (a == b) {b++;}
        }
        cout << b << "\n";
    }
}
