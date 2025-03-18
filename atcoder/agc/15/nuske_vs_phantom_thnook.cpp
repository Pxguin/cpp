#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    const int MAX_S = 2000;
    bool grid[MAX_S+1][MAX_S+1] = {false};
    int ps[MAX_S+1][MAX_S+1] = {0};
    int hor[MAX_S+1][MAX_S+1] = {0}, ver[MAX_S+1][MAX_S+1] = {0};

    int n, m, q; cin >> n >> m >> q;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            char c; cin >> c;
            grid[i+1][j+1] = (c=='1');
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            ps[i][j] = ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]; // ps[i][j] = num components (1,1) to (i,j)
            if (grid[i-1][j] && grid[i][j-1] && grid[i][j]) {ps[i][j]--;} // case: merge the two comps together
            else if (!grid[i-1][j] && !grid[i][j-1] && grid[i][j]) {ps[i][j]++;} // case: new comp

            if (grid[i][j] && grid[i-1][j]) {hor[i][j]++;} // number of components crossing row border
            hor[i][j] += hor[i][j-1];

            if(grid[i][j] && grid[i][j-1]) {ver[j][i]++;} // same thing but for column
            ver[j][i] += ver[j][i-1];
        }
    }
    while (q--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int ans = ps[x2][y2]-ps[x2][y1-1]-ps[x1-1][y2]+ps[x1-1][y1-1]; // this gives the amount components that start in rect (x1,y1), (x2,y2)
        ans += hor[x1][y2]-hor[x1][y1-1]; // this calculates the missing components (ones that start on the top and left borders)
        ans += ver[y1][x2]-ver[y1][x1-1];
        cout << ans << '\n';
    }
}