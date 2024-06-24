#include <iostream>
using namespace std;
 
void solve() {
    int n; long long c; cin >> n >> c;
    long long paintings[n];
    for (int i=0;i<n;i++) {cin >> paintings[i];}
    
    long long l = 0, h = 1e9, w = (l+h)/2;

    while (l <= h) {
        long long total = 0;
        for (long long sz : paintings) {
            total += (sz+w*2)*(sz+w*2);
            if (total > c) {break;}
        }
        if (total == c) {
            cout << w << "\n"; 
            return;
        } else if (total < c) {
            l = w+1;
        } else {h = w-1;}
        w = (l+h)/2;
    }
}
 
int main() {
    int t; cin >> t;
    while (t--) {solve();}
}