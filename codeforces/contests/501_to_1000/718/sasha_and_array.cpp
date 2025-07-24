#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9+7, N = 1e5, l2 = 32;

struct Matrix {
    ll a, b, c, d;
    Matrix() {a = b = c = d = 0;}
    Matrix(ll a, ll b, ll c, ll d) : a(a), b(b), c(c), d(d) {}
};
Matrix operator*(const Matrix& a, const Matrix& b) {
    Matrix c = Matrix(
        (a.a*b.a+a.b*b.c)%mod,
        (a.a*b.b+a.b*b.d)%mod,
        (a.c*b.a+a.d*b.c)%mod,
        (a.c*b.b+a.d*b.d)%mod
    );
    return c;
}
void operator*=(Matrix& a, const Matrix& b) {a = a*b;}
Matrix operator+(const Matrix& a, const Matrix& b) {
    Matrix c = Matrix(
        (a.a+b.a)%mod,
        (a.b+b.b)%mod,
        (a.c+b.c)%mod,
        (a.d+b.d)%mod
    );
    return c;
}

int a[N];
int n;
const Matrix base = Matrix(1,1,1,0), iden = Matrix(1,0,0,1);
Matrix pows[l2];

Matrix mexp(ll pow) {
    Matrix b = iden;
    for (int i=0;i<l2;i++) {
        if ((1LL<<i)&pow) {b *= pows[i];}
    } return b;
}

struct LazySegtree {
    Matrix sum[4*N], prod[4*N];
    LazySegtree() {
        for (int i=0;i<4*N;i++) {
            prod[i] = iden;
        }
    }
    void build(int cur=1, int l=0, int r=n-1) {
        if (l==r) {
            sum[cur] = mexp(a[l]);
        } else {
            int m = (l+r)/2;
            build(cur*2,l,m); build(cur*2+1,m+1,r);
            sum[cur] = sum[cur*2]+sum[cur*2+1];
        }
    }
    void push(int cur) {
        sum[cur*2] *= prod[cur];
        prod[cur*2] *= prod[cur];
        sum[cur*2+1] *= prod[cur];
        prod[cur*2+1] *= prod[cur];

        prod[cur] = iden;
    }
    void mul(int ql, int qr, const Matrix x, int cur=1, int l=0, int r=n-1) {
        if (l>r || ql>qr) {return;}

        if (ql==l && qr==r) {
            sum[cur] *= x;
            prod[cur] *= x;
        } else {
            push(cur);
            int m = (l+r)/2;
            mul(ql,min(m,qr),x,cur*2,l,m); mul(max(m+1,ql),qr,x,cur*2+1,m+1,r);
            sum[cur] = sum[cur*2]+sum[cur*2+1];
        }
    }
    ll add(int ql, int qr, int cur=1, int l=0, int r=n-1) {
        if (l>r || ql>qr) {return 0;}
    
        if (ql==l && qr==r) {
            return sum[cur].b;
        }
        push(cur);
        int m = (l+r)/2;
        return (add(ql,min(m,qr),cur*2,l,m)+add(max(m+1,ql),qr,cur*2+1,m+1,r))%mod;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int m; cin >> n >> m;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    pows[0] = base;
    for (int i=1;i<l2;i++) {
        pows[i] = pows[i-1]*pows[i-1];
    }
    LazySegtree segtree;
    segtree.build();
    while (m--) {
        int t, l, r; cin >> t >> l >> r;
        --l; --r;
        if (t==1) {
            int x; cin >> x;
            segtree.mul(l,r,mexp(x));
        } else {
            cout << segtree.add(l,r) << '\n';
        }
    }
}