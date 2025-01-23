#include <bits/stdc++.h>
using namespace std;

#define chmin(a, b) a = min(a,b)
#define F0R(i, a) for (int i = 0; i < (a); i++)

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("ssdj.in","r",stdin);
    freopen("ssdj.out","w",stdout);
    
    int n; cin >> n;
    char a[1001][1001];
    F0R(i,1001) {F0R(j,1001) {a[i][j] = 'A';}}
    F0R(i,n) {
        F0R(j,n) {
            cin >> a[i][j];
        }
    }

    int h[1001];
    int ans = 0, dup = 0;
    auto solve = [&]() {
        for (char ch='a';ch<='z';ch++) {
            memset(h,0,sizeof(h));
            F0R(r,n) {
                F0R(c,n) {
                    if (a[r][c]<=ch) {h[c]++;}
                    else {h[c] = 0;}
                }

                int last = n, mn = 0;
                for (int c=n-1;c>=0;c--) { // optimization instead of stack (same idea)
                    if (a[r][c]==ch) {last = c; mn = h[c];}
                    
                    if (h[c]<mn && h[c]!=0) {
                        ans++;
                        dup += (a[r-h[c]][c]==ch);
                    }
                    chmin(mn,h[c]);
                }
                F0R(c,n) {
                    if (a[r][c]==ch) {h[c] = 0;}
                }
            }
        }
    };
    solve();
    // mirror
    F0R(i,n) {reverse(a[i],a[i]+n);}
    reverse(a,a+n);
    solve();

    cout << ans-(dup/2) << '\n';
}