#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    int a[n];
    for (int i=0;i<n;i++) {cin >> a[i];}
    sort(a, a+n);
    int sum = 0;
    int p1 = 0;
    while (sum <= x && p1 < n) {
        sum += a[p1++];
    }
    if (sum > x) {p1--;}
    cout << p1 << "\n";
}