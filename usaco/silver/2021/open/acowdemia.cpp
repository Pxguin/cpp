#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, l;
vector<int> c;

bool check(int h) {
    long long sum = 0;
    for (int i=0;i<h;i++) {
        sum += max(0,h-c[i]);
    }
    if (sum <= (long long)k*l && c[h-1]+k >= h) {return true;}
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k >> l;
    c.resize(n);

    for (int i=0;i<n;i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end(), greater<>());

    int low = 0; int high = n; int m = (low+high)/2;
    int ans = 0;

    while (low <= high) {
        if (check(m)) {
            ans = m;
            low = m+1;
        } else {high = m-1;}
        m = (low+high)/2;
    }
    cout << ans << "\n";
}