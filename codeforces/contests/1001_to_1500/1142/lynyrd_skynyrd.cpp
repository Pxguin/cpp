#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define v vector

const int MAX_N = 2e5, log2dist = 18;
int jump[MAX_N][log2dist];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, q; cin >> n >> m >> q;
    v<int> perm(n,-1);
    v<int> p(n), a(m);
    F0R(i,n) {cin >> p[i]; p[i]--;}
    F0R(i,m) {cin >> a[i]; a[i]--;}
    F0R(i,n) {perm[p[i]] = p[(i+1)%n];}

    memset(jump,-1,sizeof(jump));
    v<int> last(n,-1);
    for (int i=m-1;i>=0;i--) { // calculate first jump (next occurence of the next number)
        jump[i][0] = last[perm[a[i]]];
        last[a[i]] = i;
    }
    FOR(p1,1,log2dist) {
        F0R(i,m) { // compute binary lifting array
            if (jump[i][p1-1]!=-1) {jump[i][p1] = jump[jump[i][p1-1]][p1-1];}
        }
    }

    v<int> ans(m+1,INT_MAX);
    for (int i=m-1;i>=0;i--) {
        int to = i;
        F0R(p,log2dist) { // compute right endpoint
            if ((1<<p)&(n-1) && to!=-1) {
                to = jump[to][p];
            }
        } 
        if (to!=-1) {ans[i] = to;} // you have a range [i,to]
        ans[i] = min(ans[i],ans[i+1]);
    }
    F0R(i,q) { // see if any ranges are contained inside [l,r]
        int l, r; cin >> l >> r;
        cout << (ans[l-1]<=r-1);
    }
}