#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define chmin(a, b) a = min(a,b)
#define all(x) x.begin(),x.end()
#define vec vector

const int N = 1000;
int mn[N][N], mn2[N][N];
int dist[N][N], wt[N][N];
bool scare[N][N] = {false};

double isect(pii a, pii b) {return (double)(a.s-b.s)/(b.f-a.f);}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    int px, py, kx, ky; cin >> px >> py >> kx >> ky;
    px--; py--; kx--; ky--;
    
    int c; cin >> c;
    for (int i=0;i<c;i++) {
        int a, b; cin >> a >> b;
        scare[--a][--b] = true;
    }
    
    for (int i=0;i<n;i++) { // cell (i,j): closest scarecrow to (i,j) with same j
        for (int j=0;j<m;j++) {
            mn[i][j] = mn2[n-i-1][j] = 1e7;
            if (i && mn[i-1][j]!=1e7) {mn[i][j] = mn[i-1][j]+1;}
            if (scare[i][j]) {mn[i][j] = 0;}
            if (i && mn2[n-i][j]!=1e7) {mn2[n-i-1][j] = mn2[n-i][j]+1;}
            if (scare[n-i-1][j]) {mn2[n-i-1][j] = 0;}
        }
    }
    for (int i=0;i<n;i++) {
        vec<pii> q;
        for (int j=0;j<m;j++) { // only possible scarecrows to consider at those from mn[i]
            chmin(mn[i][j],mn2[i][j]);
            if (mn[i][j]!=1e7) {
                pii line = {-2*j,mn[i][j]*mn[i][j]+j*j};
                while (q.size()>1 && isect(line,q.back())<=isect(q.back(),q[q.size()-2])) {q.pop_back();}
                q.pb(line);
            }
        }
        reverse(all(q));
        for (int j=0;j<m;j++) { // get closest scarecrow to all in row i with CHT
            while (q.size()>1 && isect(q.back(),q[q.size()-2])<=j) {q.pop_back();}
            dist[i][j] = q.back().f*j+q.back().s+j*j;
        }
    }
    
    using T = pair<int,pii>;
    priority_queue<T> pq;
    int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
    pq.push({wt[px][py]=dist[px][py],{px,py}});
    while (pq.size()) { // dijkstra to find max min edge weight from start to finish
        auto[w,z] = pq.top(); pq.pop();
        auto[x,y] = z;
        if (w!=wt[x][y]) {continue;}
        for (int i=0;i<4;i++) {
            int nx = dx[i]+x, ny = dy[i]+y;
            if (nx==-1 || nx==n || ny==-1 || ny==m) {continue;}
            if (min(w,dist[nx][ny])>wt[nx][ny]) {
                pq.push({wt[nx][ny]=min(w,dist[nx][ny]),{nx,ny}});
            }
        }
    }
    cout << wt[kx][ky] << '\n';
}
