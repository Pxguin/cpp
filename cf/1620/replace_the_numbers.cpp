#include <iostream>
using namespace std;

#define mp make_pair
#define s second
#define f first

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q; cin >> q;
    int t, x, y;
    pair<int,int> a[q];
    int map[500001];
    int k = 0;
    for (int i=0;i<q;i++) {
        cin >> t >> x;
        if (t == 1) {
            a[i] = mp(x, -1);
            map[x] = x;
            k++;
        } else {
            cin >> y;
            a[i] = mp(x, y);
            map[y] = y;
        }
    }
    int ans[k];

    for (int i=q-1;i>=0;i--) {
        if (a[i].s != -1) {
            map[a[i].f] = map[a[i].s];
        } else {
            ans[--k] = map[a[i].f];
        }
    }
    for (int i : ans) {cout << i << " ";}
}