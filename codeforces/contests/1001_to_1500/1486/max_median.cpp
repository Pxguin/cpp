#include <iostream>
#include <vector>
using namespace std;

vector<int> a; int n, k;

bool check(int m) {
    vector<int> d(n+1, 0), ss(n+1, INT_MIN);
    int h = 0, l = 0;
    for (int i=0;i<n;i++) {
        h += (a[i]>=m); l += (a[i]<m);
        d[i+1] = h-l;
    }
    for (int i=n-1;i>=0;i--) {ss[i]=max(ss[i+1],d[i+1]);}
    for (int i=0;i<=n-k;i++) {
        if (ss[i+k-1]-d[i] > 0) {return true;}
    } return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> k; a.resize(n);
    int l = INT_MAX, h = 0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        h = max(h, a[i]); l = min(l, a[i]);
    }

    int m = (l+h)/2; int ans;
    while (l <= h) {
        if (check(m)) {l = m+1; ans = m;}
        else {h = m-1;}
        m = (l+h)/2;
    }
    cout << ans << '\n';
}