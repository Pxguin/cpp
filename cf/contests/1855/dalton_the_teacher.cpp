#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    
    for (int c=0;c<t;c++) {
        int n; cin >> n;
        int chair;
        int ans = 0;
        for (int i=0;i<n;i++) {
            cin >> chair;
            if (chair == i+1) {ans++;}
        }
        cout << (ans+1)/2 << "\n";
    }
}