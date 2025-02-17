#include <bits/stdc++.h>
using namespace std;

#define chmax(a, b) a = max(a,b)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

const int MAX_N = 262144, l2d = 60;
int l[l2d][MAX_N+1], r[l2d][MAX_N+1];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("262144.in","r",stdin);
    freopen("262144.out","w",stdout);

    int n; cin >> n;
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));

    int ans = 0;
    F0R(i,n) {
        int a; cin >> a;
        l[a][i] = r[a][i] = i;
        chmax(ans,a);
    }
    FOR(p,1,l2d) {
        F0R(i,n) {
            if (r[p][i]!=-1 && l[p][i+1]!=-1) { // if left and right are both valid
                l[p+1][r[p][i]] = l[p][i+1]; // then combine them into a larger range
                r[p+1][l[p][i+1]] = r[p][i];
                chmax(ans,p+1);
            }
        }
    } cout << ans << '\n';
}