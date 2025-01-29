#include <iostream>

using namespace std;

bool has_cow[3000][3000];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int ans = 0;

void add_cows(int r, int c) {
    if (!has_cow[r][c]) {return;}
    int neighbors = 0;
    int r1; int c1;
    for (int i=0;i<4;i++) {
        if (has_cow[r+dx[i]][c+dy[i]]) {
            neighbors++;
        } else {r1 = r+dx[i]; c1 = c+dy[i];}
    }
    if (neighbors == 3) {
        has_cow[r1][c1] = true;
        ans++;
        add_cows(r1, c1);
        add_cows(r1-1,c1);
        add_cows(r1+1,c1);
        add_cows(r1,c1-1);
        add_cows(r1,c1+1);
    }
}

int main() {
    ios::sync_with_stdio(true);cin.tie(nullptr);
    int n; cin >> n;
    int r; int c;

    for (int i=0;i<n;i++) {
        cin >> r >> c;
        r += 1000; c += 1000;
        if (has_cow[r][c]) {
            ans--;
        } else {has_cow[r][c] = true;}
        add_cows(r,c);
        add_cows(r-1,c);
        add_cows(r+1,c);
        add_cows(r,c+1);
        add_cows(r,c-1);
        cout << ans << "\n";
    }
}