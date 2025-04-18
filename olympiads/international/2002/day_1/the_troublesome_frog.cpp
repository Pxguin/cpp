#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define chmax(a, b) a = max(a,b)

const int MAX_N = 5000;
pii pts[MAX_N];
bool idx[MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int r, c, n; cin >> r >> c >> n;
    for (int i=0;i<n;i++) {cin >> pts[i].f >> pts[i].s;}
    sort(pts,pts+n);

    for (int i=0;i<n;i++) {idx[--pts[i].f][--pts[i].s] = true;}

    int ans = 0;

    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            int x = pts[i].f-(pts[j].f-pts[i].f), y = pts[i].s-(pts[j].s-pts[i].s);
            if (x>=0 && y>=0 && y<c) {continue;} // make sure that this is the start of the chain

            bool flag = false;
            int cur = 0;
            for (int x2=pts[i].f,y2=pts[i].s;x2<r&&y2>=0&&y2<c;x2+=(pts[j].f-pts[i].f),y2+=(pts[j].s-pts[i].s)) {
                if (!idx[x2][y2]) {flag = true; break;} // make sure all plants in this line are flattened
                cur++;
            }
            if (!flag && cur>2) {chmax(ans,cur);}
        }
    } cout << ans << '\n';
}