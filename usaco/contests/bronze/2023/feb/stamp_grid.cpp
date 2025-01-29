#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

bool solve() {
    int n; cin >> n;
    char c;
    v<v<bool>> p(n,v<bool>(n));
    F0R(i,n) {
        F0R(j,n) {
            cin >> c;
            p[i][j] = (c=='*');
        }
    }
    int k; cin >> k;
    v<v<v<bool>>> s(4,v<v<bool>>(k,v<bool>(k)));
    v<v<bool>> ok(n,v<bool>(n,false));
    F0R(i,k) {
        F0R(j,k) {
            cin >> c;
            s[0][i][j] = (c=='*');
            s[1][j][k-i-1] = s[2][k-i-1][k-j-1] = s[3][k-j-1][i] = s[0][i][j];
        }
    }
    F0R(i,n-k+1) {
        F0R(j,n-k+1) {
            F0R(t,4) {
                int works = 1;
                F0R(i2,k) {
                    F0R(j2,k) {
                        if (s[t][i2][j2]) {works &= p[i2+i][j2+j];}
                    }
                }
                if (works) {
                    F0R(i2,k) {
                        F0R(j2,k) {
                            if (s[t][i2][j2]) {ok[i2+i][j2+j] = true;}
                        }
                    }
                }
            }
        }
    }
    F0R(i,n) {
        F0R(j,n) {
            if (p[i][j]&&!ok[i][j]) {return false;}
        }
    } return true;

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {cout << (solve() ? "YES" : "NO") << '\n';}
}