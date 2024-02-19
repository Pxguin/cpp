#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("angry.in", "r", stdin); freopen("angry.out", "w", stdout);
    int n, k; cin >> n >> k; int loc;
    vector<int> bales;
    for (int i=0;i<n;i++) {cin >> loc; bales.push_back(loc);}
    sort(bales.begin(), bales.end());

    long r = 1;
    long target = 0;
    int res = 0;
    int available_cows = k;

    int range = r * 2;

    int l, h, m;

    while (true) {
        l = res+1;
        h = bales.size()-1;
        m = (l+h)/2;
        target = bales[res]+range;

        while (true) {
            if (l > h) {
                m = l;
                break;
            }
            if (bales[m] > target) {h = m-1;}
            else if (bales[m] < target) {l = m+1;}
            else {m++; break;}

            m = (l+h)/2;
        }

        res = m;
        available_cows--;

        if (res >= bales.size()) {
            break;
        } else {
            if (available_cows == 0) {
                r++;
                available_cows = k;
                res = 0;
                target = 0;
                range += 2;
            }
        }
    }
    cout << r;
}