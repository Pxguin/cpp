#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector

const int mod = 1e9;

struct Matrix {
    vec<vec<ll>> mat;
    Matrix(vec<vec<ll>> m) : mat(m) {}
    Matrix(int n, int m) {mat = vec<vec<ll>>(n,vec<ll>(m,0));}
    void transform() {
        for (int i=0;i<mat.size();i++) {
            for (int j=i+1;j<mat.size();j++) {
                swap(mat[i][j],mat[j][i]);
            }
        }
    };
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

Matrix trsn = Matrix({
    {2,1,1,1,1,1},
    {0,0,0,1,0,1},
    {1,0,0,0,0,0},
    {2,1,1,1,1,1},
    {1,0,0,0,0,0},
    {2,1,1,1,1,1}
});
Matrix base = Matrix({
    {1},{0},{1},{0},{1},{0}
});
Matrix last = Matrix({
    {1,2,0,1,0,1}
});

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    freopen("points.in","r",stdin);
    freopen("points.out","w",stdout);

    int n; cin >> n;

    if (n==1) {cout << 0 << '\n';}
    else {
        trsn.transform();
        for (int i=0;i<32;i++) {
            if ((1<<i)&(n-2)) {
                base = trsn*base;
            }
            trsn *= trsn;
        } base = last*base;
        cout << base.mat[0][0] << '\n';
    }
}
/*
case 1: 1,3; 2 is chosen
case 2: 1,3; 2 is not chosen
case 3: 1,2; 3 is not chosen
case 4: 1,2; 3 is chosen
case 5: 2,3; 1 is not chosen
case 6: 2,3; 1 is chosen

transition:
1->3,5,1,1,3,6,2
2->4,6
3->1
4->1,1,2,3,4,5,6
5->1
6 = 4

base case:
1,3,5

to end:
1,2,2,4,6
*/