#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    freopen("bcs.in","r",stdin);
    freopen("bcs.out","w",stdout);
    
    int n, k; cin >> n >> k;
    char c1;
    v<v<v<bool>>> g(k+1,v<v<bool>>(n,v<bool>(n)));
    F0R(i,k+1) {
        F0R(r,n) {
            F0R(c,n) {
                cin >> c1;
                g[i][r][c] = (c1=='#');
            }
        }
    }
    FOR(p1,1,k+1) { // piece 1
        FOR(p2,p1+1,k+1) { // piece 2
            for (int s1=-n+1;s1<n;s1++) { // s1 and s3 specify first piece shift
                for (int s2=-n+1;s2<n;s2++) { // s2 and s4, second piece shift
                    for (int s3=-n+1;s3<n;s3++) {
                        for (int s4=-n+1;s4<n;s4++) {
                            v<v<bool>> cand(n,v<bool>(n,false));
                            bool ok = true;
                            F0R(r,n) {
                                F0R(c,n) {
                                    if (g[p1][r][c]) {
                                        if (r+s1<0||r+s1>=n||c+s3<0||c+s3>=n) {ok = false;} // if it falls outside grid
                                        else {
                                            if (cand[r+s1][c+s3]) {ok = false;} // if another '#' is already there
                                            cand[r+s1][c+s3] = true;
                                        }
                                    }
                                    if (g[p2][r][c]) {
                                        if (r+s2<0||r+s2>=n||c+s4<0||c+s4>=n) {ok = false;}
                                        else {
                                            if (cand[r+s2][c+s4]) {ok = false;}
                                            cand[r+s2][c+s4] = true;
                                        }
                                    }
                                }
                            }
                            F0R(r,n) { // do they match...?
                                F0R(c,n) {
                                    if (g[0][r][c]!=cand[r][c]) {ok = false;}
                                }
                            }
                            if (ok) { // if everything's ok :)
                                cout << p1 << ' ' << p2 << '\n'; 
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
}