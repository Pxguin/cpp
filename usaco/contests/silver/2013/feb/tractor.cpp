#include <iostream>
#include <cstdlib>
using namespace std;

int field[500][500];
bool visited[500][500];
int comp_size = 0;
bool visit_bool = false;
int n;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int d;

void ff(int r, int c) {
    if(visited[r][c] != visit_bool) {return;}
    comp_size++;
    visited[r][c] = !visit_bool;

    for (int i=0;i<4;i++) {
        int r1 = r+dx[i]; int c1 = c+dy[i];
        if ((r1 >= 0 && r1 < n && c1 >= 0 && c1 < n)
        && (abs(field[r1][c1] - field[r][c]) <= d)) {
            ff(r1,c1);
        }
    }
}

bool check() {
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            comp_size = 0;
            ff(i,j);
            if (comp_size >= (n*n+1)/2) {return true;}
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    freopen("tractor.in","r",stdin);freopen("tractor.out","w",stdout);
    cin >> n;
    int high = 0;
    int last_success;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> field[i][j];
            visited[i][j] = false;
            high = max(field[i][j],high);
        }
    }

    int low = 0;

    while (low <= high) {
        d = (low+high)/2;
        if (check()) {
            last_success = d;
            high = d-1;
        } else {
            low = d+1;
        }

        visit_bool = !visit_bool;
    }
    cout << last_success;

}