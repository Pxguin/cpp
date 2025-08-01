#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define chmin(a, b) a = min(a,b)
#define vec vector

struct Matrix {
    vec<vec<ll>> mat;
    Matrix(vec<vec<ll>> m) : mat(m) {}
    Matrix(int n, int m) {mat = vec<vec<ll>>(n,vec<ll>(m,2e18));}
};
Matrix operator*(const Matrix& a, const Matrix& b) {
    int n = a.mat.size(), m = b.mat[0].size(), l = a.mat[0].size();
    Matrix c(n,m);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            for (int k=0;k<l;k++) {
                chmin(c.mat[i][j],a.mat[i][k]+b.mat[k][j]);
            }
        }
    } return c;
}
void operator*=(Matrix& a, const Matrix& b) {a = a*b;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, k; cin >> n >> m >> k;

    Matrix cur(n,1), trsn(n,n);
    cur.mat[0][0] = 0;

    for (int i=0;i<m;i++) {
        int a, b, c; cin >> a >> b >> c;
        --b; --a;
        chmin(trsn.mat[b][a],(ll)c);
    }

    for (int i=0;i<31;i++) {
        if ((1<<i)&k) {
            cur = trsn*cur;
        } trsn *= trsn;
    }
    cout << (cur.mat[n-1][0]==2e18 ? -1 : (long long)cur.mat[n-1][0]) << '\n';
}