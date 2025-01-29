#include <iostream>
#include <vector>
using namespace std;

int barn[1001][1001];
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("paintbarn.in","r",stdin);
    freopen("paintbarn.out","w",stdout);

    int n, k; cin >> n >> k;
    int x1, y1, x2, y2;
    for (int i=0;i<n;i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        barn[x1][y1]++;
        barn[x2][y2]++;
        barn[x1][y2]--;
        barn[x2][y1]--;
    } // concept of setting x2, y2 to 1 so that when it reaches it,
    // it cancels out the second -1 that is also reached.

    int ans = 0;
    for (int i=0;i<1001;i++) {
        for (int j=0;j<1001;j++) {
            if (i > 0) {barn[i][j] += barn[i-1][j];}
            if (j > 0) {barn[i][j] += barn[i][j-1];}
            if (i > 0 && j > 0) {barn[i][j] -= barn[i-1][j-1];}
            if (barn[i][j] == k) {ans++;}
        }
    }
    // concept of building 2d sums, or sums in general, while calculating the answer
    // because all sums depend on the previous numbers.
    cout << ans << "\n";
}