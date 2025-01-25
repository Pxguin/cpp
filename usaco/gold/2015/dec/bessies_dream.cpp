#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int dist[1000][1000][4][2];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("dream.in","r",stdin);
    freopen("dream.out","w",stdout);

    int n, m; cin >> n >> m;
    v<v<int>> a(n,v<int>(m));
    F0R(i,n) {
        F0R(j,m) {cin >> a[i][j];}
    }
    F0R(i,n) F0R(j,m) F0R(d,4) F0R(s,2) {dist[i][j][d][s] = INT_MAX;}
    queue<pair<int,array<int,4>>> q;
    dist[0][0][0][0] = 0;
    q.push({0,{0,0,0,0}});

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    auto oob = [&](int x, int y, int smell) { // is this tile passable
        return (x<0 || x==n || y<0 || y==m || a[x][y]==0 || (!smell && a[x][y]==3));
    };
    auto check = [&](int x, int y, int dir, int smell, int d) { // do a check for bfs
        if (dist[x][y][dir][smell]==INT_MAX) {
            q.push({-(dist[x][y][dir][smell]=d+1),{x,y,dir,smell}});
        }
    };
    while (q.size()) {
        auto [d,cur] = q.front(); q.pop();
        auto [x,y,dir,smell] = cur;

        if (a[x][y]==4 && !(oob(x+dx[dir],y+dy[dir],smell))) { // are we forced to slide on the purple tile
            check(x+dx[dir],y+dy[dir],dir,smell,-d);
        } else { // we can choose which direction to go
            F0R(i,4) {
                if (oob(x+dx[i],y+dy[i],smell)) {continue;}
                int nx = x+dx[i], ny = y+dy[i];

                if (a[nx][ny]==1) {check(nx,ny,i,smell,-d);}
                else if (a[nx][ny]==2) {check(nx,ny,i,1,-d);}
                else if (a[nx][ny]==3) {check(nx,ny,i,smell,-d);}
                else if (a[nx][ny]==4) {check(nx,ny,i,0,-d);}
            }
        }
    }
    int ans = INT_MAX;
    F0R(i,4) {F0R(j,2) {chmin(ans,dist[n-1][m-1][i][j]);}}
    cout << (ans==INT_MAX ? -1 : ans) << '\n';
}