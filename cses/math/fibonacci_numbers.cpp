#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9+7, N = 2, l2 = 64;
using Mat = array<array<ll,N>,N>;

Mat operator*(const Mat& a, const Mat& b) {
    Mat c;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            c[i][j] = 0;
            for (int k=0;k<N;k++) {
                c[i][j] = (c[i][j]+a[i][k]*b[k][j])%mod;
            }
        }
    } return c;
}
void operator*=(Mat& a, const Mat& b) {a = a*b;}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    ll n; cin >> n;

    Mat trsn = {{{1,1},{1,0}}}, cur = {{{1,0},{0,1}}};
    for (int i=0;i<l2;i++,trsn*=trsn) {
        if ((1LL<<i)&n) {
            cur *= trsn;
        }
    } cout << cur[0][1] << '\n';
}