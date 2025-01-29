#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n, q; cin >> n >> q;
    v<int> r(q), c(q); 
    v<char> t(q);
    F0R(i,q) {
        cin >> r[i] >> c[i] >> t[i];
    }
    v<v<bool>> state(n+2,v<bool>(n+2,false)); // is the node in a good component
    v<v<char>> dir(n+2,v<char>(n+2,'?'));
    int good = 0;

    auto ff = [&](auto& ff, int row, int col)->void { // set this entire component to be good
        if (state[row][col]) {return;}
        state[row][col] = true; 
        good++;
        if (row<=n && (dir[row+1][col]=='U' || dir[row+1][col]=='?')) {ff(ff,row+1,col);}
        if (row && (dir[row-1][col]=='D' || dir[row-1][col]=='?')) {ff(ff,row-1,col);}
        if (col && (dir[row][col-1]=='R' || dir[row][col-1]=='?')) {ff(ff,row,col-1);}
        if (col<=n && (dir[row][col+1]=='L' || dir[row][col+1]=='?')) {ff(ff,row,col+1);}
    };
    F0R(i,q) {
        dir[r[i]][c[i]] = t[i];
    }
    F0R(i,n+2) { // flood fill from the borders
        dir[0][i] = 'D'; ff(ff,0,i);
        dir[n+1][i] = 'U'; ff(ff,n+1,i);
        dir[i][0] = 'R'; ff(ff,i,0);
        dir[i][n+1] = 'L'; ff(ff,i,n+1);
    }
    v<int> ans(q);
    for (int i=q-1;i>=0;i--) {
        ans[i] = n*n-(good-4*(n+1));
        int row = r[i], col = c[i];
        dir[row][col] = '?';
        if (!state[row][col]) { // if the cell was already good, then leave it alone; else, check if any neighbors are good (if so, then this cell can be good as well)
            if (state[row][col-1] || state[row][col+1] || state[row-1][col] || state[row+1][col]) {ff(ff,row,col);} 
        }
    }
    cout << 0 << '\n';
    FOR(i,1,q) {cout << ans[i] << '\n';}
}