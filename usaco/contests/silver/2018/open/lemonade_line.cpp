#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("lemonade.in","r",stdin);
    freopen("lemonade.out","w",stdout);
    int n; cin >> n;
    int w[n];
    for (int i=0;i<n;i++) {
        cin >> w[i];
    }
    sort(w, w+n, greater<>());
    for (int i=0;i<n;i++) {
        if (w[i] < i) {cout << i << "\n"; return 0;}
    }
    cout << n << "\n";
}
