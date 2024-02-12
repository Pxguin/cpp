#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct PCL {
    int i, j, i2, j2;
};

vector<vector<char>> img;
vector<vector<bool>> vis;
unordered_set<char> colors;
vector<PCL> pcls;

void ff(int y, int x, int& i, int& j, int& i2, int& j2, char& col) {
    if (vis[y][x] || img[y][x] != col) {return;}
    vis[y][x] = true;
    if (y < i2) {ff(y+1,x,i,j,i2,j2,col);}
    if (y > i) {ff(y-1, x, i, j, i2, j2, col);}
    if (x < j2) {ff(y, x+1, i, j, i2, j2, col);}
    if (x > j) {ff(y, x-1, i, j, i2, j2, col);}
}

bool works(int& i, int& j, int& i2, int& j2) {
    colors.clear();
    int regions[26] = {0};
    for (int y=i;y<=i2;y++) {
        for (int x=j;x<=j2;x++) {
            if (!vis[y][x]) {
                ff(y, x, i, j, i2, j2, img[y][x]);
                colors.insert(img[y][x]);
                regions[img[y][x]-'A']++;
            }
        }
    }
    bool c1 = false; bool c2 = false;
    for (int z : regions) {
        if (z == 1) {c1 = true;}
        if (z >= 2) {c2 = true;}
    }

    return (c1 && c2 && colors.size() == 2);
}

bool check(int& x, int& y) {
    return (pcls[x].i2 <= pcls[y].i2 && pcls[x].i >= pcls[y].i
    && pcls[x].j2 <= pcls[y].j2 && pcls[x].j >= pcls[y].j);
}

int main() {
    freopen("where.in","r",stdin);
    freopen("where.out","w",stdout);
    int n; cin >> n;
    img.resize(n);
    vis.resize(n);
    char col;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> col;
            img[i].push_back(col);
            vis[i].push_back(false);
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            for (int i2=i;i2<n;i2++) {
                for (int j2=j;j2<n;j2++) {
                    if (works(i,j,i2,j2)) {
                        PCL pcl = {i,j,i2,j2};
                        pcls.push_back(pcl);
                    }
                    for (int x=i;x<=i2;x++) {
                        for (int y=j;y<=j2;y++) {vis[x][y] = false;}
                    }
                }
            }
        }
    }
    int ans = pcls.size();

    for (int x=0;x<pcls.size();x++) {
        for (int y=0;y<pcls.size();y++) {
            if (x != y && check(x, y)) {
                ans--; break;
            }
        }
    }
    cout << ans << "\n";
}