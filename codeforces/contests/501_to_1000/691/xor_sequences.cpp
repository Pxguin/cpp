#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector

const int mod = 1e9+7;

struct Matrix {
    vec<vec<ll>> mat;
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

    int n; ll k; cin >> n >> k;

    Matrix cur(n,n), trsn(n,n);
    for (int i=0;i<n;i++) {cur.mat[i][i] = 1;}

    vec<ll> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (__builtin_popcountll(a[i]^a[j])%3==0) {
                trsn.mat[i][j] = trsn.mat[j][i] = 1;
            }
        }
    }

    for (int i=0;i<63;i++) {
        if ((1LL<<i)&(k-1)) {
            cur *= trsn;
        } trsn *= trsn;
    }
    ll ans = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            ans = (ans+cur.mat[i][j])%mod;
        }
    }
    cout << ans << '\n';
}