#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
 
void solve() {
    int n; cin >> n;
    int a[n];
    int mn = 0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        if (a[i] < a[mn]) {
            mn = i;
        }
        
    }
    
    for (int i=mn+1;i<n;i++) {
        if (a[i] < a[i-1]) {
            mn = -1;
            break;
        }
    }
    cout << mn << "\n";
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {solve();}
}