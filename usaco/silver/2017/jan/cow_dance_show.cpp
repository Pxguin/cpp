#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, t;
vector<int> d;
multiset<int> cur;

bool check(int k) {
    cur.clear();

    int prev;
    for (int i=0;i<k;i++) {cur.insert(d[i]);}
    for (int i=k;i<n;i++) {
        prev = *cur.begin();
        if (d[i]+prev > t) {return false;}

        cur.erase(cur.begin());
        cur.insert(d[i]+prev);
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("cowdance.in","r",stdin);
    freopen("cowdance.out","w",stdout);

    cin >> n >> t;
    d.resize(n);
    for (int& i : d) {cin >> i;}

    int l = 1; int h = n; int k = (l+h)/2;
    int ans = 0;

    while (l <= h) {
        if (check(k)) {
            h = k-1;
            ans = k;
        } else {l = k+1;}
        k = (l+h)/2;
    }
    cout << ans << "\n";
}