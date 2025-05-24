#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    int cnt[8] = {0};
    for (int i=0;i<n;i++) {
        int a; cin >> a;
        cnt[a]++;
    }
    bool nosol = false;

    if (cnt[5] || cnt[7] || cnt[1]!=n/3) {nosol = true;}
    if (cnt[6]<cnt[3] || cnt[2]!=n/3-cnt[3]) {nosol = true;}
    if (nosol) {cout << -1;}
    else {
        for (int i=0;i<cnt[3];i++) {cout << "1 3 6" << '\n';}
        for (int i=0;i<cnt[6]-cnt[3];i++) {cout << "1 2 6" << '\n';}
        for (int i=0;i<cnt[4];i++) {cout << "1 2 4" << '\n';}
    }
}