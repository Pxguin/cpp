#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
vector<int> p;
vector<int> s;

bool check(int t) {
    int p1 = 0;
    int p2 = 0;
    while (p1 < p.size()) {
        int cur;
        cur = max(0, p[p1] - s[p2]);
        if (cur > t) {return false;}
        bool flag = false;
        while (p2 < s.size()) {
            if (s[p2] > p[p1]) {
                if (min(cur*2+s[p2]-p[p1], cur+(s[p2]-p[p1])*2) > t) {flag = true; break;}
            } p2++;
        }
        if (!flag) {return true;}
        p1++;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;

    char z;
    for (int i=0;i<n;i++) {
        cin >> z;
        if (z == 'P') {p.push_back(i);}
        else if (z == '*') {s.push_back(i);}
    }

    int l = 1; int h = 2*n; int m = (l+h)/2;
    int ans = INT_MAX;

    while (l <= h) {
        if (check(m)) {
            h = m-1;
            ans = m;
        } else {l = m+1;}
        m = (l+h)/2;
    }
    cout << ans << "\n";
}