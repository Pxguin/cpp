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

const int G = 5, M = G*26+1;
Matrix trsn(M,M), cur(M,1);
int dist[26][26];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i=0;i<26;i++) {
        for (int j=0;j<26;j++) {dist[i][j] = 1;}
    }
    for (int i=0;i<m;i++) {
        char a, b; int c; cin >> a >> b >> c;
        dist[a-'a'][b-'a'] = dist[b-'a'][a-'a'] = c;
    }
    for (int i=(G-1)*26;i<G*26;i++) {cur.mat[i][0] = 1;}
    for (int i=0;i<(G-1)*26;i++) {trsn.mat[i][i+26] = 1;}
    for (int i=0;i<26;i++) {
        for (int j=0;j<26;j++) {
            trsn.mat[(G-1)*26+j][(G-dist[i][j])*26+i] = 1;
            trsn.mat[M-1][(G-dist[i][j])*26+i]++;
        }
    }
    trsn.mat[M-1][M-1] = 1;
    cur.mat[M-1][0] = 26;

    for (int i=0;i<32;i++) {
        if ((1<<i)&n) {
            cur = trsn*cur;
        }
        trsn *= trsn;
    } cout << cur.mat[M-1][0] << '\n';
}