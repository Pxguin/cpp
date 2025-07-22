#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector

const int mod = 1e9+7;

struct Matrix {
    vec<vec<ll>> mat;
    Matrix(vec<vec<ll>> m) : mat(m) {}
    Matrix(int n, int m) {mat = vec<vec<ll>>(n,vec<ll>(m,0));}
};
Matrix operator*(const Matrix& a, const Matrix& b) {
    int n = a.mat.size(), m = b.mat[0].size(), l = a.mat[0].size();
    Matrix c(n,m);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            for (int k=0;k<l;k++) {
                c.mat[i][j] = (c.mat[i][j]+a.mat[i][k]*b.mat[k][j])%mod;
            }
        }
    } return c;
}
void operator*=(Matrix& a, const Matrix& b) {a = a*b;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, k; cin >> n >> m >> k;

    Matrix cur(n,1), trsn(n,n);
    cur.mat[0][0] = 1;

    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        trsn.mat[--b][--a]++;
    }

    for (int i=0;i<31;i++) {
        if ((1<<i)&k) {
            cur = trsn*cur;
        } trsn *= trsn;
    }
    cout << cur.mat[n-1][0] << '\n';
}