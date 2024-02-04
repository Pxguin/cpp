#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        if (a == b) {cout << c;}
        else if (b == c) {cout << a;}
        else {cout << b;}
        cout << "\n";
    }
}
