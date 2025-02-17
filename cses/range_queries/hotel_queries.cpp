#include <bits/stdc++.h>
using namespace std;

#define F0R(i, a) for (int i = 0; i < (a); i++)

const int MAX_N = 2e5;
int segtree[4*MAX_N+1] = {0}, a[MAX_N+1];
int n;

int build(int cur=1, int l=1, int r=n) {
    if (l==r) {segtree[cur] = a[l];}
    else {
        int m = (l+r)/2;
        segtree[cur] = max(build(cur*2,l,m),build(cur*2+1,m+1,r));
    }
    return segtree[cur];
}
void query(int val, int cur=1, int l=1, int r=n) {
    if (l==r) { // found it
        segtree[cur] -= val;
        cout << l << ' ';
    } else {
        int m = (l+r)/2;
        if (segtree[2*cur]>=val) {query(val,cur*2,l,m);} // move left or right
        else {query(val,cur*2+1,m+1,r);}
        segtree[cur] = max(segtree[cur*2],segtree[cur*2+1]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int m; cin >> n >> m;
    F0R(i,n) {cin >> a[i+1];}
    build();

    F0R(i,m) {
        int val; cin >> val;
        if (segtree[1]<val) {cout << 0 << ' ';}
        else {query(val);}
    }
}