#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector

const int mod = 1e9;

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

void solve() {
    int k; cin >> k;
    Matrix a(k,1);
    Matrix c(k,k);
    for (int i=0;i<k;i++) {cin >> a.mat[i][0];}
    for (int i=0;i<k;i++) {
        if (i!=k-1) {c.mat[i][i+1] = 1;}
        cin >> c.mat[k-1][k-i-1];
    }
    int n; cin >> n;
    for (int i=0;i<31;i++,c*=c) {
        if ((1<<i)&(n-1)) {
            a = c*a;
        }
    }
    cout << a.mat[0][0] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while (t--) {solve();}
}