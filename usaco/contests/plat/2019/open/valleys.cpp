#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define f first
#define s second

const int MAX_N = 1000;
int n;

pii par1[MAX_N][MAX_N]; // dsu 1: maintains holes
int sz1[MAX_N][MAX_N];
bool bad[MAX_N][MAX_N] = {false}; // does the component touch a border (if so then it isn't a hole)
int hole_delta[MAX_N*MAX_N+1] = {0}; // keeps track of delta of # of holes

pii par2[MAX_N][MAX_N]; // dsu 2: maintains regions
int sz2[MAX_N][MAX_N], holes[MAX_N][MAX_N];

int h[MAX_N][MAX_N];
pii srt[MAX_N*MAX_N];

int main() {
    freopen("valleys.in","r",stdin);
    freopen("valleys.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0);

    memset(sz1,-1,sizeof(sz1));
    memset(sz2,-1,sizeof(sz2));

    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> h[i][j];
            srt[i*n+j] = make_pair(i,j);
        }
    }

    // maintaining all holes with DSU
    sort(srt,srt+n*n,[&](pii& a, pii& b) {return h[a.f][a.s]>h[b.f][b.s];});
    for (int i=0;i<n;i++) { // all components that touch a border are not holes
        bad[0][i] = bad[n-1][i] = bad[i][0] = bad[i][n-1] = true;
    }
    function<pii(pii)> get1 = [&](pii x)->pii {return (par1[x.f][x.s]==x ? x : par1[x.f][x.s]=get1(par1[x.f][x.s]));};
    for (int i=0;i<n*n;i++) {
        auto[x,y] = srt[i];
        hole_delta[n*n-i-1] = !bad[x][y]; // +1 hole if cell is not touching a border, +0 otherwise
        sz1[x][y] = 1; par1[x][y] = srt[i]; // initialize states for {x,y}
        
        for (int x2=x-1;x2<=x+1;x2++) { // for all pointwise reachable cells
            for (int y2=y-1;y2<=y+1;y2++) {
                if ((x2==x&&y2==y) || x2<0 || y2<0 || x2>=n || y2>=n) {continue;}
                if (sz1[x2][y2]==-1) {continue;} // make sure it's valid

                auto[a,b] = get1({x2,y2}); auto[c,d] = get1(srt[i]);
                if (a==c && b==d) {continue;}
                if (!(bad[a][b]&&bad[c][d])) {hole_delta[n*n-i-1]--;} // merge the two components, update hole count

                if (sz1[a][b]<sz1[x][y]) {swap(a,c); swap(b,d);} // update all other variables
                par1[c][d] = {a,b};
                sz1[a][b] += sz1[c][d];
                bad[a][b] |= bad[c][d];
            }
        }
    }

    // maintain all regions with DSU
    reverse(srt,srt+n*n);
    ll ans = 0;
    function<pii(pii)> get2 = [&](pii x)->pii {return (par2[x.f][x.s]==x ? x : par2[x.f][x.s]=get2(par2[x.f][x.s]));};
    for (int i=0;i<n*n;i++) {
        auto[x,y] = srt[i];
        holes[x][y] = hole_delta[i]; // adding this cell creates hole_delta[i] holes (all of which belong to this cell's component)
        sz2[x][y] = 1; par2[x][y] = srt[i];

        for (int x2=x-1;x2<=x+1;x2++) { // merge with all edgewise reachable cells
            for (int y2=y-1;y2<=y+1;y2++) {
                if ((x2!=x&&y2!=y) || (x2==x&&y2==y) || x2<0 || y2<0 || x2>=n || y2>=n) {continue;}
                if (sz2[x2][y2]==-1) {continue;}

                auto[a,b] = get2({x2,y2}); auto[c,d] = get2(srt[i]);
                if (a==c && b==d) {continue;}
                
                if (sz2[a][b]<sz2[c][d]) {swap(a,c); swap(b,d);}
                par2[c][d] = {a,b};
                sz2[a][b] += sz2[c][d];
                holes[a][b] += holes[c][d]; // sum up holes
            }
        }
        auto[a,b] = get2({x,y});
        if (holes[a][b]==0) {ans += sz2[a][b];} // if no holes, then this region is a valley
    } cout << ans << '\n';
}