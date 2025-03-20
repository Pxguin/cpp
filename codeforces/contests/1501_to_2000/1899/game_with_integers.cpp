#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t; int n;
    while(t--) {
        cin >> n;
        cout << (n%3==0 ? "Second" : "First") << "\n";
    }
}