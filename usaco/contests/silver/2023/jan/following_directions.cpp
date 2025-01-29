#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n;

    vector<vector<int>> grid(n+1);
    vector<vector<int>> freq(n+1);

    char dir;
    int c;

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> dir;
            grid[i].push_back(dir == 'R' ? -1 : -2); // -1 = Right. -2 = Down.
            freq[i].push_back(1);
        }
        cin >> c; grid[i].push_back(c);
        freq[i].push_back(0);
    }
    for (int i=0;i<n;i++) {
        cin >> c;
        grid[n].push_back(c);
        freq[n].push_back(0);
    }

    ll ans = 0;

    for (int i=0;i<n+1;i++) {
        for (int j=0;j<n+1;j++) {
            if (i) {
                if (grid[i-1][j] == -2) {freq[i][j] += freq[i-1][j];}
            }
            if (j) {
                if (grid[i][j-1] == -1) {freq[i][j] += freq[i][j-1];}
            }
            if (i == n || j == n) {
                ans += freq[i][j]*grid[i][j];
            }
        }
    }

    cin >> q;
    cout << ans << "\n";
    int x, y;
    for (int i=0;i<q;i++) {
        cin >> x >> y; x--; y--;
        int x2 = x; int y2 = y;

        int cows = freq[x][y];
        while (x < n && y < n) {
            if (grid[x][y] == -1) {y++;}
            else if (grid[x][y] == -2) {x++;}
            freq[x][y] -= cows;
        }
        ans -= grid[x][y]*cows;
        x = x2; y = y2;
        grid[x][y] = (grid[x][y] == -1 ? -2 : -1);
        while (x < n && y < n) {
            if (grid[x][y] == -1) {y++;}
            else if (grid[x][y] == -2) {x++;}
            freq[x][y] += cows;
        }
        ans += grid[x][y]*cows;
        cout << ans << "\n";
    }
}