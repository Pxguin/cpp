#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)

const int N = 1e5, l2d = 18;
int lift[l2d][N];
int x[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    for (int i=0;i<l2d;i++) {
        for (int j=0;j<N;j++) {lift[i][j] = N;}
    }
    
    int n; cin >> n;
    for (int i=0;i<n;i++) {cin >> x[i];}

    int l; cin >> l;
    for (int i=0;i<n-1;i++) {lift[0][i] = upper_bound(x,x+n,x[i]+l)-x-1;}
    for (int b=1;b<l2d;b++) {
        for (int i=0;i<n;i++) {
            if (lift[b-1][i]!=N) {lift[b][i] = lift[b-1][lift[b-1][i]];}
        }
    }

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (a>b) {swap(a,b);}

        int ans = INT_MAX, cur = 0;
        for (int i=l2d-1;i>=0;i--) {
            if (lift[i][a]<b) {
                a = lift[i][a];
                cur += (1<<i);
            } else {
                chmin(ans,cur+(1<<i));
            }
        } cout << ans << '\n';
    }
}