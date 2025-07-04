#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)

const int N = 20;
bool grid[N][N];
int dist[N][N][N][N][4][4];
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

const int base = 1e9;

struct state {
    int x1, y1, x2, y2, d1, d2;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("cownav.in","r",stdin);
    freopen("cownav.out","w",stdout);
    
    int n; cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            char c; cin >> c;
            grid[n-i-1][j] = (c=='H');
        }
    }
    memset(dist,0,sizeof(dist));
    dist[0][0][0][0][0][1] = -base;
    queue<state> q;
    q.push((state){0,0,0,0,0,1});

    auto upd = [&](state x, int d) {
        if (dist[x.x1][x.y1][x.x2][x.y2][x.d1][x.d2]==0) {
            dist[x.x1][x.y1][x.x2][x.y2][x.d1][x.d2] = d;
            q.push(x);
        }
    };
    while (q.size()) {
        state cur = q.front(); q.pop();
        int d = dist[cur.x1][cur.y1][cur.x2][cur.y2][cur.d1][cur.d2];
         
        // turn right
        state nxt = cur;
        nxt.d1 = (nxt.d1+1)%4; nxt.d2 = (nxt.d2+1)%4;
        upd(nxt,d+1);

        // turn left
        nxt = cur;
        nxt.d1 = (nxt.d1+3)%4; nxt.d2 = (nxt.d2+3)%4;
        upd(nxt,d+1);

        // move
        nxt = cur;
        if (nxt.x1!=n-1 || nxt.y1!=n-1) {
            int nx = nxt.x1+dx[nxt.d1], ny = nxt.y1+dy[nxt.d1];
            if (!(min(nx,ny)==-1 || max(nx,ny)==n || grid[nx][ny])) {nxt.x1 = nx; nxt.y1 = ny;}
        }
        if (nxt.x2!=n-1 || nxt.y2!=n-1) {
            int nx = nxt.x2+dx[nxt.d2], ny = nxt.y2+dy[nxt.d2];
            if (!(min(nx,ny)==-1 || max(nx,ny)==n || grid[nx][ny])) {nxt.x2 = nx; nxt.y2 = ny;}
        }
        upd(nxt,d+1);
    }

    int ans = 0;
    for (int i=0;i<4;i++) {
        for (int j=0;j<4;j++) {
            chmin(ans,dist[n-1][n-1][n-1][n-1][i][j]);
        }
    } cout << ans+base << '\n';
}