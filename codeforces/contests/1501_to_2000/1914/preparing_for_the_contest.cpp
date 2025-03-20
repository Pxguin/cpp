#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        for (int i=n-k;i<=n;i++) {cout << i << ' ';}
        for (int i=1;i<n-k;i++) {cout << n-k-i << ' ';}
        cout << '\n';
    }
}