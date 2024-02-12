#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<pair<int,int>>>> graph;
vector<int> comps;
vector<vector<bool>> vis;
vector<vector<int>> cows;
int n;

void ff(int x, int y, int p1, int p2, int& c) {
    if (x < 0 || x == n || y < 0 || y == n || vis[x][y]) {
        return;
    }
    for (pair<int,int> p : graph[p1][p2]) {
        if (p == make_pair(x,y)) {return;}
    }
    comps[c] += cows[x][y];
    vis[x][y] = true;

    ff(x+1,y,x,y,c);
    ff(x-1,y,x,y,c);
    ff(x,y+1,x,y,c);
    ff(x,y-1,x,y,c);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("countcross.in","r",stdin);
    freopen("countcross.out","w",stdout);

    int k, r; cin >> n >> k >> r;
    graph.resize(n);
    vis.resize(n);
    cows.resize(n);

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cows[i].push_back(0);
            graph[i].emplace_back();
            vis[i].push_back(false);
        }
    }

    int x, y, x2, y2;
    // cin roads
    for (int i=0;i<r;i++) {
        cin >> x >> y >> x2 >> y2;
        x--; y--; x2--; y2--;
        graph[x][y].emplace_back(x2, y2);
        graph[x2][y2].emplace_back(x, y);
    }

    // cin cows
    for (int i=0;i<k;i++) {
        cin >> x >> y; x--; y--;
        cows[x][y]++;
    }

    // ff
    int cn = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {

            if (!vis[i][j]) {
                comps.push_back(0);
                ff(i,j,i,j,cn);
                cn++;
            }
        }
    }


    long long ans = 0;
    for (int comp : comps) {
        ans += comp*(k-comp);
    }
    cout << ans/2 << "\n";

    /*
     * how to store graph and roads?
     * simple list should work.
     * need to store in a 2d array
     */

    /*
     * store the amount of cows in each square;
     * when flood filling for components add a sum for every component;
     * check every component against every component to get ans
     */
}